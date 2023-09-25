// Fill out your copyright notice in the Description page of Project Settings.


#include "C_PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Components/InputComponent.h"
#include "C_AbilitySystemComponent_Player.h"
#include "C_GameplayAbility.h"
#include "C_AttributeSet.h"
#include "C_Enums.h"
#include <GameplayEffectTypes.h>

// Sets default values
AC_PlayerCharacter::AC_PlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//camera
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	Camera->SetupAttachment(SpringArm);

	//Gas
	AbilitySystemComponent = CreateDefaultSubobject<UC_AbilitySystemComponent_Player>(TEXT("AbilitySystem"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	Attribute = CreateDefaultSubobject<UC_AttributeSet>(TEXT("AttributeSetBase"));

}

// Called when the game starts or when spawned
void AC_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	//gas
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	//AbilitySystemComponent->InitializeAbilitiesAndEffects();

	InitializeAttributes();
	GiveAbilities();

	//set EnhancedInput
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		if (InputSubsystem)
		{
			InputSubsystem->AddMappingContext(PlayerControls, 0);


			//gas binds to abilities
			if (AbilitySystemComponent)
			{
				const FGameplayAbilityInputBinds binds("Confirm", "Cancel", "E_AbilityInputID", static_cast<int32>(E_AbilityInputID::Confirm), static_cast<int32>(E_AbilityInputID::Cancel)); //19.25
				AbilitySystemComponent->BindAbilityActivationToInputComponent(InputComponent, binds);
			}
		}
	}
}


void AC_PlayerCharacter::MoveAround(const FInputActionValue& Value)
{
	const FVector2D MovementAixs = Value.Get<FVector2D>();
	if (GetController())
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

		//UE_LOG(LogTemp, Warning, TEXT("move Forward Triggered"));

		//strifing but with issues on pitch rotation
		const FVector ForwardDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(ForwardDir, MovementAixs.Y);
		const FVector RightDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(RightDir, MovementAixs.X);

	}

}

void AC_PlayerCharacter::InitializeAttributes()
{
	if (AbilitySystemComponent && DefaultAttributeEffect)
	{
		FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
		EffectContext.AddSourceObject(this);

		FGameplayEffectSpecHandle specHandle = AbilitySystemComponent->MakeOutgoingSpec(DefaultAttributeEffect, 1, EffectContext);
		if (specHandle.IsValid())
		{
			FActiveGameplayEffectHandle GEHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*specHandle.Data.Get());
		}
	}
}

void AC_PlayerCharacter::GiveAbilities()
{
	if (AbilitySystemComponent)
	{
		for (TSubclassOf <class UC_GameplayAbility>& StartupAbility : DefaultAbilities)
		{
			AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(StartupAbility, 1, static_cast<int32>(StartupAbility.GetDefaultObject()->AblilityInputID), this));
		}
	}
}



// Called every frame
void AC_PlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AC_PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInput->BindAction(Move, ETriggerEvent::Triggered, this, &AC_PlayerCharacter::MoveAround);
		//EnhancedInputComp->BindAction(Look, ETriggerEvent::Triggered, this, &APlayerV1::LookAround);
	}
}


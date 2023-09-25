// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "C_AbilitySystemComponent_Player.h"
#include "AbilitySystemInterface.h"
#include <GameplayEffectTypes.h>
#include "C_PlayerCharacter.generated.h"

class UInputMappingContext;
class UInputAction;
class USpringArmComponent;
class UCameraComponent;
class UC_GameplayAbility;
class UC_AbilitySystemComponent_Player;
class UC_AttributeSet;

UCLASS()
class PROJECT_SPACESTATION_API AC_PlayerCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AC_PlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Camera")
		TObjectPtr<USpringArmComponent> SpringArm;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Camera")
		TObjectPtr <UCameraComponent> Camera;

	//GAS Defaults
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GAS")
		TSubclassOf <UGameplayEffect> DefaultAttributeEffect;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GAS")
		TArray<TSubclassOf <class UC_GameplayAbility>> DefaultAbilities;

	//gas
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "GAS")
		TObjectPtr <UC_AbilitySystemComponent_Player> AbilitySystemComponent;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "GAS")
		TObjectPtr <UC_AttributeSet> Attribute;
	 
	

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Abilities")
	//	TArray<TSubclassOf<UC_GameplayAbility>> GamePlayAvilities;
	////UC_AttributeSet

	//Input
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr <UInputMappingContext> PlayerControls;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		TObjectPtr <UInputAction> Move;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		TObjectPtr <UInputAction> Interact;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		TObjectPtr <UInputAction> Skill1;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		TObjectPtr <UInputAction> Skill2;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		TObjectPtr <UInputAction> Skill3;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		TObjectPtr <UInputAction> Skill4;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		TObjectPtr <UInputAction> Skill5;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		TObjectPtr <UInputAction> Skill6;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		TObjectPtr <UInputAction> Skill7;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		TObjectPtr <UInputAction> Skill8;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		TObjectPtr <UInputAction> Skill9;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	void MoveAround(const FInputActionValue& Value);

	FORCEINLINE virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override {
		return AbilitySystemComponent.Get();
	}

	virtual void InitializeAttributes();
	virtual void GiveAbilities();

	
};

 
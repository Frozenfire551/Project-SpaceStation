// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AbilitySystemComponent.h"
#include "C_Enums.h"
#include "C_GameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_SPACESTATION_API UC_GameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	UC_GameplayAbility();

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability")
		E_AbilityInputID AblilityInputID = E_AbilityInputID::None;

};

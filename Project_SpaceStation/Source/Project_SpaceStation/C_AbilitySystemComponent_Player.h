// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AbilitySystemComponent.h"
#include "CoreMinimal.h"
#include "C_AbilitySystemComponent_Player.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_SPACESTATION_API UC_AbilitySystemComponent_Player : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:
	/*UPROPERTY(EditDefaultOnly, BlueprintReadOnly, Category = "Abilities")
		TArray<TSubclassOf<>> DefaultAbilities;

	UPROPERTY(EditDefaultOnly, BlueprintReadOnly, Category = "Abilities")
		TArray<TSubclassOf<>> DefaultEffects;*/

	UFUNCTION()
		void InitializeAbilitiesAndEffects();

};

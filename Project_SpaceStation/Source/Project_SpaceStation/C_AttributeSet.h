// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "C_AttributeSet.generated.h"

//uses macros from AttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class PROJECT_SPACESTATION_API UC_AttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	

	public:

		UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Health)
			FGameplayAttributeData Health;
		ATTRIBUTE_ACCESSORS(UC_AttributeSet, Health)

		UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_MaxHealth)
			FGameplayAttributeData MaxHealth;
		ATTRIBUTE_ACCESSORS(UC_AttributeSet, MaxHealth)

		
		UFUNCTION()
		virtual void OnRep_Health(const FGameplayAttributeData& OldHealthMax);
		UFUNCTION()
		virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldHealthMax);
	
		virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
		//get hp and max hp
		
	
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "C_AttributeSet.h"
#include "Net/UnrealNetwork.h"


void UC_AttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UC_AttributeSet, Health, OldHealth);
}
void UC_AttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldHealthMax)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UC_AttributeSet, MaxHealth, OldHealthMax);
}

void UC_AttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UC_AttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UC_AttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
}






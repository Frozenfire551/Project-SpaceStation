// Fill out your copyright notice in the Description page of Project Settings.


#include "C_AttributeSet.h"

UC_AttributeSet::UC_AttributeSet() 
{

}

void UC_AttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifeTimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifeTimeProps);

	//DOREPLIFETIME_CONDITION_NOTIFY(UC_AttributeSet, Health, COND_None, REPNOTIFY_Always);
}

void UC_AttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UC_AttributeSet, Health, OldHealth);
}

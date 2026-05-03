// Project Made by Akhil Mathew Mathew @TheRAVAGE as a part of UDEMY course : Unreal Engine 5 C++ Advanced Action RPG by Vince Petrelli


#include "WarriorFunctionLibrary.h"

#include "Warrior/AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GenericTeamAgentInterface.h"
#include "Interfaces/PawnCombatInterface.h"
#include "WarriorTypes/WarriorEnumTypes.h"

UWarriorAbilitySystemComponent* UWarriorFunctionLibrary::NativeGetWarriorASCFromActor(AActor* InActor)
{
	checkf(InActor, TEXT("InActor passed to NativeGetWarriorASCFromActor was null!"));
	return CastChecked<UWarriorAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

bool UWarriorFunctionLibrary::NativeDoesActorHaveTag(AActor* InActor, FGameplayTag InTagToCheck)
{
	UWarriorAbilitySystemComponent* ASC = NativeGetWarriorASCFromActor(InActor);
	return ASC->HasMatchingGameplayTag(InTagToCheck);
}

UPawnCombatComponent* UWarriorFunctionLibrary::NativeGetPawnCombatComponentFromActor(AActor* InActor)
{
	checkf(InActor, TEXT("InActor passed to NativeGetPawnCombatComponentFromActor was null!"));
	
	if (IPawnCombatInterface* CombatInterface = Cast<IPawnCombatInterface>(InActor))
	{
		return CombatInterface->GetPawnCombatComponent();
	}
	return nullptr;
}

void UWarriorFunctionLibrary::AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag InTagToAdd)
{
	UWarriorAbilitySystemComponent* ASC = NativeGetWarriorASCFromActor(InActor);
	if (!ASC->HasMatchingGameplayTag(InTagToAdd))
	{
		ASC->AddLooseGameplayTag(InTagToAdd);
	}
}

void UWarriorFunctionLibrary::RemoveGameplayTagToActorIfFound(AActor* InActor, FGameplayTag InTagToRemove)
{
	UWarriorAbilitySystemComponent* ASC = NativeGetWarriorASCFromActor(InActor);
	if (ASC->HasMatchingGameplayTag(InTagToRemove))
	{
		ASC->RemoveLooseGameplayTag(InTagToRemove);
	}
}

void UWarriorFunctionLibrary::BP_DoesActorHaveTag(AActor* InActor, FGameplayTag InTagToCheck,
	EWarriorConfirmType& OutConfirmType)
{
	OutConfirmType = NativeDoesActorHaveTag(InActor, InTagToCheck) ? EWarriorConfirmType::Yes : EWarriorConfirmType::No;
}

UPawnCombatComponent* UWarriorFunctionLibrary::BP_GetPawnCombatComponentFromActor(AActor* InActor,
	EWarriorValidType& OutValidType)
{
	UPawnCombatComponent* CombatComponent = NativeGetPawnCombatComponentFromActor(InActor);
	OutValidType = CombatComponent ? EWarriorValidType::Valid : EWarriorValidType::Invalid;
	return CombatComponent;
}

bool UWarriorFunctionLibrary::IsTargetHostile(APawn* QueryPawn, APawn* TargetPawn)
{
	checkf(QueryPawn && TargetPawn, TEXT("InActor passed to IsTargetHostile was null!"));
	
	IGenericTeamAgentInterface* QueryTeamInterface = Cast<IGenericTeamAgentInterface>(QueryPawn->GetController());
	IGenericTeamAgentInterface* TargetTeamInterface = Cast<IGenericTeamAgentInterface>(TargetPawn->GetController());
	
	if (QueryTeamInterface && TargetTeamInterface)
	{
		return QueryTeamInterface->GetGenericTeamId() != TargetTeamInterface->GetGenericTeamId();
	}
	return false;
}

float UWarriorFunctionLibrary::GetScalableFloatValueAtLevel(FScalableFloat InScalableFloat, int32 InLevel)
{
	return InScalableFloat.GetValueAtLevel(InLevel);
}

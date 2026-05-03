// Project Made by Akhil Mathew Mathew @TheRAVAGE as a part of UDEMY course : Unreal Engine 5 C++ Advanced Action RPG by Vince Petrelli


#include "Warrior/Components/Combat/EnemyCombatComponent.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "Warrior/DebugHelper.h"
#include "Warrior/WarriorGameplayTags.h"

void UEnemyCombatComponent::OnHitTargetAActor(AActor* HitActor)
{
	if (OverlappedActors.Contains(HitActor))
	{
		return;
	}
	OverlappedActors.AddUnique(HitActor);
	
	//TODO: Implement block check
	bool bIsValidBlock = false;
	
	const bool bIsPlayerBlocking = false;
	const bool bIsAttackUnblockable = false;
	
	if (bIsPlayerBlocking && !bIsAttackUnblockable)
	{
		//TODO: Check if the block is valid
	}
	FGameplayEventData EventData;
	EventData.Instigator = GetOwningPawn<APawn>();
	EventData.Target = HitActor;
	
	if (bIsValidBlock)
	{
		//TODO: Handle Successful Block
	}
	else
	{
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
			GetOwningPawn<APawn>(),
			WarriorGameplayTags::Shared_Event_MeleeHit,
			EventData
			);
	}
}

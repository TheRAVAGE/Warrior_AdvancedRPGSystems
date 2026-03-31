// Project Made by Akhil Mathew Mathew @TheRAVAGE as a part of UDEMY course : Unreal Engine 5 C++ Advanced Action RPG by Vince Petrelli


#include "Warrior/Components/Combat/HeroCombatComponent.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Warrior/Items/Weapons/WarriorHeroWeapon.h"
#include "Warrior/DebugHelper.h"
#include "Warrior/WarriorGameplayTags.h"

AWarriorHeroWeapon* UHeroCombatComponent::GetCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	return Cast<AWarriorHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}

AWarriorHeroWeapon* UHeroCombatComponent::GetHeroCurrentEquippedWeapon() const
{
	return Cast<AWarriorHeroWeapon>(GetCharacterCurrentEquippedWeapon());
}

float UHeroCombatComponent::GetHeroCurrentEquipWeaponDamageAtLevel(float InLevel) const
{
	return GetHeroCurrentEquippedWeapon()->HeroWeaponData.WeaponBaseDamage.GetValueAtLevel(InLevel);
}

void UHeroCombatComponent::OnHitTargetAActor(AActor* HitActor)
{
	// Debug::PrintMessage(GetOwningPawn<APawn>()->GetActorNameOrLabel() + TEXT("Hit Actor ") + HitActor->GetActorNameOrLabel(), FColor::Green, -1,true);
	if (OverlappedActors.Contains(HitActor))
	{
		return;
	}
	OverlappedActors.AddUnique(HitActor);
	FGameplayEventData Data;
	Data.Instigator = GetOwningPawn<APawn>();
	Data.Target = HitActor;
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
		GetOwningPawn<APawn>(), 
		WarriorGameplayTags::Shared_Event_MeleeHit, 
		Data
		);
	
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
		GetOwningPawn<APawn>(), 
		WarriorGameplayTags::Player_Event_HitPause, 
		FGameplayEventData()
		);
}

void UHeroCombatComponent::OnWeaponPulledFromTargetAActor(AActor* InteractedActor)
{
	// Debug::PrintMessage(GetOwningPawn<APawn>()->GetActorNameOrLabel() + TEXT("Pulled weapon From Actor ") + InteractedActor->GetActorNameOrLabel(), FColor::Red, -1,true);
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
		GetOwningPawn<APawn>(), 
		WarriorGameplayTags::Player_Event_HitPause, 
		FGameplayEventData()
		);
}

// Project Made by Akhil Mathew Mathew @TheRAVAGE as a part of UDEMY course : Unreal Engine 5 C++ Advanced Action RPG by Vince Petrelli


#include "Warrior/AbilitySystem/WarriorAbilitySystemComponent.h"

#include "Warrior/AbilitySystem/Abilities/WarriorHeroGameplayAbility.h"
#include "GameplayTagContainer.h"
#include "Warrior/WarriorTypes/WarriorStructTypes.h"

void UWarriorAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
	if (!InInputTag.IsValid()) { return; }
	
	for (const FGameplayAbilitySpec& Spec: GetActivatableAbilities())
	{
		if (!Spec.GetDynamicSpecSourceTags().HasTagExact(InInputTag)) { continue; }
		TryActivateAbility(Spec.Handle);
	}
}

void UWarriorAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{
}

void UWarriorAbilitySystemComponent::GrantHeroWeaponABilities(
	const TArray<FWarriorHeroAbilitySet>& InDefaultWeaponAbilities, int32 ApplyLevel,
	TArray<FGameplayAbilitySpecHandle>& OutGrantedSpecHandles)
{
	if (InDefaultWeaponAbilities.IsEmpty()) { return; }
	
	for (const FWarriorHeroAbilitySet& AbilitySet: InDefaultWeaponAbilities)
	{
		if (!AbilitySet.IsValid()) { continue; }
		
		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.GetDynamicSpecSourceTags().AddTag(AbilitySet.InputTag);
		
		OutGrantedSpecHandles.AddUnique(GiveAbility(AbilitySpec));
		
	}
}

void UWarriorAbilitySystemComponent::RemoveGrantedHeroWeaponAbilities(
	TArray<FGameplayAbilitySpecHandle>& InSpecHandlesToRemove)
{
	if (InSpecHandlesToRemove.IsEmpty()) { return; }
	
	for (const FGameplayAbilitySpecHandle& SpecHandle: InSpecHandlesToRemove)
	{
		if (SpecHandle.IsValid())
		{
			ClearAbility(SpecHandle);
		}
	}
	InSpecHandlesToRemove.Empty();
}

bool UWarriorAbilitySystemComponent::TryActivateAbilityByTag(FGameplayTag InAbilityTagToActivate)
{
	checkf(InAbilityTagToActivate.IsValid(), TEXT("Invalid Tag passed to activate"));
	
	TArray<FGameplayAbilitySpec*> FoundAbilities;
	GetActivatableGameplayAbilitySpecsByAllMatchingTags(InAbilityTagToActivate.GetSingleTagContainer(), FoundAbilities);
	
	if (!FoundAbilities.IsEmpty())
	{
		const int32 RandomAbilityIndex = FMath::RandRange(0, FoundAbilities.Num() - 1);
		FGameplayAbilitySpec* SpecToActivate = FoundAbilities[RandomAbilityIndex];
		
		checkf(SpecToActivate, TEXT("Invalid Tag passed to activate"));
		if (!SpecToActivate->IsActive())
		{
			return TryActivateAbility(SpecToActivate->Handle);
		}
	}
	
	return false;
}

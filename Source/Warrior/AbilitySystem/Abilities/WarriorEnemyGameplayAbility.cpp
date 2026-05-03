// Project Made by Akhil Mathew Mathew @TheRAVAGE as a part of UDEMY course : Unreal Engine 5 C++ Advanced Action RPG by Vince Petrelli


#include "Warrior/AbilitySystem/Abilities/WarriorEnemyGameplayAbility.h"

#include "Warrior/WarriorGameplayTags.h"
#include "Warrior/AbilitySystem/WarriorAbilitySystemComponent.h"
#include "Warrior/Characters/WarriorEnemyCharacter.h"

AWarriorEnemyCharacter* UWarriorEnemyGameplayAbility::GetEnemyCharacterFromActorInfo()
{
	if (!CachedWarriorEnemyCharacter.IsValid())
	{
		CachedWarriorEnemyCharacter = Cast<AWarriorEnemyCharacter>(CurrentActorInfo->AvatarActor);
	}
	return CachedWarriorEnemyCharacter.IsValid() ? CachedWarriorEnemyCharacter.Get() : nullptr;
}

UEnemyCombatComponent* UWarriorEnemyGameplayAbility::GetEnemyCombatComponentFromActorInfo()
{
	return GetEnemyCharacterFromActorInfo()->GetEnemyCombatComponent();
}

FGameplayEffectSpecHandle UWarriorEnemyGameplayAbility::MakeEnemyDamageEffectSpecHandle(
	TSubclassOf<UGameplayEffect> EffectClass, const FScalableFloat &InDamageScalableFloat)
{
	checkf(EffectClass, TEXT("EffectClass is null!"));
	
	FGameplayEffectContextHandle ContextHandle = GetWarriorAbilitySystemComponentFromActorInfo()->MakeEffectContext();
	ContextHandle.SetAbility(this);
	ContextHandle.AddSourceObject(GetAvatarActorFromActorInfo());
	ContextHandle.AddInstigator(GetAvatarActorFromActorInfo(), GetAvatarActorFromActorInfo());
	
	FGameplayEffectSpecHandle EffectSpecHandle = GetWarriorAbilitySystemComponentFromActorInfo()->MakeOutgoingSpec(
			EffectClass,
			GetAbilityLevel(),
			ContextHandle
		);
	EffectSpecHandle.Data->SetSetByCallerMagnitude(
			WarriorGameplayTags::Shared_SetByCaller_BaseDamage,
			InDamageScalableFloat.GetValueAtLevel(GetAbilityLevel())
		);
	return EffectSpecHandle;
}

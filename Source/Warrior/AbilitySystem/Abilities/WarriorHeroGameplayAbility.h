// Project Made by Akhil Mathew Mathew @TheRAVAGE as a part of UDEMY course : Unreal Engine 5 C++ Advanced Action RPG by Vince Petrelli

#pragma once

#include "CoreMinimal.h"
#include "Warrior/AbilitySystem/Abilities/WarriorGameplayAbility.h"
#include "WarriorHeroGameplayAbility.generated.h"

class UHeroCombatComponent;
class AWarriorHeroController;
class AWarriorHeroCharacter;
/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorHeroGameplayAbility : public UWarriorGameplayAbility
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category = "Warrior | Ability")
	AWarriorHeroCharacter* GetHeroCharacterFromActorInfo();
	
	UFUNCTION(BlueprintPure, Category = "Warrior | Ability")
	AWarriorHeroController* GetHeroControllerFromActorInfo();
	
	UFUNCTION(BlueprintPure, Category = "Warrior | Ability")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();
	
	UFUNCTION(BlueprintPure, Category = "Warrior | Ability")
	FGameplayEffectSpecHandle MakeHeroDamageEffectSpecHandle(
		TSubclassOf< UGameplayEffect > EffectClass, 
		float InWeaponBaseDamage, 
		FGameplayTag InCurrentAttackTypeTag,
		int32 InCurrentComboCount
		);
	
private:
	TWeakObjectPtr<AWarriorHeroController> CachedHeroController;
	TWeakObjectPtr<AWarriorHeroCharacter> CachedHeroCharacter;
};

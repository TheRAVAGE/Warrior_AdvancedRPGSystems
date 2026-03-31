// Project Made by Akhil Mathew Mathew @TheRAVAGE as a part of UDEMY course : Unreal Engine 5 C++ Advanced Action RPG by Vince Petrelli

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Warrior/WarriorTypes/WarriorEnumTypes.h"
#include "WarriorGameplayAbility.generated.h"

class UWarriorAbilitySystemComponent;
class UPawnCombatComponent;
/**
 * 
 */
UENUM(BlueprintType)
enum EWarriorAbilityActivationPolicy : uint8
{
	OnTriggered,
	OnGiven
};

UCLASS()
class WARRIOR_API UWarriorGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
protected:
	//~ Begin UGameplayAbility Interface
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	//~ End UGameplayAbility Interface
	
	UPROPERTY(EditDefaultsOnly, Category = "Warrior | Ability")
	TEnumAsByte<EWarriorAbilityActivationPolicy> ActivationPolicy = EWarriorAbilityActivationPolicy::OnTriggered;
	
	UFUNCTION(BlueprintPure, Category = "Warrior | Ability")
	UPawnCombatComponent* GetCombatComponentFromActorInfo() const;
	
	UFUNCTION(BlueprintPure, Category = "Warrior | Ability")
	UWarriorAbilitySystemComponent* GetWarriorAbilitySystemComponentFromActorInfo() const;
	
	FActiveGameplayEffectHandle NativeApplyEffectSpecHandleToTarget(AActor* TargetActor, const FGameplayEffectSpecHandle& EffectSpecHandle);
	
	UFUNCTION(BlueprintCallable, Category = "Warrior | Ability", meta = (DisplayName="Apply Effect Spec Handle To Target" , ExpandEnumAsExecs = "OutSuccessType"))
	FActiveGameplayEffectHandle BP_ApplyEffectSpecHandleToTarget(
		AActor* TargetActor, 
		const FGameplayEffectSpecHandle& EffectSpecHandle, 
		EWarriorSuccessType &OutSuccessType
		);
	
	
};

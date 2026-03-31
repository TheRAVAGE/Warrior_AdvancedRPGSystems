// Project Made by Akhil Mathew Mathew @TheRAVAGE as a part of UDEMY course : Unreal Engine 5 C++ Advanced Action RPG by Vince Petrelli

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Warrior/Components/PawnExtensionComponentBase.h"
#include "PawnCombatComponent.generated.h"

class AWarriorWeaponBase;

UENUM(BlueprintType)
enum class EToggleDamageType : uint8
{
	CurrentWeapon,
	LeftHand,
	RightHand,
};
/**
 * 
 */
UCLASS()
class WARRIOR_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category="Warrior | Combat")
	void RegisterSpawnedWeapon( FGameplayTag InWeaponTagToRegister, AWarriorWeaponBase* InWeaponToRegister, bool bResisterAsEquippedWeapon = false );
	
	UFUNCTION(BlueprintCallable, Category="Warrior | Combat")
	AWarriorWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;
	
	UPROPERTY(BlueprintReadWrite, Category="Warrior | Combat")
	FGameplayTag CurrentEquippedWeaponTag;
	
	UFUNCTION(BlueprintCallable, Category="Warrior | Combat")
	AWarriorWeaponBase* GetCharacterCurrentEquippedWeapon() const;
	
	UFUNCTION(BlueprintCallable, Category="Warrior | Combat")
	void ToggleWeapongCollision(bool bShouldEnable,EToggleDamageType ToggleDamageType);
	
	virtual void OnHitTargetAActor(AActor* HitActor);
	virtual void OnWeaponPulledFromTargetAActor(AActor* InteractedActor);
	
protected:
	TArray<AActor*> OverlappedActors;
private:
	UPROPERTY(VisibleAnywhere, Category="Warrior | Combat")
	TMap<FGameplayTag, AWarriorWeaponBase*> CharacterCarriedWeaponsMap;
};

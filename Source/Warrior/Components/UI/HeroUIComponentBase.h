// Project Made by Akhil Mathew Mathew @TheRAVAGE as a part of UDEMY course : Unreal Engine 5 C++ Advanced Action RPG by Vince Petrelli

#pragma once

#include "CoreMinimal.h"
#include "Warrior/Components/UI/PawnUIComponentBase.h"
#include "HeroUIComponentBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeaponChangedDelegate, TSoftObjectPtr<UTexture2D>, NewWeaponIconTexture);
/**
 * 
 */
UCLASS()
class WARRIOR_API UHeroUIComponentBase : public UPawnUIComponentBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnPercentChanged OnCurrentRageChanged;
	
	UPROPERTY(BlueprintCallable,BlueprintAssignable, Category = "Events")
	FOnWeaponChangedDelegate OnWeaponChanged;
};

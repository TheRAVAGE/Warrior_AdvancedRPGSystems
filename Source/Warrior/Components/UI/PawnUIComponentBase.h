// Project Made by Akhil Mathew Mathew @TheRAVAGE as a part of UDEMY course : Unreal Engine 5 C++ Advanced Action RPG by Vince Petrelli

#pragma once

#include "CoreMinimal.h"
#include "Warrior/Components/PawnExtensionComponentBase.h"
#include "PawnUIComponentBase.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPercentChanged, float, NewPercent);
/**
 * 
 */
UCLASS()
class WARRIOR_API UPawnUIComponentBase : public UPawnExtensionComponentBase
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnPercentChanged OnCurrentHealthChanged;
	
};

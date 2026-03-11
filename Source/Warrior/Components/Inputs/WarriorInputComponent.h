// Project Made by Akhil Mathew Mathew @TheRAVAGE as a part of UDEMY course : Unreal Engine 5 C++ Advanced Action RPG by Vince Petrelli

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "Warrior/DataAssets/Inputs/DataAsset_InputConfig.h"
#include "WarriorInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
	
public:
	template<class UserObject, typename CallbackFunc>
	void BindNativeInputAction(
		UDataAsset_InputConfig* InInputConfig, /* DataAsset */
		const FGameplayTag& InInputTag, /* InputTag */
		ETriggerEvent TriggerEvent, /* TriggerEvent */
		UserObject* ContextObject, /* Context */
		CallbackFunc Func /* Function to call */
		) 
	{
		checkf(InInputConfig, TEXT("InputConfig is nullptr"));
	
		if (UInputAction* FoundAction = InInputConfig->FindNativeInputActionByTag(InInputTag)) 
			//Looks through the data asset for Input Actions matching the tags
		{
			BindAction(FoundAction, TriggerEvent, ContextObject, Func);
		}
	}
	
};



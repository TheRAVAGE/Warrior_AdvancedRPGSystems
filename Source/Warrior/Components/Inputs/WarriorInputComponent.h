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
	
	template<class UserObject, typename CallbackFunc>
	void BindAbilityInputAction(
		UDataAsset_InputConfig* InInputConfig, /* DataAsset */
		UserObject* ContextObject, /* Context */
		CallbackFunc InputPressedFunc, /* Function to call on Started */
		CallbackFunc InputReleasedFunc /* Function to call on Completed */
		)
	{
		checkf(InInputConfig, TEXT("InputConfig is nullptr"));
		for (const FWarriorInputActionConfig& AbilityInputConfig : InInputConfig->AbilityInputActions)
		{
			if (!AbilityInputConfig.IsValid()) {continue;}
			
			BindAction(AbilityInputConfig.InputAction, ETriggerEvent::Started, ContextObject, InputPressedFunc, AbilityInputConfig.InputTag);
			BindAction(AbilityInputConfig.InputAction, ETriggerEvent::Completed, ContextObject, InputReleasedFunc, AbilityInputConfig.InputTag);
		}
	}
	
};



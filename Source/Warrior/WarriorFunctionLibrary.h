// Project Made by Akhil Mathew Mathew @TheRAVAGE as a part of UDEMY course : Unreal Engine 5 C++ Advanced Action RPG by Vince Petrelli

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WarriorFunctionLibrary.generated.h"

class UWarriorAbilitySystemComponent;
/**
 * 
 */
UENUM() 
enum class EWarriorConfirmType : uint8
{
	Yes,
	No
};
UCLASS()
class WARRIOR_API UWarriorFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	static UWarriorAbilitySystemComponent* NativeGetWarriorASCFromActor(AActor* InActor);
	
	static bool NativeDoesActorHaveTag(AActor* InActor, FGameplayTag InTagToCheck);
	
	UFUNCTION(BlueprintCallable, Category = "Warrior | FunctionLibrary")
	static void AddGameplayTagToActorIfNone (AActor* InActor, FGameplayTag InTagToAdd);
	
	UFUNCTION(BlueprintCallable, Category = "Warrior | FunctionLibrary")
	static void RemoveGameplayTagToActorIfFound (AActor* InActor, FGameplayTag InTagToRemove);
	
	UFUNCTION(BlueprintCallable, Category = "Warrior | FunctionLibrary", meta = (DisplayName = "Does Actor Have Tag", ExpandEnumAsExecs = "OutConfirmType"))
	static void BP_DoesActorHaveTag (AActor* InActor, FGameplayTag InTagToCheck, EWarriorConfirmType& OutConfirmType);
};

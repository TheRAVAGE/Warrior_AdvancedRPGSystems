// Project Made by Akhil Mathew Mathew @TheRAVAGE as a part of UDEMY course : Unreal Engine 5 C++ Advanced Action RPG by Vince Petrelli

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WarriorTypes/WarriorEnumTypes.h"
#include "WarriorFunctionLibrary.generated.h"

class UPawnCombatComponent;
class UWarriorAbilitySystemComponent;
struct FScalableFloat;
/**
 * 
 */

UCLASS()
class WARRIOR_API UWarriorFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	static UWarriorAbilitySystemComponent* NativeGetWarriorASCFromActor(AActor* InActor);
	
	static bool NativeDoesActorHaveTag(AActor* InActor, FGameplayTag InTagToCheck);
	static UPawnCombatComponent* NativeGetPawnCombatComponentFromActor(AActor* InActor);
	
	UFUNCTION(BlueprintCallable, Category = "Warrior | FunctionLibrary")
	static void AddGameplayTagToActorIfNone (AActor* InActor, FGameplayTag InTagToAdd);
	
	UFUNCTION(BlueprintCallable, Category = "Warrior | FunctionLibrary")
	static void RemoveGameplayTagToActorIfFound (AActor* InActor, FGameplayTag InTagToRemove);
	
	UFUNCTION(BlueprintCallable, Category = "Warrior | FunctionLibrary", meta = (DisplayName = "Does Actor Have Tag", ExpandEnumAsExecs = "OutConfirmType"))
	static void BP_DoesActorHaveTag (AActor* InActor, FGameplayTag InTagToCheck, EWarriorConfirmType& OutConfirmType);
	
	UFUNCTION(BlueprintCallable, Category = "Warrior | FunctionLibrary", meta = (DisplayName = "Get Pawn Combat Component From Actor", ExpandEnumAsExecs = "OutValidType"))
	static UPawnCombatComponent* BP_GetPawnCombatComponentFromActor (AActor* InActor, EWarriorValidType& OutValidType);
	
	UFUNCTION(BlueprintPure, Category = "Warrior | FunctionLibrary")
	static bool IsTargetHostile (APawn* QueryPawn, APawn* TargetPawn);
	
	UFUNCTION(BlueprintPure, Category = "Warrior | FunctionLibrary", meta=(CompactNodeTitle = "Get Value At Level"))
	static float GetScalableFloatValueAtLevel (FScalableFloat InScalableFloat, int32 InLevel);
};

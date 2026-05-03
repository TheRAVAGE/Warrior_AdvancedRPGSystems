// Project Made by Akhil Mathew Mathew @TheRAVAGE as a part of UDEMY course : Unreal Engine 5 C++ Advanced Action RPG by Vince Petrelli


#include "Warrior/AnimInstance/WarriorBaseAnimInstance.h"

#include "Warrior/WarriorFunctionLibrary.h"

bool UWarriorBaseAnimInstance::DoesOwnerHaveTag(FGameplayTag TagToCheck) const
{
	if(APawn* OwningPawn = TryGetPawnOwner())
	{
		return UWarriorFunctionLibrary::NativeDoesActorHaveTag(OwningPawn, TagToCheck);
	}
	return false;
}

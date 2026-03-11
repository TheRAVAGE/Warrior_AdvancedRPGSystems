// Project Made by Akhil Mathew Mathew @TheRAVAGE as a part of UDEMY course : Unreal Engine 5 C++ Advanced Action RPG by Vince Petrelli


#include "Warrior/AnimInstance/WarriorCharacterAnimInstance.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Warrior/Characters/WarriorBaseCharacter.h"

void UWarriorCharacterAnimInstance::NativeInitializeAnimation()
{
	CharacterRef = Cast<AWarriorBaseCharacter>(TryGetPawnOwner());
	if (CharacterRef)
	{
		MovementComponentRef = CharacterRef->GetCharacterMovement();
	}
}

void UWarriorCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!CharacterRef || !MovementComponentRef) {return;}
	
	GroundSpeed = CharacterRef->GetVelocity().Size2D();
	bHasAcceleration = MovementComponentRef->GetCurrentAcceleration().SizeSquared2D() > 0.f;
}

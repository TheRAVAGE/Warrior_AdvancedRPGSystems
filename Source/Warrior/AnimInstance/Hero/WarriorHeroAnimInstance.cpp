// Project Made by Akhil Mathew Mathew @TheRAVAGE as a part of UDEMY course : Unreal Engine 5 C++ Advanced Action RPG by Vince Petrelli


#include "Warrior/AnimInstance/Hero/WarriorHeroAnimInstance.h"

#include "Warrior/Characters/WarriorHeroCharacter.h"

void UWarriorHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	
	if (CharacterRef)
	{
		HeroCharacterRef = Cast<AWarriorHeroCharacter>(CharacterRef);
	}
}

void UWarriorHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
	
	CheckRelaxedStateTransition(DeltaSeconds);
}

void UWarriorHeroAnimInstance::CheckRelaxedStateTransition(float DeltaSeconds)
{
	if (bHasAcceleration || GroundSpeed > 0.f)
	{
		IdleElapsedTime = 0.f;
		bShouldEnterRelaxState = false;
	}
	else
	{
		IdleElapsedTime += DeltaSeconds;
		bShouldEnterRelaxState = IdleElapsedTime >= EnterRelaxStateThreshold;
	}
}

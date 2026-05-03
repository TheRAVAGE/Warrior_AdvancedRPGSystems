// Project Made by Akhil Mathew Mathew @TheRAVAGE as a part of UDEMY course : Unreal Engine 5 C++ Advanced Action RPG by Vince Petrelli


#include "Warrior/Characters/WarriorBaseCharacter.h"

#include "MotionWarpingComponent.h"
#include "Warrior/AbilitySystem/WarriorAbilitySystemComponent.h"
#include "Warrior/AbilitySystem/WarriorAttributeSet.h"

// Sets default values
AWarriorBaseCharacter::AWarriorBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;
	GetMesh()->bReceivesDecals = false;
	
	WarriorAbilitySystemComponent = CreateDefaultSubobject<UWarriorAbilitySystemComponent>(TEXT("WarriorAbilitySystemComponent"));
	WarriorAttributeSet = CreateDefaultSubobject<UWarriorAttributeSet>(TEXT("WarriorAttributeSet"));
	MotionWarpingComponent = CreateDefaultSubobject<UMotionWarpingComponent>(TEXT("MotionWarpingComponent"));

}

UAbilitySystemComponent* AWarriorBaseCharacter::GetAbilitySystemComponent() const
{
	return GetWarriorAbilitySystemComponent();
}

UPawnCombatComponent* AWarriorBaseCharacter::GetPawnCombatComponent() const
{
	return nullptr;
}

void AWarriorBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	if (WarriorAbilitySystemComponent)
	{
		WarriorAbilitySystemComponent->InitAbilityActorInfo(this, this);
		ensureMsgf(!CharacterStartUpData.IsNull(), TEXT("CharacterStartUpData is null. Please assign a valid Data Asset StartUpDataBase to the CharacterStartUpData property of %s"), *GetName());
	}
}


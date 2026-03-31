// Project Made by Akhil Mathew Mathew @TheRAVAGE as a part of UDEMY course : Unreal Engine 5 C++ Advanced Action RPG by Vince Petrelli


#include "Warrior/Items/Weapons/WarriorWeaponBase.h"

#include "Components/BoxComponent.h"
#include "Warrior/DebugHelper.h"

// Sets default values
AWarriorWeaponBase::AWarriorWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>("WeaponMesh");
	SetRootComponent(WeaponMesh);
	
	WeaponCollisionBox = CreateDefaultSubobject<UBoxComponent>("WeaponCollisionBox");
	WeaponCollisionBox->SetupAttachment(GetRootComponent());
	WeaponCollisionBox->SetBoxExtent(FVector(20.f));
	WeaponCollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	WeaponCollisionBox->OnComponentBeginOverlap.AddDynamic(this,&ThisClass::OnCollisionBoxBeginOverlap );
	WeaponCollisionBox->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnCollisionBoxEndOverlap);

}

void AWarriorWeaponBase::OnCollisionBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APawn* WeaponOwningPawn = GetInstigator<APawn>();
	checkf(WeaponOwningPawn, TEXT("Weapon %s does not have an instigator pawn"), *GetName());
	
	if (APawn* HitPawn = Cast<APawn>(OtherActor))
	{
		if (WeaponOwningPawn != HitPawn)
		{
			// Debug::PrintMessage(FString::Printf(TEXT("Begin Overlap with Pawn : %s"), *HitPawn->GetName()),FColor::Green);
			OnWeaponHitTarget.ExecuteIfBound(HitPawn);
		}
		//TODO: Implement Check for Enemy Character
	}
}

void AWarriorWeaponBase::OnCollisionBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                                  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	APawn* WeaponOwningPawn = GetInstigator<APawn>();
	checkf(WeaponOwningPawn, TEXT("Weapon %s does not have an instigator pawn"), *GetName(), FColor::Red);
	
	if (APawn* HitPawn = Cast<APawn>(OtherActor))
	{
		if (WeaponOwningPawn != HitPawn)
		{
			// Debug::PrintMessage(FString::Printf(TEXT("End Overlap with Pawn : %s"), *HitPawn->GetName()),FColor::Red);
			
			OnWeaponPulledFromTarget.ExecuteIfBound(HitPawn);
		}
		//TODO: Implement Check for Enemy Character
	}
}



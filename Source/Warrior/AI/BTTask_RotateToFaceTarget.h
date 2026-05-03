// Project Made by Akhil Mathew Mathew @TheRAVAGE as a part of UDEMY course : Unreal Engine 5 C++ Advanced Action RPG by Vince Petrelli

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_RotateToFaceTarget.generated.h"

/**
 * 
 */

struct FRotateToFaceTargetTaskMemory
{
	TWeakObjectPtr<APawn> OwningPawn;
	TWeakObjectPtr<AActor> TargetActor;
	
	bool IsValid()
	{
		return OwningPawn.IsValid() && TargetActor.IsValid();
	}
	
	void Reset()
	{
		OwningPawn.Reset();
		TargetActor.Reset();
	}
};
UCLASS()
class WARRIOR_API UBTTask_RotateToFaceTarget : public UBTTaskNode
{
	GENERATED_BODY()
	
	UBTTask_RotateToFaceTarget();
	
	//~ Begin UBTNode Interface
	virtual void InitializeFromAsset(UBehaviorTree& Asset) override;
	virtual uint16 GetInstanceMemorySize() const override;
	virtual FString GetStaticDescription() const override;
	//~ End UBTNode Interface
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
	bool HasReachedAnglePrecision(APawn* QueryPawn, AActor* TargetActor) const;
	
	
	UPROPERTY(EditAnywhere, Category="Face Target")
	float AnglePrecision;
	
	UPROPERTY(EditAnywhere, Category="Face Target")
	float RotationInterpSpeed;
	
	UPROPERTY(EditAnywhere, Category="Face Target")
	FBlackboardKeySelector InTargetToFaceKey;
	
	
};

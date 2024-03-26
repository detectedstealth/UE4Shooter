// Copyright Warply Designed

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyController.generated.h"

class UBehaviorTreeComponent;
/**
 * 
 */
UCLASS()
class UE4SHOOTER_API AEnemyController : public AAIController
{
	GENERATED_BODY()

public:
	AEnemyController();
	virtual void OnPossess(APawn* InPawn) override;

private:
	// Blackboard component for this enemy
	UPROPERTY(BlueprintReadWrite, Category="AI Behavior", meta=(AllowPrivateAccess="true"))
	UBlackboardComponent* BlackboardComponent;

	// Behavior tree component for this enemy
	UPROPERTY(BlueprintReadWrite, Category="AI Behavior", meta=(AllowPrivateAccess="true"))
	UBehaviorTreeComponent* BehaviorTreeComponent;

public:

	FORCEINLINE UBlackboardComponent* GetBlackboardComponent() const { return BlackboardComponent; }
};

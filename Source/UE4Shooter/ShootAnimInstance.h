// Copyright Warply Designed

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ShootAnimInstance.generated.h"

class AShooterCharacter;
/**
 * 
 */
UCLASS()
class UE4SHOOTER_API UShootAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void UpdateAnimationProperties(float DeltaTime);

	virtual void NativeInitializeAnimation() override;

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Movement", meta=(AllowPrivateAccess="true"))
	AShooterCharacter* ShooterCharacter;

	// The speed of the character
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Movement", meta=(AllowPrivateAccess="true"))
	float Speed;

	// Whether or not the character is in the air
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Movement", meta=(AllowPrivateAccess="true"))
	bool bIsInAir;

	// Whether or not the character is moving
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Movement", meta=(AllowPrivateAccess="true"))
	bool bIsAccelerating;

	// Offset Yaw used for strafing
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement", meta=(AllowPrivateAccess="true"))
	float MovementOffsetYaw;

	// Offset Yaw the frame before we stopped moving
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement", meta=(AllowPrivateAccess="true"))
	float LastMovementOffsetYaw;

	//
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Movement", meta=(AllowPrivateAccess="true"))
	bool bAiming;
	
};

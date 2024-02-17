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

	UShootAnimInstance();

	UFUNCTION(BlueprintCallable)
	void UpdateAnimationProperties(float DeltaTime);

	virtual void NativeInitializeAnimation() override;

protected:

	// Handle turning in place variables
	void TurnInPlace();

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

	// Yaw of the Character this frame
	float CharacterYaw;

	// Yaw of the Character the previous frame
	float CharacterYawLastFrame;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Turn In Place", meta=(AllowPrivateAccess="true"))
	float RootYawOffset;

	// Rotation curve value this frame
	float RotationCurve;

	// Rotation curve value last frame
	float RotationCurveLastFrame;
	
};

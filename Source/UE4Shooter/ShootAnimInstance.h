// Copyright Warply Designed

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ShootAnimInstance.generated.h"

UENUM(BlueprintType)
enum class EOffsetState : uint8
{
	EOS_Aiming UMETA(DisplayName="Aiming"),
	EOS_Hip UMETA(DisplayName="Hip"),
	EOS_Reloading UMETA(DisplayName="Reloading"),
	EOS_InAir UMETA(DisplayName="InAir"),

	EOS_MAX UMETA(DisplayName="DefaultMAX")
};

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

	// The pitch of the aim rotation, used for Aim Offset
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Turn In Place", meta=(AllowPrivateAccess="true"))
	float Pitch;

	// True when reloading, used to prevent Aim Offset while reloading
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Turn In Place", meta=(AllowPrivateAccess="true"))
	bool bReloading;

	// Offset state; used to determine which Aim Offset to use
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Turn In Place", meta=(AllowPrivateAccess="true"))
	EOffsetState OffsetState;
	
};

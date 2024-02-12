// Copyright Warply Designed

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

class USoundCue;
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class UE4SHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called for forwards/backwards input
	void MoveForward(float Value);

	// Called for right/left input
	void MoveRight(float Value);

	 /**
	  * Called via input to turn at a given rate.
	  * @param Rate This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	  */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to look up/down at a given rate.
	 * @param Rate This is a normaized rate, i.e. 1.0 means 100% of desired rate
	 */
	void LookUpAtRate(float Rate);

	// Called when the Fire Button is pressed
	void FireWeapon();


	bool GetBeamEndLocation(const FVector& MuzzleSocketLocation, FVector& OutBeamLocation);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	// Camera boom positioning the camera behind the character
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera", meta=(AllowPrivateAccess="true"))
	USpringArmComponent* CameraBoom;

	// Camera that follows the character
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera", meta=(AllowPrivateAccess="true"))
	UCameraComponent* FollowCamera;

	// Base turn rate, in deg/sec. Other scaling may affect final turn rate
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera", meta=(AllowPrivateAccess="true"))
	float BaseTurnRate;

	// Base look up/down rate in deg/sec. Other scaling may affect final turn rate
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera", meta=(AllowPrivateAccess="true"))
	float BaseLookUpRate;

	// Randomized gunshot sound cue
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat", meta=(AllowPrivateAccess="true"))
	USoundCue* FireSound;

	// Flash spawned at barrel_socket
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat", meta=(AllowPrivateAccess="true"))
	UParticleSystem* MuzzleFlash;

	// Montage for firing the weapon
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat", meta=(AllowPrivateAccess="true"))
	UAnimMontage* HipFireMontage;

	// Particles spawned upon bullet impact
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat", meta=(AllowPrivateAccess="true"))
	UParticleSystem* ImpactParticles;

	// Smoke trail for bullets
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat", meta=(AllowPrivateAccess="true"))
	UParticleSystem* BeamParticles;
	
public:

	// Returns CameraBoom subobject
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	// Returns FollowCamera subobject
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

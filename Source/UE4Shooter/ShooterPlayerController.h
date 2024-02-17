// Copyright Warply Designed

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UE4SHOOTER_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AShooterPlayerController();

protected:

	virtual void BeginPlay() override;

private:
	// Reference to the overall HUD overlay blueprint class
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Widgets", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UUserWidget> HUDOverlayClass;

	// Variable to hold the HUD overlay widget after creating it
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Widgets", meta=(AllowPrivateAccess="true"))
	UUserWidget* HUDOverlay;
};

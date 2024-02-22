// Copyright Warply Designed

#pragma once

#include "CoreMinimal.h"
#include "AmmoType.h"
#include "Item.h"
#include "Ammo.generated.h"

/**
 * 
 */
UCLASS()
class UE4SHOOTER_API AAmmo : public AItem
{
	GENERATED_BODY()

public:
	AAmmo();
	virtual void Tick(float DeltaSeconds) override;

protected:
	virtual void BeginPlay() override;
	// Overriden to be able to set AmmoMesh properties
	virtual void SetItemProperties(EItemState State) override;

	// Called when overlapping AreaSphere
	UFUNCTION()
	void AmmoSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


private:

	// Mesh for the ammo pickup
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Ammo", meta=(AllowPrivateAccess="true"))
	UStaticMeshComponent* AmmoMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ammo", meta=(AllowPrivateAccess="true"))
	EAmmoType AmmoType;

	// The texture for the Ammo icon
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ammo", meta=(AllowPrivateAccess="true"))
	UTexture2D* AmmoIconTexture;

	// Overlap sphere for picking up the Ammo
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ammo", meta=(AllowPrivateAccess="true"))
	USphereComponent* AmmoCollisionSphere;

public:
	FORCEINLINE UStaticMeshComponent* GetAmmoMesh() const { return AmmoMesh; }
	FORCEINLINE EAmmoType GetAmmoType() const { return AmmoType; }
};

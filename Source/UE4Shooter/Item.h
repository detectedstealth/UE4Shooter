// Copyright Warply Designed

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

class USphereComponent;
class UBoxComponent;
class UWidgetComponent;

UENUM(BlueprintType)
enum class EItemRarity : uint8
{
	EIR_Damaged UMETA(DisplayName="Damaged"),
	EIR_Common UMETA(DisplayName="Common"),
	EIR_Uncommon UMETA(DisplayName="Uncommon"),
	EIR_Rare UMETA(DisplayName="Rare"),
	EIR_Legendary UMETA(DisplayName="Legendary"),
	
	EIR_MAX UMETA(DisplayName="DefaultMAX")
};

UENUM(BlueprintType)
enum class EItemState : uint8
{
	EIS_Pickup UMETA(DisplayName="Pickup"),
	EIS_EquipInterping UMETA(DisplayName="EquipInterping"),
	EIS_PickedUp UMETA(DisplayName="PickedUp"),
	EIS_Equipped UMETA(DisplayName="Equipped"),
	EIS_Failling UMETA(DisplayName="Failling"),
	
	EIS_MAX UMETA(DisplayName="DefaultMAX")
};

UCLASS()
class UE4SHOOTER_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called when overlapping AreaSphere
	UFUNCTION()
	void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Called when end overlapping AreaSphere
	UFUNCTION()
	void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	// Sets the ActiveStars array of bools based on rarity
	void SetActiveStars();

	// Sets properties of the Item's components based on State
	void SetItemProperties(EItemState State);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	// Skeletal Mesh for the item
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category="Item Properties", meta=(AllowPrivateAccess="true"))
	USkeletalMeshComponent* ItemMesh;
	
	// Line trace collides with box to show HUD widgets
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Properties", meta=(AllowPrivateAccess="true"))
	class UBoxComponent* CollisionBox;

	// Popup widget for when the player looks at the item
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Properties", meta=(AllowPrivateAccess="true"))
	UWidgetComponent* PickupWidget;

	// Enables item tracing when overlapped
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Properties", meta=(AllowPrivateAccess="true"))
	USphereComponent* AreaSphere;

	// The name which appears on the Pickup Widget
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Properties", meta=(AllowPrivateAccess="true"))
	FString ItemName;

	// Item amount (ammo, etc
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item Properties", meta=(AllowPrivateAccess="true"))
	int32 ItemCount;

	// Item rarity - determines number of stars in Pickup Widget
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Properties", meta=(AllowPrivateAccess="true"))
	EItemRarity ItemRarity;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Item Properties", meta=(AllowPrivateAccess="true"))
	TArray<bool> ActiveStars;

	// State of the Item
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Item Properties", meta=(AllowPrivateAccess="true"))
	EItemState ItemState;
	
public:
	FORCEINLINE UWidgetComponent* GetPickupWidget() const { return PickupWidget; }
	FORCEINLINE USphereComponent* GetAreaSphere() const { return AreaSphere; }
	FORCEINLINE UBoxComponent* GetCollisionBox() const { return CollisionBox; }
	FORCEINLINE EItemState GetItemState() const { return ItemState; }
	void SetItemState(EItemState State);
	FORCEINLINE USkeletalMeshComponent* GetItemMesh() const { return ItemMesh; }
};

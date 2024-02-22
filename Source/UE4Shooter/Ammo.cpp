// Copyright Warply Designed


#include "Ammo.h"

#include "ShooterCharacter.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"

AAmmo::AAmmo()
{
	AmmoMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AmmoMesh"));
	SetRootComponent(AmmoMesh);

	GetCollisionBox()->SetupAttachment(GetRootComponent());
	GetPickupWidget()->SetupAttachment(GetRootComponent());
	GetAreaSphere()->SetupAttachment(GetRootComponent());

	AmmoCollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("AmmoCollisionSphere"));
	AmmoCollisionSphere->SetupAttachment(GetRootComponent());
	AmmoCollisionSphere->SetSphereRadius(50.f);
}

void AAmmo::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AAmmo::BeginPlay()
{
	Super::BeginPlay();

	AmmoCollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &AAmmo::AmmoSphereOverlap);
}

void AAmmo::SetItemProperties(EItemState State)
{
	Super::SetItemProperties(State);

	switch (State)
	{
	case EItemState::EIS_Pickup:
		// Set mesh properties
		AmmoMesh->SetSimulatePhysics(false);
		AmmoMesh->SetEnableGravity(false);
		AmmoMesh->SetVisibility(true);
		AmmoMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
		AmmoMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		break;

	case EItemState::EIS_Equipped:
		// Set mesh properties
		AmmoMesh->SetSimulatePhysics(false);
		AmmoMesh->SetEnableGravity(false);
		AmmoMesh->SetVisibility(true);
		AmmoMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
		AmmoMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		break;

	case EItemState::EIS_Failling:
		// Set Mesh properties
		AmmoMesh->SetSimulatePhysics(true);
		AmmoMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		AmmoMesh->SetEnableGravity(true);
		AmmoMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
		AmmoMesh->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
		break;

	case EItemState::EIS_EquipInterping:
		// Set mesh properties
		AmmoMesh->SetSimulatePhysics(false);
		AmmoMesh->SetEnableGravity(false);
		AmmoMesh->SetVisibility(true);
		AmmoMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
		AmmoMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		break;
		
	default: break;
	}
}

void AAmmo::AmmoSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		auto OverlappedCharacter = Cast<AShooterCharacter>(OtherActor);
		if (OverlappedCharacter)
		{
			StartItemCurve(OverlappedCharacter);
			AmmoCollisionSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		}
	}
}


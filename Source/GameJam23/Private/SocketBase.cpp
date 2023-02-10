// Fill out your copyright notice in the Description page of Project Settings.


#include "SocketBase.h"
#include "CPPGameInstance.h"
#include "BlueprintFuncLibTools.h"
#include "Room.h"

void ASocketBase::Initialize(double X, double Y)
{
	socketIndex = { X, Y };
}

// Sets default values
ASocketBase::ASocketBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Border1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Border1"));
	Border2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Border2"));
	Border3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Border3"));
	Border4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Border4"));

	UBoxComponent* boxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box"));
	boxCollision->SetBoxExtent({1000,1000,50});
	boxCollision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	boxCollision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	RootComponent = boxCollision;

	Border1->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	Border2->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	Border3->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	Border4->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	UStaticMesh* mesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'")).Object;
	Border1->SetStaticMesh(mesh);
	Border2->SetStaticMesh(mesh);
	Border3->SetStaticMesh(mesh);
	Border4->SetStaticMesh(mesh);
	
	Border1->SetRelativeTransform({ {0,0,0}, { - 950, 0, 0}, {1,20,1} });
	Border2->SetRelativeTransform({ {0,0,0}, {0, 950, 0},{18,1,1} });
	Border3->SetRelativeTransform({ {0,0,0}, {950, 0, 0},{1,20,1} });
	Border4->SetRelativeTransform({ {0,0,0}, {0, -950, 0},{18,1,1} });
	
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> FoundMaterial(TEXT("MaterialInstanceConstant'/Game/Data/Building/M_Emissive.M_Emissive'"));
	
	UMaterialInterface* StoredMaterial;
	if (FoundMaterial.Succeeded())
	{
		StoredMaterial = FoundMaterial.Object;
		
		Border1->SetMaterial(0, StoredMaterial);
		Border2->SetMaterial(0, StoredMaterial);
		Border3->SetMaterial(0, StoredMaterial);
		Border4->SetMaterial(0, StoredMaterial);
	}
}

// Called when the game starts or when spawned
void ASocketBase::BeginPlay()
{
	gameInstance = Cast<UCPPGameInstance>(GetGameInstance());
}

// Called every frame
void ASocketBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASocketBase::NotifyActorOnClicked(FKey ButtonPressed)
{
	if (placedRoom == nullptr) {
		if(gameInstance->selectedRoom != nullptr){
			FTransform transform = GetActorTransform();
			FVector location = transform.GetLocation();
			location.Z += 150;
			transform.SetLocation(location);
			placedRoom = GetWorld()->SpawnActorDeferred<ARoom>(gameInstance->selectedRoom, transform);
			placedRoom->Initialize(socketIndex);
			placedRoom->FinishSpawning(transform);
			//DoesPathExists function
			gameInstance->pathExists = UBlueprintFuncLibTools::doesPathExists(gameInstance->socketGrid);
			
		}
	}
}

void ASocketBase::NotifyActorBeginCursorOver()
{
	if (placedRoom == nullptr) {
		if (gameInstance->selectedRoom != nullptr) {
			FTransform transform = GetActorTransform();
			FVector location = transform.GetLocation();
			location.Z += 150;
			transform.SetLocation(location);
			hoverRoom = GetWorld()->SpawnActor<ARoom>(gameInstance->selectedRoom, transform);
			hoverRoom->SetActorEnableCollision(false);
		}
	}
}

void ASocketBase::NotifyActorEndCursorOver()
{
	if (hoverRoom != nullptr) {
		hoverRoom->Destroy();
		hoverRoom = nullptr;
	}
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "GridSpawner.h"

// Sets default values
AGridSpawner::AGridSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

AGridSpawner::~AGridSpawner()
{
}

// Called when the game starts or when spawned
void AGridSpawner::BeginPlay()
{
	//Spawn all Sockets
	for (int i = 0; i < RowNumber; i++) {
		socketGrid.AddDefaulted();
		for (int j = 0; j < ColumnNumber; j++) {
			FVector location = { GetActorLocation().X + i * 2000, GetActorLocation().Y + j * 2000, GetActorLocation().Z };
			FTransform spawnTransform = { GetActorRotation(), location, { 1,1,1 } };
			socketGrid[i].Add(GetWorld()->SpawnActorDeferred<ASocketBase>(ASocketBase::StaticClass(), spawnTransform));
			socketGrid[i][j]->Initialize(i, j);
			socketGrid[i][j]->FinishSpawning(spawnTransform);
		}
	}
	//Spawn Start and End Room
	int32 rng = FMath::RandRange(0, RowNumber - 1);
	FTransform transform = socketGrid[rng][0]->GetActorTransform();
	transform.SetLocation({ transform.GetLocation().X, transform.GetLocation().Y, transform.GetLocation().Z + 150});
	socketGrid[rng][0]->placedRoom = GetWorld()->SpawnActor<ARoom>(StartRoom, transform);

	rng = FMath::RandRange(0, RowNumber - 1);
	transform = socketGrid[rng][ColumnNumber - 1]->GetActorTransform();
	transform.SetLocation({ transform.GetLocation().X, transform.GetLocation().Y, transform.GetLocation().Z + 150 });
	socketGrid[FMath::RandRange(0, RowNumber - 1)][ColumnNumber-1]->placedRoom = GetWorld()->SpawnActor<ARoom>(EndRoom, transform);
	
}

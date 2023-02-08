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
	for (int i = 0; i < RowNumber; i++) {
		socketGrid.AddDefaulted();
		for (int j = 0; j < ColumnNumber; j++) {
			FVector location = { GetActorLocation().X + i * 2000, GetActorLocation().Y + j * 2000, GetActorLocation().Z };
			FVector scale = { 1,1,1 };
			FTransform spawnTransform = { GetActorRotation(), location, scale };
			socketGrid[i].Add(GetWorld()->SpawnActorDeferred<ASocketBase>(ASocketBase::StaticClass(), spawnTransform));
			socketGrid[i][j]->Initialize(i, j);
			socketGrid[i][j]->FinishSpawning(spawnTransform);
		}
	}
}

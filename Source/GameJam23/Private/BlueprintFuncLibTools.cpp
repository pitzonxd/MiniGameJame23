// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueprintFuncLibTools.h"
#include "SocketBase.h"
#include "Kismet/KismetStringLibrary.h"
#include "Engine/GameEngine.h"
#include "CPPGameInstance.h"

bool UBlueprintFuncLibTools::_doesPathExists(TArray<TArray<arrStruct>> socketArray, TArray<FVector2D> neighbors, FVector2D endIndex)
{
	if (neighbors.Num() == 0) {
		return false;
	}

	TArray<FVector2D> newNeighbors;

	for (auto& neighbor : neighbors) {
		socketArray[neighbor.X][neighbor.Y].visited = true;
		if (neighbor == endIndex) {
			return true;
		}
		for (auto& newNeighbor : getValidNeighbors(socketArray, neighbor)) {
			newNeighbors.Add(newNeighbor);
		}
	}
	return _doesPathExists(socketArray, newNeighbors, endIndex);
}

TArray<FVector2D> UBlueprintFuncLibTools::getValidNeighbors(TArray<TArray<arrStruct>> socketArray, FVector2D thisIndex)
{
	TArray<FVector2D> neighbors;
	if (thisIndex.X != 0) {
		if (socketArray[thisIndex.X - 1][thisIndex.Y].step != -1 && socketArray[thisIndex.X - 1][thisIndex.Y].visited != true) {
			neighbors.Add(FVector2D(thisIndex.X - 1, thisIndex.Y));
		}
	}
	if (thisIndex.Y != 0) {
		if (socketArray[thisIndex.X][thisIndex.Y - 1].step != -1 && socketArray[thisIndex.X][thisIndex.Y - 1].visited != true) {
			neighbors.Add(FVector2D(thisIndex.X, thisIndex.Y - 1));
		}
	}
	if (thisIndex.X < socketArray.Num() - 1) {
		if (socketArray[thisIndex.X + 1][thisIndex.Y].step != -1 && socketArray[thisIndex.X + 1][thisIndex.Y].visited != true) {
			neighbors.Add(FVector2D(thisIndex.X + 1, thisIndex.Y));
		}
	}
	if (thisIndex.Y < socketArray[0].Num() - 1) {
		if (socketArray[thisIndex.X][thisIndex.Y + 1].step != -1 && socketArray[thisIndex.X][thisIndex.Y + 1].visited != true) {
			neighbors.Add(FVector2D(thisIndex.X, thisIndex.Y + 1));
		}
	}
	return neighbors;
}

bool UBlueprintFuncLibTools::doesPathExists(UCPPGameInstance* gameInstance)
{
	//make 2D Array of int of size socketGrid, then populate with obstacles
	TArray<TArray<arrStruct>>socketArray;
	for (int i = 0; i < gameInstance->socketGrid.Num(); i++) {
		socketArray.AddDefaulted();
		for (int j = 0; j < gameInstance->socketGrid[0].Num(); j++) {
			if (gameInstance->socketGrid[i][j]->placedRoom != nullptr) {
				socketArray[i].Add({ false, 0 });
			}
			else {
				socketArray[i].Add(arrStruct());
			}
		}
	}
	socketArray[gameInstance->startIndex.X][gameInstance->startIndex.Y].visited = true;
	return _doesPathExists(socketArray, getValidNeighbors(socketArray, gameInstance->startIndex), gameInstance->endIndex);
}

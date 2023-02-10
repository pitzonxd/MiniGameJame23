// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueprintFuncLibTools.h"
#include "SocketBase.h"

bool UBlueprintFuncLibTools::_doesPathExists()
{
	return false;
}

bool UBlueprintFuncLibTools::doesPathExists(TArray<TArray<ASocketBase*>> socketGrid)
{
	/*
	struct arrStruct {
		bool visited = false;
		int step = -1;
	};

	//make 2D Array of int of size socketGrid, then populate with obstacles
	TArray<TArray<arrStruct>>socketArray;
	for (int i = 0; i < socketGrid.Num(); i++) {
		socketArray.AddDefaulted();
		for (int j = 0; j < socketGrid[0].Num(); j++) {
			if (socketGrid[i][j]->placedRoom != nullptr) {
				socketArray[i].Add({ false, 0 });
			}
			socketArray[i].Add(arrStruct());
		}
	}
	*/
	return false;
}

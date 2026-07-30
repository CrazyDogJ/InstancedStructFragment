// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NameTextStruct.generated.h"

USTRUCT(BlueprintType)
struct INSTANCEDSTRUCTFRAGMENT_API FNameTextStruct
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Id = "";

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText DisplayName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText DisplayDescription;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString CategoryId = "";

#if WITH_EDITOR
	// Call it when this struct of property changed.
	void RefreshLocalizationKey();
#endif
};

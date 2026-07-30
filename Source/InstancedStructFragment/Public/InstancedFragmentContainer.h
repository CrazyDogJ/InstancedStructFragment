// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StructUtils/InstancedStruct.h"
#include "InstancedFragmentContainer.generated.h"

USTRUCT(BlueprintType)
struct INSTANCEDSTRUCTFRAGMENT_API FInstancedFragmentContainer
{
	GENERATED_BODY()

public:
	// Instanced struct datas.
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FInstancedStruct> DefaultFragments;

	// Return default item fragment.
	template <typename T>
		const T* GetFragmentPtr() const
	{
		const UScriptStruct* StructType = T::StaticStruct();
		if (const auto Found = TypeLookup.Find(StructType))
		{
			return DefaultFragments[*Found].GetPtr<T>();
		}
		
		return nullptr;
	}

	// Used in bp custom nodes.
	FInstancedStruct FindFragmentByClass(const UScriptStruct* StructType, bool& bValid) const;
	
#if WITH_EDITOR
	// Call it when this DefaultFragments of this struct changed.
	void RebuildTypeMapping();
#endif
	
protected:
	// Accelerate look up.
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, AdvancedDisplay, Category = "Storage Info")
	TMap<const UScriptStruct*, int> TypeLookup;
};

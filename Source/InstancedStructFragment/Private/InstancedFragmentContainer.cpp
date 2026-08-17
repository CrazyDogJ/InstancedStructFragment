// Fill out your copyright notice in the Description page of Project Settings.


#include "InstancedFragmentContainer.h"

FInstancedStruct FInstancedFragmentContainer::FindFragmentByClass(const UScriptStruct* StructType, bool& bValid) const
{
	FInstancedStruct EmptyStruct;
	EmptyStruct.InitializeAs(StructType);

	if (const auto Found = TypeLookup.Find(StructType))
	{
		FInstancedStruct Dummy;
		Dummy.InitializeAs(DefaultFragments[*Found].GetScriptStruct());

		if (Dummy.Identical(&EmptyStruct, 0))
		{
			bValid = true;
			return DefaultFragments[*Found];
		}
	}
	
	bValid = false;
	return FInstancedStruct();
}

#if WITH_EDITOR
void FInstancedFragmentContainer::RebuildTypeMapping()
{
	// Update lookup pre save.
	TypeLookup.Empty();
	
	for (int i = 0; i < DefaultFragments.Num(); i++)
	{
		if (DefaultFragments[i].IsValid())
		{
			auto Type = DefaultFragments[i].GetScriptStruct();
			TypeLookup.Add(Type, i);
		}
	}
}
#endif
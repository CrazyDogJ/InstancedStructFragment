// Fill out your copyright notice in the Description page of Project Settings.


#include "NameTextStruct.h"

#if WITH_EDITOR
void FNameTextStruct::RefreshLocalizationKey()
{
	if (!Id.IsEmpty())
	{
		DisplayName =
			FText::ChangeKey(CategoryId, Id + "DisplayName", DisplayName);
		DisplayDescription =
			FText::ChangeKey(CategoryId, Id + "DisplayDescription", DisplayDescription);
	}
}
#endif
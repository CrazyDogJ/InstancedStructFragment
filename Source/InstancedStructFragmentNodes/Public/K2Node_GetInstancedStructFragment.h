// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InstancedFragmentContainer.h"
#include "K2Node_InstancedStructQuery.h"
#include "StructUtils/InstancedStruct.h"
#include "K2Node_GetInstancedStructFragment.generated.h"

UCLASS(BlueprintType, Blueprintable)
class INSTANCEDSTRUCTFRAGMENTNODES_API UK2Node_GetInstancedStructFragment : public UK2Node_InstancedStructQuery
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static UPARAM(DisplayName = "Property")FInstancedStruct FindFragmentByClass(const FInstancedFragmentContainer& InContainer, const UScriptStruct* StructType, bool& bValid);
	
	//~ UEdGraphNode Interface.
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual FText GetTooltipText() const override;
	virtual FText GetKeywords() const override;
	virtual void AllocateDefaultPins() override;

	//~ UK2Node Interface
	virtual void GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const override;
	virtual void ExpandNode(class FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph) override;
};

﻿// Copyright Out-of-the-Box Plugins 2018-2023. All Rights Reserved.

#pragma once

#include "QuickMenuExtension.h"

#include "ToolbarMenuSelectHierarchyExtension.generated.h"

/**
 * Add entries from the main frame toolbar -> Select menu -> Hierarchy section
 */
UCLASS()
class UToolbarMenuSelectHierarchyExtension : public UQuickMenuExtension
{
	GENERATED_BODY()

	virtual TArray<TSharedPtr<FQuickCommandEntry>> GetCommands(const FQuickCommandContext& Context) override;
};

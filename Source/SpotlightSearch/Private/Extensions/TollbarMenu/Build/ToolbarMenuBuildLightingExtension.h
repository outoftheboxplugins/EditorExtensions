﻿// Copyright Out-of-the-Box Plugins 2018-2023. All Rights Reserved.

#pragma once

#include "QuickMenuExtension.h"

#include "ToolbarMenuBuildLightingExtension.generated.h"

/**
 * Add entries from the main frame toolbar -> Build menu -> Lighting section
 */
UCLASS()
class UToolbarMenuBuildLightingExtension : public UQuickMenuExtension
{
	GENERATED_BODY()

	virtual TArray<TSharedPtr<FQuickCommandEntry>> GetCommands(const FQuickCommandContext& Context) override;
};
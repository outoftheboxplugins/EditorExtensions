﻿// Copyright Out-of-the-Box Plugins 2018-2023. All Rights Reserved.

#include "ToolbarMenuBuildTextureStreamingExtension.h"

#include <LevelEditor.h>
#include <LevelEditorActions.h>

TArray<TSharedPtr<FQuickCommandEntry>> UToolbarMenuBuildTextureStreamingExtension::GetCommands(const FToolMenuContext& Context)
{
	TArray<TSharedPtr<FQuickCommandEntry>> OutCommands;

	const FLevelEditorModule& LevelEditorModule = FModuleManager::Get().LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	const TSharedRef<FUICommandList> LevelEditorCommands = LevelEditorModule.GetGlobalLevelEditorActions();

	const TSharedPtr<FQuickCommandEntry> BuildTextureStreaming = MakeShared<FQuickCommandEntry>(FLevelEditorCommands::Get().BuildTextureStreamingOnly.ToSharedRef(), LevelEditorCommands);
	OutCommands.Emplace(BuildTextureStreaming);

	const TSharedPtr<FQuickCommandEntry> BuildTextureVirtual = MakeShared<FQuickCommandEntry>(FLevelEditorCommands::Get().BuildVirtualTextureOnly.ToSharedRef(), LevelEditorCommands);
	OutCommands.Emplace(BuildTextureVirtual);

	return OutCommands;
}
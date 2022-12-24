﻿// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

#include "ToolbarMenuFileProjectExtension.h"

#include <Interfaces/IMainFrameModule.h>

TArray<FQuickCommandEntry> UToolbarMenuFileProjectExtension::GetCommands()
{
	TArray<FQuickCommandEntry> OutCommands;

	IMainFrameModule& MainFrameModule = FModuleManager::Get().LoadModuleChecked<IMainFrameModule>("MainFrame");
	TSharedPtr<const FUICommandList> MainFrameCommands = MainFrameModule.GetMainFrameCommandBindings();

	UToolMenus* ToolMenus = UToolMenus::Get();
	UToolMenu* MainTabFileMenu = ToolMenus->ExtendMenu("MainFrame.MainTabMenu.File");
	FToolMenuSection* ProjectSection = MainTabFileMenu->FindSection("FileProject");

	for (FToolMenuEntry& Block : ProjectSection->Blocks)
	{
		// NOTE: the block has no command list assigned, we temporarily assign the MainFrame list to access the FUIAction and revert it afterwards
		Block.SetCommandList(MainFrameCommands);
		if (const FUIAction* FoundAction = Block.GetActionForCommand(ProjectSection->Context, MainFrameCommands))
		{
			FQuickCommandEntry MenuEntry;
			MenuEntry.Title = Block.Label;
			MenuEntry.Tooltip = Block.ToolTip;
			MenuEntry.Icon = Block.Icon;
			MenuEntry.CanExecuteCallback = FoundAction->CanExecuteAction;
			MenuEntry.ExecuteCallback = FoundAction->ExecuteAction;

			OutCommands.Emplace(MenuEntry);
		}
		Block.SetCommandList({});
	}

	return OutCommands;
}
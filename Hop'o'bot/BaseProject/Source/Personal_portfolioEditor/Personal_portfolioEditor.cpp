#include "Personal_portfolioEditor.h"
#include "Modules/ModuleManager.h"
#include "Modules/ModuleInterface.h"

#include "Personal_portfolio/MoveComponent.h"

#define LOCTEXT_NAMESPACE "FPersonal_portfolioEditorModule"

IMPLEMENT_MODULE(FPersonal_portfolioEditorModule, Personal_portfolioEditor);


void FPersonal_portfolioEditorModule::StartupModule()
{
    //Place your editor-only startup code here (menus, spawners, etc.)
}

void FPersonal_portfolioEditorModule::ShutdownModule()
{
    Cleanup any editor hooks you registered in StartupModule()
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPersonal_portfolioEditorModule, Personal_portfolioEditor);
#pragma once

#include "Engine.h"
#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"
#include "UnrealEd.h"
#include "MoveComponentVisualizer.h"

DECLARE_LOG_CATEGORY_EXTERN(Personal_portfolioEditor, All, All)

//class FPersonal_portfolioEditorModule : public IModuleInterface
//{
//public:
    //virtual void StartupModule() override;
    //virtual void ShutdownModule() override;
//};

// Personal_portfolioEditor.h

class FPersonal_portfolioEditorModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
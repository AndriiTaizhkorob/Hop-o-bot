// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ComponentVisualizer.h"
#include "Personal_portfolio/MoveComponent.h"

/**
 * 
 */
class PERSONAL_PORTFOLIOEDITOR_API FMoveComponentVisualizer : public FComponentVisualizer
{


public:
	void DrawVisualization(const UActorComponent* Component, const FSceneView* View, FPrimitiveDrawInterface* PDI) override;

};

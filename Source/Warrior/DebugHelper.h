// Project Made by Akhil Mathew Mathew @TheRAVAGE as a part of UDEMY course : Unreal Engine 5 C++ Advanced Action RPG by Vince Petrelli

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
namespace Debug
{
	static void PrintMessage(const FString &Message, const FColor &Color = FColor::MakeRandomColor(), int32 InKey = -1, bool bLog = false)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(InKey, 5.f, Color, Message);
			if (bLog)
			{
				UE_LOG(LogTemp, Warning, TEXT("%s"), *Message);
			}
		}
	}
	
	static void PrintMessage(const FString &FloatTitle,const float Value, const FColor &Color = FColor::MakeRandomColor(), int32 InKey = -1, bool bLog = false)
	{
		if (GEngine)
		{
			const FString &FloatText = FloatTitle + TEXT(" : ") + FString::SanitizeFloat(Value);
			GEngine->AddOnScreenDebugMessage(InKey, 5.f, Color, FloatText);
			if (bLog)
			{
				UE_LOG(LogTemp, Warning, TEXT("%s"), *FloatText);
			}
		}
	}
	
}

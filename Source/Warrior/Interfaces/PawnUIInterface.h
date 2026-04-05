// Project Made by Akhil Mathew Mathew @TheRAVAGE as a part of UDEMY course : Unreal Engine 5 C++ Advanced Action RPG by Vince Petrelli

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PawnUIInterface.generated.h"

class UPawnUIComponentBase;
class UHeroUIComponentBase;
class UEnemyUIComponentBase;
// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPawnUIInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class WARRIOR_API IPawnUIInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual UPawnUIComponentBase* GetPawnUIComponent() const = 0;
	virtual UHeroUIComponentBase* GetHeroUIComponent() const {return nullptr;};
	virtual UEnemyUIComponentBase* GetEnemyUIComponent() const {return nullptr;};
};

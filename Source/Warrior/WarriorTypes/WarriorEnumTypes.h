// Project Made by Akhil Mathew Mathew @TheRAVAGE as a part of UDEMY course : Unreal Engine 5 C++ Advanced Action RPG by Vince Petrelli

#pragma once

UENUM() 
enum class EWarriorConfirmType : uint8
{
	Yes,
	No
};

UENUM() 
enum class EWarriorValidType : uint8
{
	Valid,
	Invalid
};

UENUM() 
enum class EWarriorSuccessType : uint8
{
	Successful,
	Failed
};
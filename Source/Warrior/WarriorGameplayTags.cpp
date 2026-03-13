// Project Made by Akhil Mathew Mathew @TheRAVAGE as a part of UDEMY course : Unreal Engine 5 C++ Advanced Action RPG by Vince Petrelli


#include "WarriorGameplayTags.h"

namespace WarriorGameplayTags
{
	// Input tags
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Input_Move, "Input.Move");
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Input_Look, "Input.Look");
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Input_EquipAxe, "Input.EquipAxe");
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Input_UnEquipAxe, "Input.UnEquipAxe");
	
	//Player Tags
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Axe, "Player.Weapon.Axe");
}
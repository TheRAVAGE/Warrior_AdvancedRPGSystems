// Project Made by Akhil Mathew Mathew @TheRAVAGE as a part of UDEMY course : Unreal Engine 5 C++ Advanced Action RPG by Vince Petrelli

#pragma once
#include "NativeGameplayTags.h"

namespace WarriorGameplayTags
{
	// Input tags
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_Move);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_Look);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_EquipAxe);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_UnEquipAxe);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_LightAttack_Axe);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_HeavyAttack_Axe);
	
	//Player Tags
	//Player - Weapon Tags
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Axe);
	
	//Player - Ability Tags
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Equip_Axe);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Unequip_Axe);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Light_Axe);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Heavy_Axe);
		
	//Player - Event Tags
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Equip_Axe);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Unequip_Axe);
	
	//Player - Status Tags
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Status_JumpToFinisher);
	
	
	//Enemy Tags
	//Enemy - Weapon Tags
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Weapon);
}

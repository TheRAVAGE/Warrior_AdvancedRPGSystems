// Project Made by Akhil Mathew Mathew @TheRAVAGE as a part of UDEMY course : Unreal Engine 5 C++ Advanced Action RPG by Vince Petrelli


#include "WarriorGameplayTags.h"

namespace WarriorGameplayTags
{
	// Input tags
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Input_Move, "Input.Move");
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Input_Look, "Input.Look");
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Input_EquipAxe, "Input.EquipAxe");
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Input_UnEquipAxe, "Input.UnEquipAxe");
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Input_LightAttack_Axe, "Input.LightAttack.Axe");
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Input_HeavyAttack_Axe, "Input.HeavyAttack.Axe");
	
	//Player Tags
	//Player - Weeapon Tags
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Axe, "Player.Weapon.Axe");
	
	//Player - Ability Tags
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Equip_Axe, "Player.Ability.Equip.Axe");
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Unequip_Axe, "Player.Ability.Unequip.Axe");
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Light_Axe, "Player.Ability.Attack.Light.Axe");
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Heavy_Axe, "Player.Ability.Attack.Heavy.Axe");
	
	//Player - Event Tags
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Player_Event_Equip_Axe, "Player.Event.Equip.Axe");
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Player_Event_Unequip_Axe, "Player.Event.Unequip.Axe");
	
	//Player - Status Tags
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Player_Status_JumpToFinisher, "Player.Status.JumpToFinisher");
	
	//Enemy Tags
	//Enemy - Weapon Tags
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Enemy_Weapon, "Enemy.Weapon");
	
}
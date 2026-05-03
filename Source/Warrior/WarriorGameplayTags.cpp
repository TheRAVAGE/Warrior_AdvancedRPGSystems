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
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Input_Roll, "Input.Roll");
	
	//Player Tags
	//Player - Weeapon Tags
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Axe, "Player.Weapon.Axe");
	
	//Player - Ability Tags
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Equip_Axe, "Player.Ability.Equip.Axe");
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Unequip_Axe, "Player.Ability.Unequip.Axe");
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Light_Axe, "Player.Ability.Attack.Light.Axe");
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Heavy_Axe, "Player.Ability.Attack.Heavy.Axe");
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Player_Ability_HitPause, "Player.Ability.HitPause");
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Roll, "Player.Ability.Roll");
	
	//Player - Event Tags
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Player_Event_Equip_Axe, "Player.Event.Equip.Axe");
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Player_Event_Unequip_Axe, "Player.Event.Unequip.Axe");
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Player_Event_HitPause, "Player.Event.HitPause");
	
	//Player - Status Tags
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Player_Status_JumpToFinisher, "Player.Status.JumpToFinisher");
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Player_Status_Rolling, "Player.Status.Rolling");
	
	//Player - Attack Type Tags
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Player_SetByCaller_AttackType_Light, "Player.SetByCaller.AttackType.Light");
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Player_SetByCaller_AttackType_Heavy, "Player.SetByCaller.AttackType.Heavy");
	
	//Enemy Tags
	//Enemy - Ability Tags
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_Melee, "Enemy.Ability.Melee");
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_Ranged, "Enemy.Ability.Ranged");
	
	//Enemy - Weapon Tags
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Enemy_Weapon, "Enemy.Weapon");
	
	//Enemy - Status Tags
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Enemy_Status_Strafing, "Enemy.Status.Strafing");
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Enemy_Status_UnderAttack, "Enemy.Status.UnderAttack");
	
	//Shared Tags
	//Shared - Ability Tags
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_HitReact, "Shared.Ability.HitReact");
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_Death, "Shared.Ability.Death");
	
	//Shared - Event Tags
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Shared_Event_MeleeHit, "Shared.Event.MeleeHit");
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Shared_Event_HitReact, "Shared.Event.HitReact");
	
	//Shared - SetByCaller Tags
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Shared_SetByCaller_BaseDamage, "Shared.SetByCaller.BaseDamage");
	
	//Shared - Status Tags
	WARRIOR_API UE_DEFINE_GAMEPLAY_TAG(Shared_Status_Dead, "Shared.Status.Dead");
}
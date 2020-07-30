#pragma once

#include <vector>
#include <string>

namespace DigiRoyale
{

struct Item
{
	enum ItemType
	{
		weapon,
		consumable
	};
	std::string name;
};

struct Weapon : public Item
{
	float range;
	float directDamage; //damage from direct hit (explosives have damage falloff)
	bool throwable; //should weapon be thrown (anything can be thrown, but should it?)
};

struct Consumable : public Item
{
	enum ConsumableType
	{
		CTkill, //kills instantly
		//CTdmgovertime, //damage over time
		CTheal, //example: bandages
		CTenergize, //increases stamina to avoid having to rest
		CThydrates, //hydrates to avoid dehydration
		CTfills, //fills belly to avoid hunger
		CTdehydrates, //dehydrates someone
		CTemptys, //makes belly feel empty to starve
		CTnarcs, //de-energizes to make someone need to rest
	};
	ConsumableType type;
	int healAmt; //heal amount
	int energyAmt; //energy amount or narc amount if narc type
	int waterAmt; //hydrate/dehydrate amount
	int foodAmt; //amount to fill/empty food bar
};

struct Inventory
{
	std::vector<Item*> items;
};

}

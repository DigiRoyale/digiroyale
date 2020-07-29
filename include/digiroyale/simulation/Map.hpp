#include <vector>
#include <digiroyale/simulation/Inventory.hpp>

struct MapElement
{
	float size; //radius
	float noticeability; //distance element is visible from
};

struct Shrub : public MapElement
{
	enum ShrubType
	{
		STwildBerry, //good for food stat
		STnarcBerry, //reduces stamina
		STpowerBerry,//increases stamina
		STgushBerry, //increases water
		STpoisonBerry//kills
	};
	ShrubType type;
};

struct Tree : public MapElement
{
	float height; //height of tree extends range of ranged weapons
};

//TODO: make rivers not circles
struct River : public MapElement
{
	enum RiverType
	{
		RTfreshwater, //good for drinking and cleans off digistank
		RTdirtywater  //bad for drinking and applies more digistank
	};
	RiverType type;
};

struct Twig : public MapElement //to make fires, make loud sound when stepped on
{
	bool temp; //Ill just leave this here for now, just to diff between twig and base 
};

struct Fire : public MapElement
{
	float temp; //Ill just leave this here for now, just to diff between fire and base 
};

struct Map
{
	float size; //circle with size radius
	std::vector<Inventory> lootStashes; //[0] is cornicopia
	std::vector<MapElement*> elements;
};
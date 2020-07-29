#include "digiroyale/simulation/Inventory.hpp"
#define NOGRID //non-grid based implementation

class Survivor
{
public:
	Survivor(int trust_, int charisma_, int care_, int sneak, int shower, int strength_);
	std::string name; //please dont name yourself "@everyone"
	std::string image_url;
	Inventory inventory;
private:
	//personality stats
	int trust; //from 1-10, base stat for trust in others
	int charisma; //from 1-10, ability to make others trust you (make allies)
	int care; //from 1-10, care for others
	int crafty; //from 1-10, probability to loot Allies and make traps
	int sneaky; //from 1-10, probability to sneak or hide
	int curiousity;//from 1-10, probability to investigate where there might be people
	int destank; //from 1-10, probability to de-stank (bathe)
	int dex; //from 1-10, dexterity; ability to evade
	int strength; //from 1-10, base attack damage
	int maxWater; //5 + 10 - strength, leaner means needs less water
	int maxFood;  //5 + 10 - dexterity, bigger build means can last longer without food
	int maxEnergy;//5 + 10 - charisma, it takes energy to be charismatic
	//survivor stats
	int water; //no minimum, hydration amount  (negative means taking damage)
	int food;  //no minimum, belly full amount (negative means taking damage)
	int energy; //from 0-10, energy/stamina
	int killCount = 0;
	bool isAlive = true;
#ifdef NOGRID
	float noticeability = 1.f; //no max, ability to be noticed (noise, stank, etc.)  
	//TODO: maybe make Status Effects and put this in there
	float digistank; //distance squared of stank (0 if clean)
#endif
#ifdef GRID
	int noticeability; //no max, ability to be noticed (noise, stank, etc.)  
	int digistank; //distance squared of stank (0 if clean)
#endif
};
//things to note: 
// - survivors with higher dexterity will have lower strength and vice versa
// - trust stat also affects how closely survivor travels with allies,
//   lower trust means farther away which means group is more noticeable and thus
//   lowers survivability of group, but higher trust can make you dismiss an ally 
//   hurting you and thus lowers your individual survivability
// - Sneaky and Curiousity are inverses of each other
// - Care and crafty are inverses of each other
// - Higher charisma means you'll find it easier to convince others to be your ally, but
//	 it will lower your max energy as it takes more energy to keep their trust in you
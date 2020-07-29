#include "digiroyale/simulation/Survivor.hpp"

Survivor::Survivor(int trust_, int charisma_, int care_, int sneak,
	int shower, int strength_)
	: trust(trust_), charisma(charisma_), care(care_), crafty(10 - care_),
	sneaky(sneak), curiousity(10-sneak), destank(shower), dex(10-strength_),
	strength(strength_), maxWater(5 + 10 - strength), maxFood(5 + 10 - dex),
	maxEnergy(5 + 10 - charisma_), water(maxWater),food(maxFood),energy(maxEnergy)
{
}

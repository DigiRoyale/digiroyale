#include <random> //Mersenne Twister, uniform distribution
#include <ctime> //time
#include <type_traits> //std::is_same

namespace //hack to make sure this compiles
{
	namespace Random
	{
		// random number generator, uses 64 bit Mersenne Twister engine
		std::mt19937_64 rng{ static_cast<unsigned long long>(std::time(nullptr)) };

		template< typename T, typename U >
		auto Range(T min, U max) -> decltype(min + max)
		{
			using return_type = decltype(min + max);
			if (max < min) //fix max < min so it wont crash
			{
				return_type temp = min;
				min = max;
				max = static_cast<decltype(max)>(temp);
			}
			//to make range [min,max] for floating point numbers
			if (std::is_same<return_type, float>::value ||
				std::is_same<return_type, double>::value)
			{
				std::uniform_real_distribution<double> dist(
					min,
					std::nextafter(max, std::numeric_limits<double>::max()));
				return static_cast<return_type>(dist(rng));
			}
			//to make range [min,max] for integral numbers
			std::uniform_real_distribution<double> dist(
				min, max + 1.0);
				
			return static_cast<return_type>(dist(rng));
		}
	};
};

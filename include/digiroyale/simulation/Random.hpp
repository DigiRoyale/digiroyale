#pragma once

#include <random> //Mersenne Twister, uniform distribution
#include <ctime> //time
#include <type_traits> //std::is_same

namespace DigiRoyale
{

namespace Random
{
// random number generator, uses 64 bit Mersenne Twister engine
std::mt19937_64 rng{ static_cast<unsigned long long>(std::time(nullptr)) };

template<typename T, typename U, std::enable_if_t<std::is_floating_point_v<T>, int> = 0>
std::common_type_t<T, U> Range(T lower_bound, U upper_bound)
{
	using float_t = std::common_type_t<T, U>;

	//to make range [lower_bound, upper_bound] for floating point numbers
	std::uniform_real_distribution<float_t> dist{
		// calling min and max like this ensures that the bounds can be in the wrong order and it will still work
		std::min(float_t(lower_bound), float_t(upper_bound)),
		// we want this to be a closed interval, but std::real_distribution does a left-closed right-open interval.
		// so nextafter makes the upper bound the next representable float, so we get a closed interval.
		std::nextafter(
			std::max(float_t(lower_bound), float_t(upper_bound)),
			std::numeric_limits<float_t>::max())
	};

	return dist(rng);
}

template<typename T, typename U, std::enable_if_t<std::is_integral_v<T>, int> = 0>
std::common_type_t<T, U> Range(T lower_bound, U upper_bound)
{
	using int_t = std::common_type_t<T, U>;

	//to make range [lower_bound, upper_bound] for integral numbers
	std::uniform_int_distribution<int_t> dist{
		// calling min and max like this ensures that the bounds can be in the wrong order and it will still work
		std::min(int_t(lower_bound), int_t(upper_bound)),
		std::max(int_t(lower_bound), int_t(upper_bound))
	};

	return dist(rng);
}

}

}
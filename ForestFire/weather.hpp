#ifndef FORESTFIRE_WEATHER_HPP_
#define FORESTFIRE_WEATHER_HPP_
#pragma once
#include <string>

using namespace std;

/**
 * \brief 
 * Weather Class
 */
class Weather
{
	float burn_multiplier_;
	string condition_name_;
public:
	/**
	 * \brief 
	 * Weather Constructor
	 * \param burn_multiplier 
	 * \param condition_name 
	 */
	Weather(float burn_multiplier, string condition_name);

	/**
	 * \brief 
	 * Gets the multiplier for the weather condition
	 * \return 
	 * Returns float
	 */
	float getBurnMultiplier() const { return burn_multiplier_; }

	/**
	 * \brief 
	 * Gets the name of the weather condition
	 * \return 
	 * Returns string
	 */
	string getConditionName() const { return condition_name_; }
};
#endif // FORESTFIRE_WEATHER_HPP_
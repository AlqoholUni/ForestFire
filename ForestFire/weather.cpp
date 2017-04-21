#include "weather.hpp"
#include <string>

using namespace std;

/**
* \brief
* Weather constructor
* \param burn_multiplier
* \param condition_name
*/
Weather::Weather(float burn_multiplier, std::string condition_name)
{
	this->burn_multiplier_ = burn_multiplier;
	this->condition_name_ = condition_name;
}
#ifndef FORESTFIRE_FOREST_FIRE_HPP_
#define FORESTFIRE_FOREST_FIRE_HPP_
#pragma once
#include "tree.hpp"
#include <string>
#include "Weather.hpp"

using namespace std;

/**
 * \brief 
 * Raining Weather obj
 */
static Weather* Raining = new Weather(0.5f, "Raining");
/**
 * \brief 
 * Cold Weather obj
 */
static Weather* Cold = new Weather(0.7f, "Cold");
/**
 * \brief 
 * Pleasant Weather obj
 */
static Weather* Pleasant = new Weather(1.0f, "Pleasant");
/**
 * \brief 
 * Dry Weather obj
 */
static Weather* Dry = new Weather(1.2f, "Dry");
/**
 * \brief 
 * Hot Weather obj
 */
static Weather* Hot = new Weather(1.5f, "Hot");

/**
 * \brief 
 * ForestFire Class
 */
class ForestFire
{
	/**
	 * \brief 
	 * Center Tree Object
	 */
	Tree* center_;
	/**
	 * \brief 
	 * Chance nearby tree catches fire
	 */
	int fire_chance_;
	/**
	 * \brief 
	 * Delay between frames (ms)
	 */
	int refresh_delay_;
	/**
	 * \brief 
	 * Weather Object
	 */
	Weather* weather_;
public:
	/**
	 * \brief 
	 * Default ForestFire ctor
	 */
	ForestFire() = default;
	/**
	 * \brief 
	 * Explicit ForestFire ctor
	 * \param center 
	 */
	explicit ForestFire(Tree* center)
		: center_(center),
		  fire_chance_(0),
		  refresh_delay_(0),
		  weather_(nullptr) {}

	/**
	 * \brief 
	 * Set delay between frames (ms)
	 * \param refresh_delay 
	 * int refresh_delay
	 */
	void setRefreshDelay(int refresh_delay) { refresh_delay_ = refresh_delay; }
	/**
	 * \brief 
	 * Set chance of nearby tree catching fire
	 * \param fire_chance 
	 * int fire_chance
	 */
	void setFireChance(int fire_chance) { fire_chance_ = fire_chance; }
	/**
	 * \brief 
	 * Get chance of nearby tree catching fire
	 * \return 
	 * int fire_chance_
	 */
	int getFireChance() const { return fire_chance_; }
	/**
	 * \brief 
	 * Get delay between frames (ms)
	 * \return 
	 * int refresh_delay_
	 */
	int getRefreshDelay() const { return refresh_delay_; }

	/**
	 * \brief 
	 * Create Grid Method
	 */
	void create();
	/**
	 * \brief 
	 * Update Grid Status Method
	 */
	void update() const;
	/**
	 * \brief 
	 * Burn Grid Status Method
	 */
	void burn() const;
	/**
	 * \brief 
	 * Get Weather Status
	 */
	void getWeather();
	/**
	 * \brief 
	 * Calculate Weather Effects
	 * \return 
	 * float
	 */
	float calcWeather() const;
	/**
	 * \brief 
	 * Clears Screen
	 */
	static void clearScreen() { if (system("cls")) system("clear"); }
};

#endif // FORESTFIRE_FOREST_FIRE_HPP_
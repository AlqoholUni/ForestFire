#include "forest_fire.hpp"
#include <ctime>
#include <iostream>
#include "tree_states.hpp"

using namespace std;

/**
 * \brief 
 * Tree Map array
 */
Tree* map[20][20];

/**
 * \brief
 * Creates the initial Grid
 * Initializes a burning tree
 */
void ForestFire::create()
{
	// Gets weather status
	this->getWeather();
	// Adds neighbours to 10, 10 (center of grid)
	auto center = Tree::addNeighbours(10, 10);
	// Randomizes based on current time
	//srand(time(nullptr));
	//auto randomr = rand() % 19 + 1;
	//srand(time(nullptr));
	//auto randomc = rand() % 19 + 1;

	// Loops through all rows and columns
	for (auto r = 0; r < 21; r++)
	{
		for (auto c = 0; c < 21; c++)
		{
			// Assigns Tops and Sides
			if (r == 0 || r == 20)
				map[r][c] = new TreeTop();
			else if (c == 0 || c == 20)
				map[r][c] = new TreeSide();
			// Assigns a random starting tree that's burning
			//else if (r == randomr && c == randomc)
			//	map[r][c] = new TreeBurning();

			// Debug screen
			if (r == 8 && c == 20)
				cout << static_cast<char>(map[r][c]->getStatus()) << " " << "FIRE CHANCE: " << fire_chance_ << "%";
			else if (r == 9 && c == 20)
				cout << static_cast<char>(map[r][c]->getStatus()) << " " << "REFRESH RATE: " << refresh_delay_ << "ms";
			else if (r == 10 && c == 20)
				cout << static_cast<char>(map[r][c]->getStatus()) << " " << "WEATHER: " << weather_->getConditionName();
			else if (r == 11 && c == 20)
				cout << static_cast<char>(map[r][c]->getStatus()) << " " << "WEATHER EFFECT (BURN MULTIPLIER X FIRE CHANCE): " << weather_->getBurnMultiplier() * fire_chance_ << "%";
			else if (r == 12 && c == 20)
				cout << static_cast<char>(map[r][c]->getStatus()) << " " << "---DEBUG---";
			else if (r == 13 && c == 20)
				cout << static_cast<char>(map[r][c]->getStatus()) << " " << "REGROWTH CHANCE: " << "1/" << calcWeather() * 100;
			else if (r == 14 && c == 20)
				cout << static_cast<char>(map[r][c]->getStatus()) << " " << "RANDOM COMBUSTION CHANCE: " << "1/" << 200 * calcWeather();
			else if (r == 15 && c == 20)
				cout << static_cast<char>(map[r][c]->getStatus()) << " " << "CALC WEATHER: " << calcWeather();
			else
				cout << static_cast<char>(map[r][c]->getStatus()) << " ";
		}
		cout << endl;
	}
	//map[randomr][randomc]->setNextStatus(kTreeBurning);
}

/**
 * \brief
 * Updates Status from NextStatus
 */
void ForestFire::update() const
{
	this->clearScreen();
	this->burn();

	for (auto r = 0; r < 21; r++)
	{
		for (auto c = 0; c < 21; c++)
		{
			// Assigns Top and Sides
			if (r == 0 || r == 20)
				map[r][c] = new TreeTop();
			else if (c == 0 || c == 20)
				map[r][c] = new TreeSide();

			// Debug screen
			if (r == 8 && c == 20)
				cout << static_cast<char>(map[r][c]->getStatus()) << " " << "FIRE CHANCE: " << fire_chance_ << "%";
			else if (r == 9 && c == 20)
				cout << static_cast<char>(map[r][c]->getStatus()) << " " << "REFRESH RATE: " << refresh_delay_ << "ms";
			else if (r == 10 && c == 20)
				cout << static_cast<char>(map[r][c]->getStatus()) << " " << "WEATHER: " << weather_->getConditionName();
			else if (r == 11 && c == 20)
				cout << static_cast<char>(map[r][c]->getStatus()) << " " << "WEATHER EFFECT (BURN MULTIPLIER X FIRE CHANCE): " << weather_->getBurnMultiplier() * fire_chance_ << "%";
			else if (r == 12 && c == 20)
				cout << static_cast<char>(map[r][c]->getStatus()) << " " << "---DEBUG---";
			else if (r == 13 && c == 20)
				cout << static_cast<char>(map[r][c]->getStatus()) << " " << "REGROWTH CHANCE: " << "1/" << calcWeather() * 100;
			else if (r == 14 && c == 20)
				cout << static_cast<char>(map[r][c]->getStatus()) << " " << "RANDOM COMBUSTION CHANCE: " << "1/" << 200 * calcWeather();
			else if (r == 15 && c == 20)
				cout << static_cast<char>(map[r][c]->getStatus()) << " " << "CALC WEATHER: " << calcWeather();
			else
				cout << static_cast<char>(map[r][c]->getStatus()) << " ";
		}
		cout << endl;
	}
}

/**
 * \brief
 * Sets the NextStatus depending on the variables:
 * User input chance,
 * Random Weather
 */
void ForestFire::burn() const
{
	srand(time(nullptr));

	// Loops through all rows and columns of map
	for (auto r = 0; r < 21; r++)
	{
		for (auto c = 0; c < 21; c++)
		{
			if (map[r][c]->getStatus() == kTreeBurning)
			{
				map[r][c]->setNextStatus(kTreeEmpty);

				// Checks neighbouring Tree's status and applies next_status_
				if (map[r][c]->getNorth() != nullptr && (map[r][c]->getNorth()->getStatus() == kTreeAlive && weather_->getBurnMultiplier() * this->getFireChance() > rand() % 100 + 1))
				{
					map[r][c]->getNorth()->setNextStatus(kTreeBurning);
				}

				if (map[r][c]->getSouth() != nullptr && (map[r][c]->getSouth()->getStatus() == kTreeAlive && weather_->getBurnMultiplier() * this->getFireChance() > rand() % 100 + 1))
				{
					map[r][c]->getSouth()->setNextStatus(kTreeBurning);
				}

				if (map[r][c]->getEast() != nullptr && (map[r][c]->getEast()->getStatus() == kTreeAlive && weather_->getBurnMultiplier() * this->getFireChance() > rand() % 100 + 1))
				{
					map[r][c]->getEast()->setNextStatus(kTreeBurning);
				}

				if (map[r][c]->getWest() != nullptr && (map[r][c]->getWest()->getStatus() == kTreeAlive && weather_->getBurnMultiplier() * this->getFireChance() > rand() % 100 + 1))
				{
					map[r][c]->getWest()->setNextStatus(kTreeBurning);
				}

			}

			// Random Combustion and Regrowth
			if (map[r][c]->getStatus() == kTreeAlive && 2.f * calcWeather() >= rand() % 400 + 1.f) // Random Combustion Chance (1/200) 2/400 fixes strange glitch #BroScience
			{
				map[r][c]->setNextStatus(kTreeBurning);
			}

			if (map[r][c]->getStatus() == kTreeEmpty && 2.f / calcWeather() >= rand() % 200 + 1.f) // Random Regrowth Rate (1/100) 2/200 fixes strange glitch #BroScience
			{
				map[r][c]->setNextStatus(kTreeAlive);
			}
		}
	}

	// Assigns next_status_ to status_
	for (auto r = 0; r < 21; r++)
	{
		for (auto c = 0; c < 21; c++)
		{
			map[r][c]->setStatus(map[r][c]->getNextStatus());
		}
	}
}
/**
* \brief
* Gets Weather based off of a random number
*/
void ForestFire::getWeather()
{
	srand(time(nullptr));

	switch (rand() % 5 + 1)
	{
	case 1: weather_ = Raining;
		break;
	case 2: weather_ = Cold;
		break;
	case 3: weather_ = Pleasant;
		break;
	case 4: weather_ = Dry;
		break;
	case 5: weather_ = Hot;
		break;
	default: weather_ = nullptr;
		break;
	}
}

/**
* \brief
* Calculates the effect weather has on trees burning
* \return
* Returns burn_multiplier_
*/
float ForestFire::calcWeather() const
{
	return weather_->getBurnMultiplier();
}
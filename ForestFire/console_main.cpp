#include <Windows.h>
#include "forest_fire.hpp"
#include <iostream>

/**
 * \brief 
 * Main Event Method
 * \return 
 * int
 */
int main()
{
	// Creates new ForestFire
	auto new_fire = new ForestFire();

	new_fire->setFireChance(0);
	new_fire->setRefreshDelay(0);

	// User input catch
	while (new_fire->getFireChance() > 100 || new_fire->getFireChance() < 1)
	{
		int chance;
		cout << "Please enter a chance between 1 and 100 that a tree will catch fire: ";
		cin >> chance;
		new_fire->setFireChance(chance);

		if (system("cls"))
			system("clear");
	}

	// User input catch
	while (new_fire->getRefreshDelay() > 500 || new_fire->getRefreshDelay() < 100)
	{
		int delay;
		cout << "Please enter a delay between 100 and 500 for screen fresh (1000ms = 1 second): ";
		cin >> delay;
		new_fire->setRefreshDelay(delay);

		if (system("cls"))
			system("clear");
	}

	new_fire->clearScreen();
	// Creates new Grid
	new_fire->create();

	while (true)
	{
		// Update timer
		Sleep(new_fire->getRefreshDelay());
		new_fire->update();

		if (GetAsyncKeyState(VK_ESCAPE))
		{
			return 0;
		}
	}
}

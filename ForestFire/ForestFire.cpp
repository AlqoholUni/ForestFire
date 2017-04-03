
#include "Tree.h"
#include <cstdlib>
#include <iostream>

int main()
{
	Forest* newForest = new Forest();
	for (auto y = 21; y-- > 0;)
	{
		for (auto x = 0; x < 21; x++)
		{
			if (y == 0 || y == 20)
			{
				newForest->addTreeAtEnd(treeTop, treeTop);
			}
			else if (x == 0 || x == 20)
			{
				newForest->addTreeAtEnd(treeSide, treeSide);
			}
			else if (y == 10 && x == 10)
			{
				newForest->addTreeAtEnd(treeBurning, treeBurning);
			}
			else
			{
				newForest->addTreeAtEnd(treeAlive, treeAlive);
			}
		}
	}
	newForest->listAllTrees();

	system("pause");
	return 0;
}

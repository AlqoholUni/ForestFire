#include "forest_fire.hpp"

/**
 * \brief 
 * Tree ctor
 */
Tree::Tree(): status_(kTreeAlive),
              next_status_(kTreeAlive),
              north_(nullptr),
              south_(nullptr),
              west_(nullptr),
              east_(nullptr) { }

/**
* \brief
* Tree ctor
* \param status_
* Current eTreeStatus
* \param next_status_
* Next eTreeStatus
*/
Tree::Tree(eTreeState status_, eTreeState next_status_)
{
	this->status_ = status_;
	this->next_status_ = next_status_;
}

/**
* \brief
* Tree ctor
* \param north
* Northern Tree
* \param south
* Southern Tree
* \param west
* Western Tree
* \param east
* Eastern Tree
*/
Tree::Tree(Tree* north, Tree* south, Tree* west, Tree* east): status_(),
                                                              next_status_(),
                                                              north_(north),
                                                              south_(south),
                                                              west_(west),
                                                              east_(east) { }

/**
 * \brief 
 * Adds Neighbours to row and col
 * \param row 
 * int Row
 * \param col 
 * int Column
 * \return 
 * Tree*
 */
Tree* Tree::addNeighbours(int row, int col)
{
	// Ignore edges
	if (row > 20 || row < 0 || col > 20 || col < 0)
	{
		return nullptr;
	}
	// Skip already assigned values
	if (map[row][col] != nullptr)
	{
		return map[row][col];
	}

	// Create new Tree node
	auto node = new Tree;
	map[row][col] = node;

	// Add neighbours
	if (row > 0)
	{
		node->setNorth(addNeighbours(row - 1, col));
	}
	if (row < 20)
	{
		node->setSouth(addNeighbours(row + 1, col));
	}
	if (col > 0)
	{
		node->setWest(addNeighbours(row, col - 1));
	}
	if (col < 20)
	{
		node->setEast(addNeighbours(row, col + 1));
	}

	return node;
}

/**
 * \brief 
 * Set Tree to the East
 * \param e_tree 
 * Tree* Tree to the East
 */
void Tree::setEast(Tree * e_tree)
{
	this->east_ = e_tree;
}

/**
* \brief
* Set Tree to the West
* \param w_tree
* Tree* Tree to the West
*/
void Tree::setWest(Tree * w_tree)
{
	this->west_ = w_tree;
}

/**
* \brief
* Set Tree to the North
* \param n_tree
* Tree* Tree to the North
*/
void Tree::setNorth(Tree * n_tree)
{
	this->north_ = n_tree;
}

/**
* \brief
* Set Tree to the South
* \param s_tree
* Tree* Tree to the South
*/
void Tree::setSouth(Tree * s_tree)
{
	this->south_ = s_tree;
}

/**
 * \brief 
 * Set status_ of Tree
 * \param status 
 * eTreeState status
 */
void Tree::setStatus(eTreeState status)
{
	this->status_ = status;
}

/**
 * \brief 
 * Set next_status of Tree
 * \param next 
 * eTreeState next
 */
void Tree::setNextStatus(eTreeState next)
{
	this->next_status_ = next;
}

/**
 * \brief 
 * Get Tree East of this*
 * \return 
 * Tree*
 */
Tree * Tree::getEast() const
{
	return this->east_;
}

/**
* \brief
* Get Tree West of this*
* \return
* Tree*
*/
Tree * Tree::getWest() const
{
	return this->west_;
}

/**
* \brief
* Get Tree North of this*
* \return
* Tree*
*/
Tree * Tree::getNorth() const
{
	return this->north_;
}

/**
* \brief
* Get Tree South of this*
* \return
* Tree*
*/
Tree * Tree::getSouth() const
{
	return this->south_;
}

/**
 * \brief 
 * Get status_ of this*
 * \return 
 * eTreeState
 */
eTreeState Tree::getStatus() const
{
	if (this->status_ == kTreeTop)
		return kTreeTop;
	if (this->status_ == kTreeSide)
		return kTreeSide;
	if (this->status_ == kTreeAlive)
		return kTreeAlive;
	if (this->status_ == kTreeBurning)
		return kTreeBurning;
	if (this->status_ == kTreeEmpty)
		return kTreeEmpty;
	return kTreeAlive;
}

/**
 * \brief 
 * Get next_status_ of this*
 * \return 
 * eTreeStatus
 */
eTreeState Tree::getNextStatus() const
{
	if (this->next_status_ == kTreeTop)
		return kTreeTop;
	if (this->next_status_ == kTreeSide)
		return kTreeSide;
	if (this->next_status_ == kTreeAlive)
		return kTreeAlive;
	if (this->next_status_ == kTreeBurning)
		return kTreeBurning;
	if (this->next_status_ == kTreeEmpty)
		return kTreeEmpty;
	return kTreeAlive;
}

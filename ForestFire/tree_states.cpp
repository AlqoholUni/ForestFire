#include "tree_states.hpp"

/**
* \brief
* TreeTop ctor
*/
TreeTop::TreeTop() 
{
	this->setStatus(kTreeTop);
	this->setNextStatus(kTreeTop);
}

/**
* \brief
* TreeSide ctor
*/
TreeSide::TreeSide()
{
	this->setStatus(kTreeSide);
	this->setNextStatus(kTreeSide);
}

/**
* \brief
* TreeAlive ctor
*/
TreeAlive::TreeAlive()
{
	this->setStatus(kTreeAlive);
	this->setNextStatus(kTreeAlive);
}

/**
* \brief
* TreeBurning ctor
*/
TreeBurning::TreeBurning()
{
	this->setStatus(kTreeBurning);
	this->setNextStatus(kTreeEmpty);
}

/**
* \brief
* TreeEmpty ctor
*/
TreeEmpty::TreeEmpty()
{
	this->setStatus(kTreeEmpty);
	this->setNextStatus(kTreeEmpty);
}

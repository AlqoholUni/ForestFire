#ifndef FORESTFIRE_TREE_STATES_HPP_
#define FORESTFIRE_TREE_STATES_HPP_
#pragma once
#include "tree.hpp"

/**
 * \brief 
 * TreeTop Class
 */
class TreeTop : public Tree
{
public:
	/**
	 * \brief 
	 * TreeTop ctor
	 */
	TreeTop();
};

/**
 * \brief 
 * TreeSide Class
 */
class TreeSide : public Tree
{
public:
	/**
	 * \brief 
	 * TreeSide ctor
	 */
	TreeSide();
};

/**
 * \brief 
 * TreeAlive Class
 */
class TreeAlive : public Tree
{
public:
	/**
	 * \brief 
	 * TreeAlive ctor
	 */
	TreeAlive();
};

/**
 * \brief 
 * TreeBurning Class
 */
class TreeBurning : public Tree
{
public:
	/**
	 * \brief 
	 * TreeBurning ctor
	 */
	TreeBurning();
};

/**
 * \brief 
 * TreeEmpty Class
 */
class TreeEmpty : public Tree
{
public:
	/**
	 * \brief 
	 * TreeEmpty ctor
	 */
	TreeEmpty();
};

#endif // FORESTFIRE_TREE_STATES_HPP_
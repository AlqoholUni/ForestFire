#ifndef FORESTFIRE_TREE_HPP_
#define FORESTFIRE_TREE_HPP_
#pragma once

/**
 * \brief 
 * eTreeState enum : char
 */
enum eTreeState : char
{
	kTreeTop = '-',
	kTreeSide = '|',
	kTreeAlive = '^',
	kTreeBurning = 'X',
	kTreeEmpty = '.'
};

/**
 * \brief 
 * Tree struct
 */
struct Tree
{
private:
	/**
	 * \brief 
	 * Current Tree State
	 */
	eTreeState status_;
	/**
	 * \brief 
	 * Tree State in next frame
	 */
	eTreeState next_status_;

	/**
	 * \brief 
	 * Northern Tree
	 */
	Tree* north_;
	/**
	 * \brief 
	 * Southern Tree
	 */
	Tree* south_;
	/**
	 * \brief 
	 * Western Tree
	 */
	Tree* west_;
	/**
	 * \brief 
	 * Eastern Tree
	 */
	Tree* east_;

public:
	/**
	 * \brief 
	 * Tree ctor
	 */
	Tree();

	/**
	 * \brief 
	 * Tree ctor
	 * \param status_ 
	 * Current eTreeStatus
	 * \param next_status_ 
	 * Next eTreeStatus
	 */
	Tree(eTreeState status_, eTreeState next_status_);

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
	Tree(Tree* north, Tree* south, Tree* west, Tree* east);

	/**
	 * \brief 
	 * Adds neighbouring trees to center point
	 * \return 
	 * Tree*
	 */
	static Tree* addNeighbours(int, int);

	/**
	* \brief
	* Set Tree to the East
	* \param e_tree
	* Tree* Tree to the East
	*/
	void setEast(Tree* e_tree);
	/**
	* \brief
	* Set Tree to the West
	* \param w_tree
	* Tree* Tree to the West
	*/
	void setWest(Tree* w_tree);
	/**
	* \brief
	* Set Tree to the North
	* \param n_tree
	* Tree* Tree to the North
	*/
	void setNorth(Tree* n_tree);
	/**
	* \brief
	* Set Tree to the South
	* \param s_tree
	* Tree* Tree to the South
	*/
	void setSouth(Tree* s_tree);

	/**
	* \brief
	* Set status_ of Tree
	* \param status
	* eTreeState status
	*/
	void setStatus(eTreeState status);
	/**
	* \brief
	* Set next_status of Tree
	* \param next
	* eTreeState next
	*/
	void setNextStatus(eTreeState next);

	/**
	* \brief
	* Get Tree East of this*
	* \return
	* Tree*
	*/
	Tree* getEast() const;
	/**
	* \brief
	* Get Tree West of this*
	* \return
	* Tree*
	*/
	Tree* getWest() const;
	/**
	* \brief
	* Get Tree North of this*
	* \return
	* Tree*
	*/
	Tree* getNorth() const;
	/**
	* \brief
	* Get Tree South of this*
	* \return
	* Tree*
	*/
	Tree* getSouth() const;

	/**
	* \brief
	* Get status_ of this*
	* \return
	* eTreeState
	*/
	eTreeState getStatus() const;
	/**
	* \brief
	* Get next_status_ of this*
	* \return
	* eTreeStatus
	*/
	eTreeState getNextStatus() const;
};

extern Tree* map[20][20];

#endif // FORESTFIRE_TREE_HPP_
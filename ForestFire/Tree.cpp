#include "Tree.h"
#include <iostream>
#include <windows.h>

using namespace std;

Tree::Tree()
{
	status_ = treeAlive;
	next_ = treeAlive;
	left_ = nullptr;
	right_ = nullptr;
	up_ = nullptr;
	down_ = nullptr;
}

Tree::Tree(TreeStatus status, TreeStatus next)
{
	status_ = status;
	next_ = next;
	left_ = nullptr;
	right_ = nullptr;
	up_ = nullptr;
	down_ = nullptr;
}

void Tree::setLeft(Tree* left)
{
	left_ = left;
}

void Tree::setUp(Tree * up)
{
	up_ = up;
}

void Tree::setDown(Tree * down)
{
	down_ = down;
}

Tree * Tree::getRight() const {
	return right_;
}

Tree * Tree::getLeft() const {
	return left_;
}

Tree * Tree::getUp() const {
	return up_;
}

Tree * Tree::getDown() const {
	return down_;
}

TreeStatus Tree::getStatus() const {
	return status_;
}

TreeStatus Tree::getNext() const {
	return next_;
}


void Tree::setRight(Tree* right)
{
	right_ = right;
}

Forest::Forest()
{
	start = nullptr;
	end = nullptr;
}

bool Forest::isEmpty() const {
	return start == nullptr;
}

void Forest::addFirstTree()
{
	Tree* current;
	current = new Tree(treeTop, treeTop);
	start = current;
	end = current;
}

void Forest::addTreeAtEnd(TreeStatus status, TreeStatus next)
{
	Tree* current;
	if (end == nullptr)
		addFirstTree();
	else
	{
		current = new Tree(status, next);
		end->setRight(current);
		end = current;
	}
}

void Forest::listAllTrees() const
{
	Tree* current;
	auto count = 0;
	if (!isEmpty())
	{
		current = start;
		while (current != nullptr)
		{
			count++;
			cout << static_cast<char>(current->getStatus()) << " ";
			current = current->getRight();
			if (count % 21 == 0)
				cout << endl;
		}
	}
}

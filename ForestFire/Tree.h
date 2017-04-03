#pragma once

enum TreeStatus : char
{
	treeTop = '-',
	treeSide = '|',
	treeAlive = '^',
	treeBurning = 'X',
	treeEmpty = '.'
};

struct Tree
{
private:
	TreeStatus status_;
	TreeStatus next_;

	Tree* left_;
	Tree* right_;
	Tree* up_;
	Tree* down_;

public:
	Tree();
	Tree(TreeStatus status, TreeStatus next);

	void setRight(Tree* right);
	void setLeft(Tree* left);
	void setUp(Tree* up);
	void setDown(Tree* down);

	Tree* getRight() const;
	Tree* getLeft() const;
	Tree* getUp() const;
	Tree* getDown() const;

	TreeStatus getStatus() const;
	TreeStatus getNext() const;
};

struct Forest
{
private:
	Tree* start;
	Tree* end;

public:
	Forest();

	bool isEmpty() const;

	void addFirstTree();
	void addTreeAtEnd(TreeStatus status, TreeStatus next);
	void listAllTrees() const;
};

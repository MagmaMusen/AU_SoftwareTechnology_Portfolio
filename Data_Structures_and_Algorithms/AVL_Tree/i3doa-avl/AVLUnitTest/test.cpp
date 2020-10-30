#include "pch.h"
#include "../AVL/avl.h"


using namespace AVL;

enum Side {LEFT, RIGHT};

void connect(avlNode<int>* parent, avlNode<int>* child, Side side)
{
	if(side == LEFT) parent->left = child;
	else parent->right = child;
	child->parent = parent;
}

TEST(AVL, UpdateBalanceFactor_Nullptr_ExceptionThrown)
{
	avlNode<int>* root = nullptr;
	ASSERT_THROW(
		updateBalanceFactors(root),
		std::invalid_argument
		);

}


TEST(AVL, UpdateBalanceFactor_Root_NoUpdateNeeded) 
{
	avlNode<int>* root = new avlNode<int>();
	avlNode<int>* retVal = updateBalanceFactors(root);
	ASSERT_EQ(retVal, nullptr);
	ASSERT_EQ(root->balanceFactor, 0);
}


TEST(AVL, UpdateBalanceFactor_NewNodeLeft_NoImbalance)
{
	avlNode<int>* root = new avlNode<int>();
	avlNode<int>* child = new avlNode<int>();
	connect(root, child, LEFT);

	avlNode<int>* retVal = updateBalanceFactors(child);
	ASSERT_EQ(retVal, nullptr);
	ASSERT_EQ(root->balanceFactor, -1);

}


TEST(AVL, UpdateBalanceFactor_NewNodeRight_NoImbalance)
{
	avlNode<int>* root = new avlNode<int>();
	avlNode<int>* child = new avlNode<int>();
	connect(root, child, RIGHT);

	avlNode<int>* retVal = updateBalanceFactors(child);
	ASSERT_EQ(retVal, nullptr);
	ASSERT_EQ(root->balanceFactor, 1);
}


TEST(AVL, UpdateBalanceFactor_NewNodesLeftThenRight_RootImbalanceCorrect)
{
	avlNode<int>* root = new avlNode<int>();
	avlNode<int>* rightChild = new avlNode<int>();
	avlNode<int>* leftChild = new avlNode<int>();
	
	connect(root, leftChild, LEFT);		
	updateBalanceFactors(leftChild);
	
	connect(root, rightChild, RIGHT);	
	avlNode<int>* retVal = updateBalanceFactors(rightChild);
	
	ASSERT_EQ(nullptr, retVal);
	ASSERT_EQ(root->balanceFactor, 0);
	ASSERT_EQ(leftChild->balanceFactor, 0);
	ASSERT_EQ(rightChild->balanceFactor, 0);
}


TEST(AVL, UpdateBalanceFactor_NewNodesRightThenLeft_RootImbalanceCorrect)
{
	avlNode<int>* root = new avlNode<int>();
	avlNode<int>* rightChild = new avlNode<int>();
	avlNode<int>* leftChild = new avlNode<int>();

	connect(root, rightChild, RIGHT);
	updateBalanceFactors(rightChild);

	connect(root, leftChild, LEFT);
	avlNode<int>* retVal = updateBalanceFactors(leftChild);

	ASSERT_EQ(nullptr, retVal);
	ASSERT_EQ(root->balanceFactor, 0);
	ASSERT_EQ(leftChild->balanceFactor, 0);
	ASSERT_EQ(rightChild->balanceFactor, 0);
}

TEST(AVL, UpdateBalanceFactor_RightRightImbalance_RootImbalanceCorrect)
{
	avlNode<int>* root = new avlNode<int>();
	avlNode<int>* child = new avlNode<int>();
	avlNode<int>* grandChild = new avlNode<int>();
	connect(root, child, RIGHT); 
	updateBalanceFactors(child);

	connect(child, grandChild, RIGHT);

	avlNode<int>* retVal = updateBalanceFactors(grandChild);
	ASSERT_EQ(root, retVal);
	ASSERT_EQ(root->balanceFactor, 2);
	ASSERT_EQ(child->balanceFactor, 1);
	ASSERT_EQ(grandChild->balanceFactor, 0);
}

TEST(AVL, UpdateBalanceFactor_LeftLeftImbalance_RootImbalanceCorrect)
{
	avlNode<int>* root = new avlNode<int>();
	avlNode<int>* child = new avlNode<int>();
	avlNode<int>* grandChild = new avlNode<int>();
	connect(root, child, LEFT);
	updateBalanceFactors(child);

	connect(child, grandChild, LEFT);

	avlNode<int>* retVal = updateBalanceFactors(grandChild);
	ASSERT_EQ(root, retVal);
	ASSERT_EQ(root->balanceFactor, -2);
	ASSERT_EQ(child->balanceFactor, -1);
	ASSERT_EQ(grandChild->balanceFactor, 0);
}


TEST(AVL, UpdateBalanceFactor_LeftRightImbalance_RootImbalanceCorrect)
{
	avlNode<int>* root = new avlNode<int>();
	avlNode<int>* child = new avlNode<int>();
	avlNode<int>* grandChild = new avlNode<int>();
	connect(root, child, RIGHT);
	updateBalanceFactors(child);

	connect(child, grandChild, LEFT);

	avlNode<int>* retVal = updateBalanceFactors(grandChild);
	ASSERT_EQ(root, retVal);
	ASSERT_EQ(root->balanceFactor, 2);
	ASSERT_EQ(child->balanceFactor, -1);
	ASSERT_EQ(grandChild->balanceFactor, 0);
}


TEST(AVL, UpdateBalanceFactor_RightLeftImbalance_RootImbalanceCorrect)
{
	avlNode<int>* root = new avlNode<int>();
	avlNode<int>* child = new avlNode<int>();
	avlNode<int>* grandChild = new avlNode<int>();
	connect(root, child, LEFT);
	updateBalanceFactors(child);

	connect(child, grandChild, RIGHT);

	avlNode<int>* retVal = updateBalanceFactors(grandChild);
	ASSERT_EQ(root, retVal);
	ASSERT_EQ(root->balanceFactor, -2);
	ASSERT_EQ(child->balanceFactor, 1);
	ASSERT_EQ(grandChild->balanceFactor, 0);
}


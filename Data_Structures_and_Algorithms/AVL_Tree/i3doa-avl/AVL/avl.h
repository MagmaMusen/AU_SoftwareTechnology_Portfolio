#pragma once
#include <stdexcept>

namespace AVL
{
	template<typename T>
	class avlNode
	{
		public:
			avlNode<T>* parent;
			avlNode<T>* left;
			avlNode<T>* right;
			T data;
			int balanceFactor;

			avlNode(const T& d = T(), avlNode<T>* p = nullptr, avlNode<T>* l = nullptr, avlNode<T>* r = nullptr, int bf = 0)
				:data(d), parent(p), left(l), right(r), balanceFactor(bf)
			{}
	};



	template<typename T>
	bool search(avlNode<T>* root, const T& data)
	{
		if (root == nullptr) return false;
		if (root->data == data) return true;
		if (data <= root->data) return search(root->left, data);
		return search(root->right, data);
	}


	// avlNode<T>* updateBalanceFactors(avlNode<T>* node)
	// Arguments:	node:	A recently inserted leaf node at which to start balance updating
	// Returns:		If a node is found from node to root which needs to be rebalanced, a pointer to this node is returned.
	//				If no such node is found, nullptr is returned
	template<typename T>
	avlNode<T>* updateBalanceFactors(avlNode<T>* node)
	{
		if (node == nullptr) throw std::invalid_argument("node = nullptr");
		
		avlNode<T>* parent = node->parent;
		if(parent == nullptr)
		{
			node->balanceFactor = 0;
			return nullptr;
		}

		if (parent->left == node)		// Parents left subtree just got deeper
			--parent->balanceFactor;
		else							// Parents right subtree just got deeper
			++parent->balanceFactor;

		while (parent->parent != nullptr && parent->balanceFactor > -2 && parent->balanceFactor < 2)
		{
			node = parent;
			parent = node->parent;
			if (node->balanceFactor == 0) return nullptr;	// No rebalancing needed here or above

			if (parent->left == node)		// Parents left subtree just got deeper
				--parent->balanceFactor;
			else							// Parents right subtree just got deeper
				++parent->balanceFactor;
		}

		if (parent->balanceFactor < -1 || parent->balanceFactor > 1)	// parent out of balance
		{
			return parent;
		}
		return nullptr;
	}

}



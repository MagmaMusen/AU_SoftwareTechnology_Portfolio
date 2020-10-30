#pragma once

template<typename T>
class BST
{
private:
	template<typename T>
	class Node
	{
	public:
		Node(const T& _data = T(), Node<T>* l = nullptr, Node<T>* r = nullptr, Node<T>* p = nullptr) 
		: data(_data), left(l), right(r), parent(p)
		{}
		
		T data;
		Node<T>* parent;
		Node<T>* left;
		Node<T>* right;
	};

	Node<T>* root;

	Node<T>* find(Node<T>* root, const T& data)
	{
		if (root == nullptr) return nullptr;
		if (root->data == data) return root;
		if (data <= root->data) return find(root->left, data);
		return find(root->right, data);
	}

public:
	BST() : root(nullptr)
	{
	}


	bool search(const T& data)
	{
		return find(root, data) != nullptr;
	}

	
	void insert(const T& data)
	{
		// Special case: Root is null - insert data
		if (root == nullptr)
		{
			root = new Node<T>(data);
			return;
		}

		// (1) Find leaf-place to insert new node
		Node<T>* cursor = root;
		
		while (true)
		{
			if (data <= cursor->data)
			{
				if (cursor->left == nullptr)	// Cursor->left is leaf -> insert new node here
				{
					cursor->left = new Node<T>(data);
					cursor->left->parent = cursor;
					return;
				}
				else
				{
					cursor = cursor->left;		// cursor->left is non-leaf -> continue search in left subtree
				}
			}
			else
			{
				if (cursor->right == nullptr)	// Cursor->right is leaf -> insert new node here
				{
					cursor->right = new Node<T>(data);
					cursor->right->parent = cursor;
					return;
				}
				else
					cursor = cursor->right;		// cursor->right is non-leaf -> continue search in right subtree
			}
		}
	}


	
	void remove(const T& data)
	{
		// Find node to remove
		Node<T>* cursor = find(root, data);
		if (cursor == nullptr) return;


		// INV: cursor points to node to remove.
		if (cursor->left == nullptr && cursor->right == nullptr)// Cursor points to a leaf
		{
			if (cursor == root) root = nullptr;	// Removing last node in tree - update root
			else
			{
				// cursor points to non-root leaf - update parent
				if (cursor->parent->right == cursor) cursor->parent->right = nullptr;
				else cursor->parent->left = nullptr;
			}

			// Delete node and return
			delete cursor;
			return;
		}

		// INV: cursor points to node to remove, and cursor is non-leaf
		// Find node to substitute cursor
		if (cursor->left == nullptr) // Cursor has empty left sub-tree
		{
			if (cursor == root) // cursor points to root - Update root to point to own right subtree
			{
				root = root->right;
				if(root->right != nullptr) root->right->parent = root;
				root->parent = nullptr;
			}
			// Cursor is non-root - connect parent's relevant subtree to cursor's right subtree 
			else if (cursor->parent->right == cursor)
			{
				cursor->parent->right = cursor->right;	// We are in the RIGHT subtree of cursor's parent - connect parent's RIGHT subtree to cursor's right subtree
				cursor->right->parent = cursor->parent;
			}
			else
			{
				cursor->parent->left = cursor->right;		// We are in the LEFT subtree of cursor's parent - connect parent's LEFT subtree to cursor's right subtree
				cursor->right->parent = cursor->parent;
			}
			delete cursor;								// Remove node and return
			return;
		}
		
		if(cursor->right == nullptr)// Cursor has empty right sub-tree
		{
			if(cursor == root)
			{
				root = root->left;
				if(root->left != nullptr) root->left->parent = root;
				root->parent = nullptr;
			}
			// cursor is non-root and has empty right subtree
			// Cursor is non-root - connect parent's relevant subtree to cursor's left subtree 
			else if (cursor->parent->right == cursor)
			{
				cursor->parent->right = cursor->left;	// We are in the RIGHT subtree of cursor's parent - connect parent's RIGHT subtree to cursor's left subtree
				cursor->left->parent = cursor->parent;
			}
			else
			{
				cursor->parent->left = cursor->left;		// We are in the LEFT subtree of cursor's parent - connect parent's LEFT subtree to cursor's left subtree
				cursor->left->parent = cursor->parent;
			}
			delete cursor;								// Remove node
			return;
		}


		// INV: cursor points to node to remove, and cursor has two non-empty subtrees
		// Find node to substitute (greatest in left subtree)
		Node<T>* substitute = cursor->left;
	
		while (substitute->right != nullptr)
			substitute = substitute->right;

		
		// INV: substitute points to node that will substitute cursor.
		if (substitute->parent == cursor)	// Substitute is left child of cursor - special wiring-in necessary 
		{
			substitute->right = cursor->right;
			substitute->parent = cursor->parent;
		}

		else	// Substitute is not left child of cursor - regular wiring-in
		{
			// Connect parent->right to left subtree of substitute
			substitute->parent->right = substitute->left;

			// "Wire in" substitute at cursor's position
			substitute->left = cursor->left;
			substitute->right = cursor->right;
			substitute->parent = cursor->parent;
		}
	
		if (cursor->parent == nullptr)
		{
			// cursor is at root - update root
			root = substitute;
		}
		else
		{
			// cursor is not at root - update cursor's parent
			if (cursor->data > cursor->parent->data) cursor->parent->right = substitute;
			else cursor->parent->left = substitute;
		}

		// Substitution complete - remove cursor
		delete cursor;
	}
};
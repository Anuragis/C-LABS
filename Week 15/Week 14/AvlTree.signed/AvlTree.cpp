#include <iostream>
#include <chrono>
#include "AvlTree.h"

using namespace std;
using namespace std::chrono;

/**
 * Default constructor.
 */
AvlTree::AvlTree()
    : BinarySearchTree()
{
}

/**
 * Destructor.
 */
AvlTree::~AvlTree()
{
}

/**
 * Private method to compute the height of a subtree.
 * Overrides the base class method.
 * @param ptr pointer to the root node of the subtree.
 * @return the height of the subtree.
 */
int AvlTree::height(const BinaryNode *ptr) const
{
    return ptr == nullptr ? -1 : ptr->height;
}

/**
 * Private method to insert a data item into a subtree
 * and set the new root of the subtree.
 * Overrides the base class method.
 * @param data the data to insert.
 * @param ptr pointer to the root node of the subtree.
 */
void AvlTree::insert(const long data, BinaryNode* &ptr)
{
    BinarySearchTree::insert(data, ptr);
    rebalance(ptr);
}

/**
 * Private method to remove a data item from a subtree
 * and set the new root node of the subtree.
 * Do nothing if the data item is not found.
 * Overrides the base class method.
 * @param data the data to remove.
 * @param ptr pointer to the root node of the subtree.
 */
void AvlTree::remove(const long data, BinaryNode* &ptr)
{
    BinarySearchTree::remove(data, ptr);
    rebalance(ptr);
}

/**
 * Private method to balance the tree.
 * @param ptr pointer to the node to balance.
 * @return pointer to the balanced node.
 */
BinaryNode *AvlTree::rebalance(BinaryNode* &ptr)
{
    if (ptr == nullptr) return ptr;

    // Left side too high.
    if (height(ptr->left) - height(ptr->right) > 1)
    {
    	//insert_probe_count++;
        if (height(ptr->left->left) >= height(ptr->left->right))
        {
        	//insert_probe_count++;
            ptr = singleRightRotation(ptr);
          //  cout << "    --- Single right rotation at node "
            //     << ptr->data << endl;
        }
        else
        {

            ptr = doubleLeftRightRotation(ptr);
           // cout << "    --- Double left-right rotation at node "
            //     << ptr->data << endl;
        }
    }

    // Right side too high.
    else if (height(ptr->right) - height(ptr->left) > 1)
    {
    //	insert_probe_count++;
        if (height(ptr->right->right) >= height(ptr->right->left))
        {
            ptr = singleLeftRotation(ptr);
          //  cout << "    --- Single left rotation at node "
          //       << ptr->data << endl;
        }
        else
        {

       // 	insert_probe_count++;
            ptr = doubleRightLeftRotation(ptr);
          //  cout << "    --- Double right-left rotation at node "
           //      << ptr->data << endl;
        }
    }

    // Recompute the node's height.
    ptr->height = (max(height(ptr->left),
                       height(ptr->right)) + 1);

    if (checkBalance(ptr) < 0)
    {
    //	insert_probe_count++;
      //  cout << endl << "***** Tree unbalanced!" << endl;
    }

    return ptr;
}

/**
 * Case 1 (outside left-left): Rebalance with a single right rotation.
 * Update heights and return the new root node.
 * @param k2 pointer to the node to rotate.
 * @return pointer to the new root node.
 */
BinaryNode *AvlTree::singleRightRotation(BinaryNode *k2)
{
	steady_clock::time_point start_time =steady_clock::now();
//	insert_probe_count++;
//insert_probe_count++;

		BinaryNode *temp = k2->left;
		BinaryNode *T2 = temp->right;

	    // Perform rotation
	    temp->right = k2;
	    k2->left = T2;

	    // Update heights
	    k2->height = max(height(k2->left), height(k2->right))+1;
	    temp->height = max(height(temp->left), height(temp->right))+1;

	    // Return new root
	    return temp;

	    /**	steady_clock::time_point end_time = steady_clock::now();
	        long elapsed_time = duration_cast<milliseconds>(end_time - start_time).count();
	        increment_elapsed_time(elapsed_time);*/

}

/**
 * Case 2 (inside left-right): Rebalance with a double left-right rotation.
 * @param k3 pointer to the node to rotate.
 * @return pointer to the new root node.
 */
BinaryNode *AvlTree::doubleLeftRightRotation(BinaryNode *k3)
{
	steady_clock::time_point start_time =steady_clock::now();
//	insert_probe_count++;
//	insert_probe_count++;
		BinaryNode *temp;
	    temp = k3->left;
	    k3->left = singleLeftRotation(temp);
	    return singleRightRotation(k3);

	   /** steady_clock::time_point end_time = steady_clock::now();
	    	        long elapsed_time = duration_cast<milliseconds>(end_time - start_time).count();
	    	        increment_elapsed_time(elapsed_time);*/
}

/**
 * Case 3 (inside right-left): Rebalance with a double left rotation.
 * @param k1 pointer to the node to rotate.
 * @return pointer to the new root node.
 */
BinaryNode *AvlTree::doubleRightLeftRotation(BinaryNode *k1)
{
	steady_clock::time_point start_time =steady_clock::now();
//	insert_probe_count++;
//	insert_probe_count++;
		BinaryNode *temp;
	    temp = k1->right;
	    k1->right = singleRightRotation(temp);
	    return singleLeftRotation(k1);

	  /**  steady_clock::time_point end_time = steady_clock::now();
	    	    	        long elapsed_time = duration_cast<milliseconds>(end_time - start_time).count();
	    	    	        increment_elapsed_time(elapsed_time);*/
}

/**
 * Case 4 (outside right-right): Rebalance with a single left rotation.
 * Update heights and return the new root node.
 * @param k2 pointer to the node to rotate.
 * @return pointer to the new root node.
 */
BinaryNode *AvlTree::singleLeftRotation(BinaryNode *k1)
{
	steady_clock::time_point start_time =steady_clock::now();
//	insert_probe_count++;
//insert_probe_count++;

	BinaryNode *y = k1->right;
	BinaryNode *T2 = y->left;

	    // Perform rotation
	    y->left = k1;
	    k1->right = T2;

	    //  Update heights
	    k1->height= max(height(k1->left), height(k1->right))+1;
	    y->height = max(height(y->left), height(y->right))+1;

	    // Return new root
	    return y;

	  /**  steady_clock::time_point end_time = steady_clock::now();
	    	        long elapsed_time = duration_cast<milliseconds>(end_time - start_time).count();
	    	        increment_elapsed_time(elapsed_time);*/
}

/**
 * Private method for a paranoid check of whether a tree node is balanced.
 * @param ptr pointer to the node to check.
 * @return the height of the node if balanced, -1 if the node is null,
 *         or -2 if unbalanced.
 */
int AvlTree::checkBalance(BinaryNode *ptr)
{
//	insert_probe_count=insert_probe_count+2;
    if (ptr == nullptr) return -1;


    int leftHeight  = checkBalance(ptr->left);
    int rightHeight = checkBalance(ptr->right);

    if ((abs(height(ptr->left) - height(ptr->right)) > 1)
        || (height(ptr->left)  != leftHeight)
        || (height(ptr->right) != rightHeight))
    {
        return -2;       // unbalanced
    }

    return height(ptr);  // balanced
}

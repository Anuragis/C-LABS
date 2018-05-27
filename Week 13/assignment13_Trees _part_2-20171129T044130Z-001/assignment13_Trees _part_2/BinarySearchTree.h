/**
 * An implementation of the binary search tree and its operations.
 */

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <string>
#include "BinaryNode.h"

using namespace std;

class BinarySearchTree
{
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree& rhs);
    virtual ~BinarySearchTree();

    BinaryNode *getRoot() const;
    int height() const;
    int findMin() const throw(string);
    int findMax() const throw(string);

    void clear();
    bool isEmpty() const;
    bool contains(const int data) const;
    void insert(const int data);
    void remove(const int data);

    static int get_insert_probe_count();
    static int get_search_probe_count();
    static int get_insert_comparison_count();
    static int get_search_comparison_count();
    static void reset();
    void reset_elapsed_time();
    long get_elapsed_time() const;

protected:
    virtual int height(const BinaryNode *ptr) const;
    virtual void insert(const int data, BinaryNode* &ptr);
    virtual void remove(const int data, BinaryNode* &ptr);

    	static int insert_probe_count;
        static int search_probe_count;
        static int insert_comparison_count;
        static int search_comparison_count;
        void increment_elapsed_time(long milsec);
        long elapsed_time;

private:
    BinaryNode *root;



    BinaryNode *findMin(BinaryNode *ptr) const;
    BinaryNode *findMax(BinaryNode *ptr) const;
    void clear(BinaryNode* &ptr);
    bool contains(const int data, BinaryNode *ptr) const;
};


#endif // BINARY_TREE_CHECKER_H

/**
 * @file    BinarySearchTree.h
 * @brief   This is a class specification file for a BinarySearchTree class.
 *
 * @author  Daiki Itoh
 * @date    10/2/2018
 */
#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE
#include <iostream>
using std::ostream;
#include "Node.h"

class BinarySearchTree
{
    public:
        BinarySearchTree() = default;
        void add(const int& new_data);
        void BFS(ostream& strm) const;
        void DFS(ostream& strm) const;
        void erase_recursively();
        ~BinarySearchTree() { erase_recursively(); };
    private:                 
        void erase_recursively(Node* current_toot);
        Node* root = nullptr;
};

#endif

/**
 * @file    BinarySearchTree.cpp
 * @brief   This is a class implementation file for a BinarySearchTree class.
 *
 * It contains necessary methods to add, display, erase nodes.
 *
 * @author  Daiki Itoh
 * @date    10/2/2018
 */
#include <iostream>
using std::ostream;
#include <stack>
using std::stack;
#include <queue>
using std::queue;
#include "BinarySearchTree.h"

/**
 * @brief     Mutator. It adds a node iteratively to a tree.
 *
 * @param     new_city     It holds an object of CityStateZip.
 */
void BinarySearchTree::add(const int& new_data)
{
    //Create a new node with new_city.
    Node* new_node = new Node{new_data};
    //If there is no node in the list, point root to the new node.
    if(!root)
    {
        root = new_node;
    }
    //Otherwise, it does the following.
    else
    {
        //Create a pointer that points to root.
        Node* current = root;
        //added determines if the new node is added to the tree or not.
        bool added = false;
        //Until the new node is added, it loops.
        while(!added)
        {
            if(*new_node < *current)
            {
                //If left branch is nullptr, then add the new node there
                //and set added to true.
                if(current->get_left() == nullptr)
                { 
                    current->set_left(new_node);
                    added = true;
                }//End if 
                else//Left branch is not nullptr.
                {
                    //Go to left.
                    current = current->get_left();
                }
            }
            else//*new_node > *current
            {
                //If right branch is nullptr, then add the new node there
                //and set added to true.
                if (current->get_right() == nullptr)
                {
                    current->set_right(new_node);
                    added = true;
                } //end if
                else//Right branch is not nullptr
                {
                    //Go to right.
                    current = current->get_right();
                }
            }
        }
    }
}

/**
 * @brief     It writes nodes in breadth first search.
 *
 * @param     strm     It holds an object of ostream.
 */
void BinarySearchTree::BFS(ostream& strm) const
{
    if(root) // there are nodes at least
    {
        Node* current = root;
        queue<Node*> root_queue;
        bool done = false; // assume work to be done
        
        strm << *current << '\n';
        
        while(current && !done)
        {
            if(current->get_left())
            {
                // store the information on left and display it
                root_queue.push(current->get_left());
                strm << *(current->get_left()) << '\n';
            }
            if(current->get_right())
            {
                // store the information on right and display it 
                root_queue.push(current->get_right());
                strm << *(current->get_right()) << '\n';
            }
            if(!root_queue.empty())
            {
                // get back to the node at the front of queue
                current = root_queue.front();
                root_queue.pop();
            }
            else // queue == empty
            {
                done = true; // finish loop
            }
        }
    }
}


/**
 * @brief     It writes nodes in depth first search.
 *
 * @param     strm     It holds an object of ostream.
 */
void BinarySearchTree::DFS(ostream& strm) const
{
    //If there is no node in the tree, it doesn't do anything.
    if(root)
    {
        //Create and point current to root.
        Node* current = root;
        //Use std::stack from STL to store each current pointer.
        stack<Node*> root_stack;
        //done is set to true when left is nullptr or right is nullptr.
        //It distinguishes if these actions are taken or not. finished marks
        //the end of iteration.
        bool done = false, finished = false;
        //It loops until it writes the last node in the tree.
        while(current && !finished)
        {
            //It goes to left until nullptr is encountered.
            if(current->get_left() && !done)
            {
                //Before each replacement, push each current to stack.
                root_stack.push(current);
                //Go left.
                current = current->get_left();
            }
            //In the case that left is nullptr.
            else if(!current->get_left() && !done)
            {
                //Display the node's data.
                strm << *current << '\n';
                //Set done to ture since this action is taken.
                done = true;
                //If it can go to right, go right.
                if(current->get_right())
                {
                    current = current->get_right();
                    //Set done to false so that it allows traversal to left
                    //again.
                    done = false;
                }
            }
            //When there is no item in the stack, it finishes looping.
            else if(root_stack.empty())
            {
                //Set finished to true so that it exits the loop.
                finished = true;
            }
            //In the case that right is nullptr.
            else//!current->get_right()
            {
                //Go back up.
                current = root_stack.top();
                //Pop the item from the stack.
                root_stack.pop();
                //Write the node's data.
                strm << *current << '\n';
                //Set done to true since this action is taken.
                done = true;
                //If it can go to right, go right.
                if(current->get_right())
                {
                    current = current->get_right();
                    //Set done to false so that it allows traversal to left
                    //again.
                    done = false;
                }
            }
        }
    }
}

/**
 * @brief     It erases all the nodes from the tree.
 *
 * @detailed  It calls private version to erase the nodes.
 */
void BinarySearchTree::erase_recursively()
{
    //Call private version passing root.
    erase_recursively(root);
    //Set root to nullptr to leave the tree in a consistent, empty tree.
    root = nullptr;
}

/**
 * @brief     It erases all the nodes from the tree.
 *
 * @detailed  It is called by public version.
 *
 * @param     currentRoot     It holds a pointer that points to current root.
 */
void BinarySearchTree::erase_recursively(Node* currentRoot)
{
    //If there is no node in the tree, it doesn't do anything.
    if(currentRoot)
    {
        //Post-order traversal.
        //Go left.
        erase_recursively(currentRoot->get_left());
        //Go right.
        erase_recursively(currentRoot->get_right());
        //Set left to nullptr.
        currentRoot->set_left(nullptr);
        //Set right to nullptr.
        currentRoot->set_right(nullptr);
        //Visit and delete the node.
        delete currentRoot;
    }
}
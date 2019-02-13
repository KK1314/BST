/**
 * @file    Node.cpp
 * @brief   This is a class implementation file for a Node class.
 *
 * It contains necessary methods to diplay nodes.
 *
 * @author  Daiki Itoh
 * @date    10/2/2018
 */
#include "Node.h"

/**
 * @brief     It displays Node's data.
 * @param     fout     It holds an object of ostream.
 */
void Node::write(ostream& fout) const
{
    fout << get_data();
}

/**
 * @brief     Overloading << operator. It writes a node's data.
 *
 * @detailed  It calls write method() to display information.
 *
 * @param     fout     It holds an object of ostream.
 * @param     n     It holds an object of CSZNode.
 * 
 * @return    It returns the ostream object.
 */
ostream& operator<<(ostream& fout, const Node& n)
{
    //Make use of write() method to display data.
    n.write(fout);
    //Return the ostream object for the cascaded use of <<.
    return fout;
}
/**
 * @file    Node.h
 * @brief   This is a class specification file for a Node class.
 *
 * @author  Daiki Itoh
 * @date    10/2/2018
 */
#ifndef NODE_H
#define NODE_H
#include <iostream>
using std::ostream;

class Node
{
    public:
        Node(const int& new_data) { data = new_data; }
        void    set_left(Node* new_left) { left = new_left;} 
        void    set_right(Node* new_right) { right = new_right; }
        int     get_data() const { return data; }
        Node*   get_left() const { return left; }
        Node*   get_right() const { return right; }
        void    write(ostream& fout) const;
        bool    operator<(const Node& op2) const
                { return this->get_data() < op2.get_data(); }
    private:
        int     data;
        Node*   left  = nullptr;
        Node*   right = nullptr;
};
ostream& operator<<(ostream& fout, const Node& n);

#endif
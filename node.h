#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <iostream>


class Node
{
public:

	Node (const char c = 0, Node* prv = NULL) {x = c; previous = prv; }
	//~Node();

	Node* getPrevious() const { return previous; }
	char getChar () { return x; }

	void setPrevious(Node* previous) { this->previous = previous; }
	void setChar(const char x) { this -> x = x; }   ///the string is memorized into the stack char by char,
                                                    ///there are not multiple strings on a node

private:
    friend class stiva;
	Node* previous;
	char x;
};


#endif // NODE_H_INCLUDED

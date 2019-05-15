#ifndef STIVA_H_INCLUDED
#define STIVA_H_INCLUDED

#include <iostream>
#include <string.h>
#include <string>
#include "node.h"

using namespace std;

class stiva
{
public:
     int size_s = 0;
     stiva();
	~stiva();

    int size() {return size_s;}

	void Push(char);
	char Pop();
	char Top();
	void Reverse(char * str);
	void retrieveString(char * s);
	void DELETE();

	stiva operator - (stiva& other);
	bool operator == (stiva& other);

    friend ostream& operator <<(ostream& out, stiva& stiva1);
    friend istream& operator >>(istream& in, stiva& stiva1);

	private:
	Node* top;

};



#endif // STIVA_H_INCLUDED

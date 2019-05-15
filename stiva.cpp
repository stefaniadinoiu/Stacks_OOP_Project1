#include "stiva.h"

stiva::stiva() /// Stack constructor
{
    this -> top = new Node;
    cout << " \nStack initialized\n";
}

stiva::~stiva() /// stack destructor
{
    cout << " \nStack is destroyed\n";
}

void stiva::Push(char x) /// Enters items in the stack
{
    Node * newTop = new Node(x, this -> top);
    this -> top = newTop;
    ++size_s;
}

char stiva::Pop()  ///Removes items from the stack
{
    if(size_s)
    {
        Node * newTop = top -> previous;
        char topc = top -> x;
        delete top;
        top = newTop;
        --size_s;
        return topc;
    }
    return 0;
}

void stiva::DELETE()    /// Deletes all the elements from the stack
{
    while (this->Top() != 0)
        this->Pop();

  if (this->Top() == 0)

    cout << " STACK IS EMPTY ";
}

char stiva::Top() /// Displays the top of the stack
{
    return top->x;
}

void stiva::Reverse(char * str) /// Reverses the stack items
{
    int l = strlen(str);
    for(int i = 0; i < l; ++i)
        Push(str[i]);
    for(int i = 0; i < l; ++i)
        str[i] = Pop();
}

void stiva::retrieveString(char * s) /// Retrieves the stack in case it was previously changed
{
    int i = 0;
    Node * tempTop = top;
    do{
        s[i] = tempTop -> x;
        tempTop = tempTop -> previous;
        ++i;
    }
    while(tempTop->previous != NULL);
}

bool stiva::operator == (stiva & other) /// operator " == " overloading
{
///verifying if two stacks are equal

        while (this -> Top() == other.Top() && (this -> Top() != 0 && other.Top() != 0) )
        {
            this -> Pop();
            other.Pop();
        }

    if (this -> Top() == 0 && other.Top() == 0)  return true;
                else return false;

}

stiva stiva::operator - (stiva & other)  /// operator " - " overloading
{
    ///"from the beginning of the stack" => "top", because the first entered character is at the bottom

    while (this -> Top() == other.Top())
    {

        if ((int)this -> Top() == 0)
            break;
        else {
               Pop();
               other.Pop();
            }

    }

    return *this;
}

ostream& operator <<(ostream& out, stiva& stiva1) /// Operator " << " overloading
{
    Node * tempTop = stiva1.top;
    do{
        out << tempTop -> getChar() << " ";
        tempTop = tempTop -> getPrevious();
      }
      while (tempTop -> getPrevious() != NULL);
      out << "\n";

    return out;
}





/*ostream& operator <<(ostream& out, stiva& stiva1)   //displays the stack CONCOMITANT with it's emptying.
{
    while(stiva1.size())
        out<<stiva1.Pop();
    return out;
}*/

istream& operator >>(istream& in, stiva& stiva1) /// Operator " >> " overloading
{
    string temp;
    in >> temp;

    /// it - evaluates to iterator to set of string
    /// type automatically
    for (auto it = temp.begin(); it != temp.end(); ++it)

        stiva1.Push(*it);

    return in;
}

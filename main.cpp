#include <iostream>
#include <fstream>
#include "stiva.h"
#include "node.h"

using namespace std;

ifstream f("Stack.in");
char buf [1024];

void Project()
{
    cout << "----------- PROJECT I. SUBJECT 3 ----------\n";
    cout << "----------- DINOIU NADIA STEFANIA ---------\n";
    cout << "------------------ GROUP 211 --------------\n";
}

void Menu_INPUT_choice()
{
    cout << "1. Console input\n";
    cout << "2. File input\n";
}

void Menu_Stack_Operations()
{
    cout << "1. PUSH elements into the stack\n";
    cout << "2. POP elements from stack\n";
    cout << "3. Display the TOP of the stack\n";
    cout << "4. REVERSE a string USING the stack\n";
    cout << "5. REVERSE the stored string FROM the stack\n";
    cout << "6. DIFFERENCE between 2 stacks\n";
    cout << "7. DELETE the entire STACK\n";
    cout << "8. STACKS are EQUAL\n";
    cout << "0. EXIT\n";
}

int main()
{

    Project();

    stiva st1;

    int Option_1;

    cout << "Input from : \n\n";

    Menu_INPUT_choice();

    cin >> Option_1;

    switch (Option_1)
    {
        case 1 :
            int Option_2;

            cout << "\n" << "Choose stack operation :  " << "\n" << "\n";

            Menu_Stack_Operations();

            cin >> Option_2;

            while(Option_2)
            {
                switch(Option_2)
                {
                    case 0:
                        break;

                    case 1:
                        cout << "Press ENTER to STOP introducing" << "\n";
                        cin  >> st1;
                        cout << " Items entered: " << "\n";
                        cout << st1;
                        break;

                    case 2 :
                        st1.Pop();
                        cout << "REMAINED items: " << st1;
                        break;

                    case 3 :
                        cout << st1.Top();
                        break;

                    case 4:
                        cout << "String to reverse: ";
                        cin  >> buf;
                        st1.Reverse(buf);
                        cout << "REVERSED string: " << buf << "\n";
                        break;

                    case 5:
                        memset(buf, 0, 1024);
                        st1.retrieveString(buf);
                        st1.Reverse(buf);


                    case 7:
                            cout << "INITIAL stack is : ";
                            cout << st1;
                            st1.DELETE();
                            break;    cout << "REVERSED string: " << buf << "\n";


                    case 6:
                        {
                         stiva st2;
                         cout << "Second stack items :" << "\n";
                         cin  >> st2;
                         st1 = st1 - st2;
                         cout << "REMAINED items in the FIRST stack: " << "\n";
                         cout << st1;
                         break;
                        }


                    case 8:
                        {
                            stiva st1, st2;
                            cout << "FIRST STACK IS: ";
                            cin  >> st1;
                            cout << st1;
                            cout << "\n" << "SECOND STACK IS: ";
                            cin  >> st2;
                            cout << st2;
                            cout << "\n";

                           if(st1 == st2) cout << "STACKS ARE EQUAL";
                                else cout << "STACKS ARE NOT EQUAL";
                            break;
                        }


                }
                cout << "\n" << "Choose stack operation :  " << "\n" << "\n";

                 Menu_Stack_Operations();

                cin >> Option_2;
            }
          break;

        case 2 :

                 cout << "\n" << " Choose stack operation :  " << "\n" << "\n";

                 Menu_Stack_Operations();

                 cin >> Option_2;

                 while(Option_2){

                    switch(Option_2)
                        {

                        case 0:
                            break;

                        case 1:
                            f >> st1;
                            cout << "Items in the first stack: "  << "\n";
                            cout << st1;
                            break;

                        case 2 :
                            st1.Pop();
                            cout << "REMAINED items: " << "\n";
                            cout << st1;
                            break;

                        case 3 :
                            cout << st1.Top() << " ";
                            break;

                        case 4:
                            cout << "String to reverse: ";
                            st1.Reverse(buf);
                            cout << "REVERSED string: " << buf << "\n";
                            cout << st1;
                            break;
                        case 5:
                              memset(buf, 0, 1024);
                              st1.retrieveString(buf);
                              st1.Reverse(buf);
                              cout << "REVERSED string: " << buf << "\n";

                        case 7:
                            cout << "INITIAL stack is : ";
                            f >> st1;
                            cout << st1;
                            st1.DELETE();
                            break;

                        case 6:
                            {
                              stiva st2;
                              f >> st1;
                              cout << "Second stack items :" << "\n";
                              f  >> st2;
                              cout << st2;
                              st1 = st1 - st2;
                              cout << "REMAINED items in the FIRST stack: " << "\n";
                              cout << st1;
                              break;
                            }

                case 8:
                        {
                            stiva st1, st2;
                            cout << "FIRST STACK IS: ";
                            f  >> st1;
                            cout << st1;
                            cout << "\n" << "SECOND STACK IS: ";
                            f  >> st2;
                            cout << st2;
                            cout << "\n";

                           if(st1 == st2) cout << "STACKS ARE EQUAL";
                                else cout << "STACKS ARE NOT EQUAL";
                            break;
                        }

        }
                    cout << "\n" << "Choose stack operation :  " << "\n" << "\n";

                    Menu_Stack_Operations();

                    cin >> Option_2;

                }

                f.close();
                break;
    }
    return 0;
}

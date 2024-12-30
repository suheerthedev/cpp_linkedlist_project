#include <iostream>
using namespace std;

struct Node
{
    int data;
    int index;
    Node *next;
};

struct LinkedList
{
    Node *start = nullptr;
    Node *last = nullptr;
    int length = 0;

    // insertBegin(value)
    void insertBegin(int value)
    {
        // ye if check karega ke list empty hai ke nahi, humare helper function "isEmpty ki madad"
        if (isEmpty())
        {
            // ye line memory me ik empty node banadega "n" ke naam se
            Node *n = new Node;

            // ab is node mein woh value pass hogi jo user ne function call karwate howe di
            n->data = value;

            // iski index humne zero rakhi hai kion kay hum head pe insert kar rahay hain or head/pehli node ki index zero hoti hai
            n->index = 0;

            // iska pointer null hoga kion  kay ye wahid node hogi list mein, because hum check kar chuke hain ke list empty hai ke nahi
            n->next = nullptr;

            // start or last ko is node pe lakar betha deingay, because ye wahid node hai abhi humari list mein
            start = n;
            last = n;

            // iska tou pata he hoga
            length++;
        }
        /*or agar list empty nahi howi tou ye chale ga,
        ab ismein hum ye assume karte howe handling kareingay ke
        atleast ik node tou list mein majood hai*/
        else
        {
            // ye line memory me ik empty node banadega "n" ke naam se
            Node *n = new Node;

            // ab is node mein woh value pass hogi jo user ne function call karwate howe di
            n->data = value;

            // iski index humne zero rakhi hai kion kay hum head pe insert kar rahay hain or head/pehli node ki index zero hoti hai
            n->index = 0;

            /*is node ko humne start pe point karwa kion kay start abhi pehli node pe
            betha hai or is "pehli wali" node se pehlay hum ik new node rakhna chaa rahe hain,
            isliyue hum new node ka pointer jo ke "n->next" hai usko start pe point
            karwadeingay
            */
            n->next = start;

            /* ab start kion kay humesha pehli wali node pe hona chahiye hai, lekin
            ab list mein ik new node agayi hai jo ke start se pehli wali node hai
            isliye hum start ko jump karwa kar us node pe rakhdeingay */
            start = n;

            // ye tou pata he hoga
            length++;

            // sab nodes ki indices update kardein, helper method use karte howe
            updateIndices();
        }
    }

    // insertEnd(int value)
    void insertEnd(int value)
    {
        if (isEmpty())
        {
            Node *n = new Node;
            n->data = value;
            n->index = length;
            n->next = nullptr;

            start = n;
            last = n;
            length++;
        }
        else
        {
            Node *n = new Node;
            n->data = value;
            n->index = length;
            n->next = nullptr;

            last->next = n;
            last = n;
            length++;
        }
    }

    // insertAt(int index, int value)
    void insertAt(int index, int value)
    {
        if (index == 0)
        {
            // when user wants to add in the start of list
            insertBegin(value);
        }
        else if (index > 0 && index < length)
        {
            // beech mein kahein pe
            Node *temp = start;

            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
            }

            Node *n = new Node;
            n->data = value;
            n->index = index;
            n->next = temp->next;
            temp->next = n;
            length++;
            updateIndices();
        }
        else
        {
            cout << endl
                 << "No Such Index Found" << endl;
        }
    }

    // deleteBegin
    void deleteBegin()
    {
        if (isEmpty())
        {
            cout << endl
                 << "Unable to delete, List is Empty :(" << endl;
        }
        else
        {
            Node *toDelete = start;
            start = start->next;
            delete toDelete;
            length--;
            updateIndices();
        }
    }

    // deleteEnd
    void deleteEnd()
    {
        if (isEmpty())
        {
            cout << endl
                 << "Unable to delete, List is Empty :(" << endl;
        }
        else
        {
            Node *temp = start;

            for (int i = 0; i < length - 2; i++)
            {
                temp = temp->next;
            }

            Node *toDelete = last;
            last = temp;
            last->next = nullptr;
            delete toDelete;
            length--;
        }
    }

    // deleteAt(index)
    void deleteAt(int index)
    {
        if (isEmpty())
        {
            cout << endl
                 << "Unable to delete, List is Empty :(" << endl;
        }
        else
        {
            if (index == 0)
            {
                // jab head delete karna hoga
                deleteBegin();
            }
            else if (index == length - 1)
            {
                // jab tail ko delete karna hoga
                deleteEnd();
            }
            else if (index > 0 && index < length - 1)
            {
                // head or tail ke beech mein jo nodes hongi unko handle kareingay
                Node *prev = start;
                Node *temp = start;

                for (int i = 0; i < index; i++)
                {
                    prev = temp;
                    temp = temp->next;
                }

                prev->next = temp->next;
                delete temp;
                length--;
                updateIndices();
            }
            else
            {
                cout << endl
                     << "Invalid Index" << endl;
            }
        }
    }

    // deleteWhereDataIs(value)
    void deleteWhereDataIs(int value)
    {
        if (isEmpty())
        {
            cout << endl
                 << "Unable to delete, List is Empty :(" << endl;
        }
        else
        {
            if (checkForValue(value))
            {
                // ye jab run hoga, jab na tou list empty hogi or value bhi available hogi
                if (start->data == value)
                {
                    // jab value humein head pe hi miljayegi
                    deleteBegin();
                }
                else if (last->data == value)
                {
                    // jab value humein tail pe miljayegi
                    deleteEnd();
                }
                else
                {
                    // jab value beech mein kahein hogi
                    Node *prev = start;
                    Node *temp = start;

                    for (int i = 0; i < length; i++)
                    {
                        if (temp->data == value)
                        {
                            break;
                        }
                        prev = temp;
                        temp = temp->next;
                    }

                    prev->next = temp->next;
                    delete temp;
                    length--;
                    updateIndices();
                }
            }
            else
            {
                cout << "Sorry, value is not present in the list." << endl;
            }
        }
    }

    // search based on index
    void getWhereIndexIs(int index)
    {
        if (isEmpty())
        {
            cout << endl
                 << "List is Empty, Cannot Search an Empty List :(" << endl;
        }
        else
        {
            if (index >= 0 && index < length)
            {
                Node *temp = start;
                for (int i = 0; i < index; i++)
                {
                    temp = temp->next;
                }
                cout << endl
                     << "The Data at given index is: " << temp->data << endl;
            }
            else
            {
                cout << endl
                     << "No data found on this index." << endl;
            }
        }
    }

    // search based on value
    void getWhereValueIs(int value)
    {
        if (isEmpty())
        {
            cout << endl
                 << "List is Empty, Cannot Search an Empty List :(" << endl;
        }
        else
        {

            if (checkForValue(value))
            {
                Node *temp = start;
                for (int i = 0; i < length; i++)
                {
                    if (temp->data == value)
                    {
                        break;
                    }
                    temp = temp->next;
                }
                cout << endl
                     << "The data is on the index: " << temp->index << endl;
            }
            else
            {
                cout << endl
                     << "The value is not present in the list." << endl;
            }
        }
    }

    // returns the size of the list or the number of elements
    int sizeOfList()
    {
        return length;
    }

    void sortList()
    {
        Node *temp = start;
        for (int i = 0; i < length; i++)
        {
            temp = temp->next;
        }
    }

    // display method
    void display()
    {
        if (isEmpty())
        {
            cout << endl
                 << "List is Empty Right Now." << endl;
        }
        else
        {

            Node *temp = start;
            cout << endl;
            for (int i = 0; i < length; i++)
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << " NULL " << endl;
        }
    }

    //============ HELPER FUNC & METHODS ==========

    bool isEmpty()
    {
        return start == nullptr;
    }

    void updateIndices()
    {
        Node *temp = start;
        for (int i = 0; i < length; i++)
        {
            temp->index = i;
            temp = temp->next;
        }
    }

    bool checkForValue(int value)
    {
        Node *temp = start;
        bool isPresent = false;

        for (int i = 0; i < length; i++)
        {
            if (temp->data == value)
            {
                isPresent = true;
            }
            temp = temp->next;
        }

        return isPresent;
    }
};

int getValue()
{
    int value;
    cout << endl
         << "Enter value: ";
    cin >> value;

    return value;
}

int getIndex()
{
    int index;
    cout << endl
         << "Enter index: ";
    cin >> index;

    return index;
}

bool isContinue()
{
    bool condition;
    cout << endl
         << "Enter 1 to Continue, or 0 to exit: ";
    cin >> condition;
    return condition;
}

void exitProgram()
{
    cout << "Exiting the program. Goodbye!" << endl;
    return;
}

LinkedList myList;

void mainMenu()
{
    int choice;

    cout << "------------------------" << endl
         << "    Linked List Menu    " << endl
         << "------------------------" << endl
         << endl
         << "        Add Value       " << endl
         << "1. Add Value In Start" << endl
         << "2. Add Value At" << endl
         << "3. Add Value In End" << endl
         << endl
         << "       Delete Value     " << endl
         << "4. Delete Value In Start" << endl
         << "5. Delete Value At" << endl
         << "6. Delete Value In End" << endl
         << "7. Delete Specific Value" << endl
         << endl
         << "     Other Operations    " << endl
         << "8. Display List" << endl
         << "9. Find Value by Index" << endl
         << "10. Find Specific Value" << endl
         << "11. Exit" << endl;

    cout << endl
         << "Enter Your Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:

        myList.insertBegin(getValue());

        if (isContinue())
            mainMenu();
        else
            exitProgram();

        break;

    case 2:

        myList.insertAt(getIndex(), getValue());

        if (isContinue())
            mainMenu();
        else
            exitProgram();

        break;

    case 3:

        myList.insertEnd(getValue());

        if (isContinue())
            mainMenu();
        else
            exitProgram();

        break;

    case 4:

        myList.deleteBegin();

        if (isContinue())
            mainMenu();
        else
            exitProgram();

        break;

    case 5:

        myList.deleteAt(getIndex());

        if (isContinue())
            mainMenu();
        else
            exitProgram();

        break;

    case 6:

        myList.deleteEnd();

        if (isContinue())
            mainMenu();
        else
            exitProgram();

        break;

    case 7:

        myList.deleteWhereDataIs(getValue());

        if (isContinue())
            mainMenu();
        else
            exitProgram();

        break;

    case 8:

        myList.display();

        if (isContinue())
            mainMenu();
        else
            exitProgram();

        break;

    case 9:

        myList.getWhereIndexIs(getIndex());

        if (isContinue())
            mainMenu();
        else
            exitProgram();

        break;

    case 10:
        myList.getWhereValueIs(getValue());

        if (isContinue())
            mainMenu();
        else
            exitProgram();

        break;

    case 11:
        exitProgram();
        break;

    default:
        cout << "Invalid choice! Please try again." << endl;
        mainMenu();

        break;
    }
}
int main()
{
    mainMenu();

    return 0;
}
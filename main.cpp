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
        // checks if the list is empty or not
        // handles case where list is empty
        if (isEmpty())
        {
            Node *n = new Node;
            n->data = value;
            n->index = 0;
            n->next = nullptr;
            
            start = n;
            last = n;

            length++;
        }
        // handle case where is list is not empty
        else
        {
            Node *n = new Node;
            n->data = value;
            n->index = 0;
            n->next = start;

            start = n;

            length++;

            updateIndices();
        }
    }

    // insertEnd(int value)
    void insertEnd(int value)
    {
        // checks if the list is empty or not
        // handles case where list is empty
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
        // handle case where is list is not empty
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

    // this method takes index and value from user, and insert a new node with the value provided  by user
    void insertAt(int index, int value)
    {
        // when user wants to add in the start of list
        if (index == 0)
        {
            insertBegin(value);
        }
        // when user choose to insert in between or in the end of the list
        else if (index > 0 && index < length)
        {
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
        // display error message when index is not valid
        else
        {
            cout << endl
                 << "No Such Index Found" << endl;
        }
    }

    // this method deletes the node present in the start of the list
    void deleteBegin()
    {
        // checks if the list is empty or not
        if (isEmpty())
        {
            cout << endl
                 << "Unable to delete, List is Empty :(" << endl;
        }
        // handles the case when the list is not empty
        else
        {
            Node *toDelete = start;
            start = start->next;
            delete toDelete;
            length--;
            updateIndices();
        }
    }

    // this method deletes the node present in the end of the list
    void deleteEnd()
    {
        // checking if the list is empty
        if (isEmpty())
        {
            cout << endl
                 << "Unable to delete, List is Empty :(" << endl;
        }
        // handling case where list is not empty
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

    // this method deletes the node present on the index given by the user
    void deleteAt(int index)
    {
        // checking if the list is empty or not
        if (isEmpty())
        {
            cout << endl
                 << "Unable to delete, List is Empty :(" << endl;
        }
        // handling the cases when list is not empty
        else
        {
            if (index == 0)
            {
                // when user chooses to delete the first node of the list
                deleteBegin();
            }
            else if (index == length - 1)
            {
                // when user chooses to delete the last node of the list
                deleteEnd();
            }
            else if (index > 0 && index < length - 1)
            {
                // when user chooses to delete any node that is present between head and tail
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

    // this method deletes the nodes which has the first instance of the data provided by the user
    void deleteWhereDataIs(int value)
    {
        // checking if the list is empty or not
        if (isEmpty())
        {
            cout << endl
                 << "Unable to delete, List is Empty :(" << endl;
        }
        // handling cases when the list is not empty
        else
        {
            // this if will run if the value is already present in the list
            if (checkForValue(value))
            {
                // when the data is found in the first node of the list
                if (start->data == value)
                {

                    deleteBegin();
                }
                // when the data is found in the last node of the list
                else if (last->data == value)
                {

                    deleteEnd();
                }
                // when the data is found in any node that is in between the head and the tail of the list
                else
                {

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
            // displaying error message in case the list doesnt has the value
            else
            {
                cout << "Sorry, value is not present in the list." << endl;
            }
        }
    }

    // this method searches based on index provided by user
    void getWhereIndexIs(int index)
    {
        // checking if the list is empty or not
        if (isEmpty())
        {
            cout << endl
                 << "List is Empty, Cannot Search an Empty List :(" << endl;
        }
        // handling cases when the list is not empty
        else
        {
            // finds the value if index is correct
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
            // display errro message incase index is invalid
            else
            {
                cout << endl
                     << "Invalid index." << endl;
            }
        }
    }

    // this method searches based on the value provided by the user
    void getWhereValueIs(int value)
    {
        // checks if the list is empty or not
        if (isEmpty())
        {
            cout << endl
                 << "List is Empty, Cannot Search an Empty List :(" << endl;
        }
        // handles the cases when list is not empty
        else
        {
            // this if will run if the value is already present in the list
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
            // displays error message if value is not present in the list
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

    // traverses and display the elements in the list
    void display()
    {
        // checks if list is empty or not
        if (isEmpty())
        {
            cout << endl
                 << "List is Empty Right Now." << endl;
        }
        // displays if list is not empty
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

    // checks whether the list is empty or not
    bool isEmpty()
    {
        return start == nullptr;
    }

    // this method updates indices of all the nodes in the list
    void updateIndices()
    {
        Node *temp = start;
        for (int i = 0; i < length; i++)
        {
            temp->index = i;
            temp = temp->next;
        }
    }

    // this function checks whether the given value is present or not in the list
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

// this functions gets the value from user and returns it
int getValue()
{
    int value;
    cout << endl
         << "Enter value: ";
    cin >> value;

    return value;
}

// this functions gets the index from user and returns it
int getIndex()
{
    int index;
    cout << endl
         << "Enter index: ";
    cin >> index;

    return index;
}

// this function asks user if they want to continue with the program or not
bool isContinue()
{
    bool condition;
    cout << endl
         << "Enter 1 to Continue, or 0 to exit: ";
    cin >> condition;
    return condition;
}

// this method displays exiting message
void exitProgram()
{
    cout << "Exiting the program. Goodbye!" << endl;
    return;
}

// created list
LinkedList myList;

// method which runs main menu
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
    // everything runs through main menu method
    mainMenu();

    return 0;
}
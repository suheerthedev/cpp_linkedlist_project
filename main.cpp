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

    // function to add a new node at the end most
    void addANewNode(int value)
    {
        Node *n = new Node;
        n->data = value;
        n->index = length;
        n->next = nullptr;

        if (length == 0)
        {
            start = n;
            last = n;
        }
        else
        {
            last->next = n;
            last = n;
        }
        length++;
    }

    // function to traverse and display the content of the list
    void display()
    {
        Node *temp = start;
        for (int i = 0; i < length; i++)
        {
            cout << "Index: " << temp->index << " Value: " << temp->data << endl;
            temp = temp->next;
        }
    }

    // function to insert a new node in the start of the list
    void insertAtStart(int value)
    {
        Node *temp = start;
        for (int i = 0; i < length; i++)
        {
            temp->index++;
            temp = temp->next;
        }
        Node *n = new Node;
        n->data = value;
        n->index = 0;
        n->next = start;
        start = n;
        length++;
    }

    // function to insert a new node in the end of the list
    void insertAtLast(int value)
    {
        Node *n = new Node;
        n->data = value;
        n->index = length;
        n->next = nullptr;
        last->next = n;
        last = n;
        length++;
    }

    // function to insert a new node at an already present index
    void insertAt(int index, int value)
    {

        if (index == 0)
        {
            insertAtStart(value);
        }
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

            Node *temp1 = n->next;
            for (int i = index; i < length; i++)
            {
                temp1->index++;
                temp1 = temp1->next;
            }
            length++;
        }
        else
        {
            cout << "No data on this index." << endl;
        }
    }

    void deleteBegin()
    {
        if (isEmpty())
        {
            cout << "Cannot Delete, List Is Empty." << endl;
        }
        else
        {
            start = start->next;
            length--;
            Node *temp = start;
            for (int i = 0; i < length; i++)
            {
                temp->index--;
                temp = temp->next;
            }
        }
    }

    void deleteEnd()
    {
        /*this function will go the index before the last one and
        then we would update the last to comeback one node back
        and update its pointer to nullptr
        */
        if (isEmpty())
        {
            cout << "Cannot Delete, List Is Empty." << endl;
        }
        Node *temp = start;

        for (int i = 0; i < length - 2; i++)
        {
            temp = temp->next;
        }

        last = temp;
        last->next = nullptr;
        length--;
    }

    void deleteAt(int index)
    {
        if (index == 0)
        {
            start = start->next;
            length--;
            Node *temp = start;
            for (int i = 0; i < length; i++)
            {
                temp->index--;
                temp = temp->next;
            }
        }
        else if (index == length - 1)
        {
            Node *temp = start;

            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
            }
            temp->next = nullptr;
            last = temp;
            length--;
        }
        else if (index > 0 && index < length - 1)
        {
            Node *temp1 = start;
            Node *temp2 = start;

            for (int i = 0; i < index - 1; i++)
            {
                temp1 = temp1->next;
            }

            for (int i = 0; i < index; i++)
            {
                temp2 = temp2->next;
            }
            Node *temp3 = temp2;

            temp1->next = temp2->next;
            length--;
            for (int i = index; i < length; i++)
            {
                temp3 = temp3->next;
                temp3->index--;
            }
        }
        else
        {
            cout << "No Data Available At This Index." << endl;
        }
    }

    void deleteWhereDataIs(int value)
    {
        //to check whether value is present or not
        bool isPresent = false;
        Node* checker = start;
        for(int i = 0 ; i < length; i++){
            if(checker->data == value){
                isPresent = true;
            }
            checker = checker->next;
        }

        //now handling the deletion of the data
        if(isPresent){
            if (start->data == value)
            {
                start = start->next;
                length--;
                Node *temp = start;
                for (int i = 0; i < length; i++)
                {
                    temp->index--;
                    temp = temp->next;
                }
            }
            else
            {
                Node *temp1 = start;
                Node *temp2 = start;

                for (int i = 0; i < length; i++)
                {
                    if (temp2->next == nullptr)
                    {
                        temp1->next = nullptr;
                        last = temp1;
                        length--;
                        break;
                    }
                    else if (temp2->data == value)
                    {
                        temp1->next = temp2->next;
                        length--;
                        for (int i = temp2->index; i < length; i++)
                        {
                            temp2 = temp2->next;
                            temp2->index--;
                        }
                        break;
                    }
                    temp1 = temp2;
                    temp2 = temp2->next;
                }
            }
        }
        else{
            cout<<"Value not present in the list."<<endl;
        }
    }

    void getWhereValueIs(int value)
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
        cout << "Data is at index: " << temp->index << endl;
    }

    void getWhereIndexIs(int index)
    {
        Node *temp = start;

        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }

        cout << "Data at Index: " << temp->index << " is: " << temp->data << endl;
    }

    // function to check whether list is empty or not, returns a boolean
    bool isEmpty()
    {
        return start == nullptr;
    }
};

int main()
{
    LinkedList l1;

    l1.addANewNode(1);
    l1.addANewNode(2);
    l1.addANewNode(3);
    l1.addANewNode(4);

    cout << "Before Deleting where data is: " << endl;
    l1.display();
    cout << "After Deleting where data is: " << endl;
    l1.deleteWhereDataIs(5);
    l1.display();

    return 0;
}
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
    Node *start;
    Node *last;
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
        start = start->next;
        length--;
        Node *temp = start;
        for (int i = 0; i < length; i++)
        {
            temp->index--;
            temp = temp->next;
        }
    }

    void deleteEnd()
    {
        /*this function will go the index before the last one and
        then we would update the last to comeback one node back
        and update its pointer to nullptr
        */
        Node *temp = start;

        for (int i = 0; i < length - 2; i++)
        {
            temp = temp->next;
        }

        last = temp;
        last->next = nullptr;
        length--;
    }
};

int main()
{
    LinkedList l1;

    l1.addANewNode(1);
    l1.addANewNode(2);
    l1.addANewNode(3);
    l1.addANewNode(4);

    cout << "Before Deleting From Start: " << endl;
    l1.display();
    cout << "After Deleting From Start: " << endl;
    l1.deleteEnd();
    l1.display();

    return 0;
}
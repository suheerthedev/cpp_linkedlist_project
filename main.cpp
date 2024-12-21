#include<iostream>
using namespace std;

struct Node{
    int data;
    int index;
    Node* next;
};

struct LinkedList{
    Node* start;
    Node* last;
    int length = 0;

    void addANewNode(int value){
        Node* n = new Node;
        n->data = value;
        n->index = length;
        n->next = nullptr;

        if(length == 0){
            start = n;
            last = n;
        }
        else{
            last->next = n;
            last = n;
        }
        length++;
    }

    void display(){
        Node* temp = start;
        for(int i = 0; i < length ; i++){
            cout<<"Index: "<<temp->index<<" Value: "<<temp->data<<endl;
            temp = temp->next;
        }
    }
};

int main(){
    LinkedList l1;

    l1.addANewNode(1);
    l1.addANewNode(2);
    l1.addANewNode(3);
    l1.addANewNode(4);

    l1.display();
    return 0;
}
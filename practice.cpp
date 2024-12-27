#include<iostream>
using namespace std;

struct Node{
    int data;
    int index;
    Node* next;
};

struct LinkedList{
    Node* start = nullptr;
    Node* last = nullptr;
    int length = 0;

    void insertBegin(int value){

        if(isEmpty()){
            Node* n = new Node;
            n->data = value;
            n->index = 0;
            n->next = nullptr;

            start = n;
            last = n;
            length++;
        }
        else{
            Node* n = new Node;
            n->data = value;
            n->index = 0;
            n->next = start->next;
            start = n;
            length++;
            updateIndices();
        }
            
    }

    void insertEnd(int value){
        Node* n = new Node;
        n->data = value;
        n->index = length;
        n->next = nullptr;

    }

    //============== HELPER FUNCTIONS ==============

    void updateIndices(){
        Node* temp = start;

        for(int i = 0 ; i < length; i++){
            temp->index = i;
            temp = temp->next;
        }
    }

    bool isEmpty(){
        return start == nullptr;
    }

};

int main(){
    return 0;
}
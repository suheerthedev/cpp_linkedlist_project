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

    //insertBegin(value)
    void insertBegin(int value){
        if(isEmpty()){
            //when list is empty
            Node* n = new Node;
            n->data = value;
            n->index = 0;
            n->next = nullptr;

            start = n;
            last = n;
            length++;
        }
        else{
            //node are found
        }
    }

    //insertEnd(value)

    //insertAt(index , value)

    //deleteBegin

    //deleteEnd

    //deleteAt(index)

    //deleteWhereDataIs(value)

    //========== HELPER METHOD & FUNCTION =========

    bool isEmpty(){
        return start == nullptr; //true other false
    }
};

int main(){


    return 0;
}
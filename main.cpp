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
};

int main(){
    return 0;
}
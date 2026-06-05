#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

void traverse(Node *head); 
void backward(Node *head);

int main(){
    
    Node *node1 = new Node;
    Node *node2 = new Node;
    Node *node3 = new Node;
    Node *node4 = new Node;
    Node *node5 = new Node;
    
    node1->data = 10;
    node1->next = node2;
    node1->prev = node5;
    
    node2->data = 20;
    node2->next = node3;
    node2->prev = node1;
    
    node3->data = 30;
    node3->next = node4;
    node3->prev = node2;
    
    node4->data = 40;
    node4->next = node5;
    node4->prev = node3;
    
    node5->data = 50;
    node5->next = node1;
    node5->prev = node4;
    
    cout << "Forward:\n";
    traverse(node1);

    cout << "\nBackward:\n";
    backward(node1);

    return 0;
}

void traverse(Node *head){
    Node *temp = head;
    int i = 1;
    int max = head->data;

    do{
        cout << "Data ke " << i << ": " << temp->data << endl;
        if(temp->data > max){
            max = temp->data;
        }
        temp = temp->next;
        i++;
    }while(temp != head);

    cout << "Data terbesar adalah " << max << endl;
}

void backward(Node *head){
    Node *temp = head->prev;
    int i = 1;
    int max = temp->data;

    do{
        cout << "Data ke " << i << ": " << temp->data << endl;
        if(temp->data > max){
            max = temp->data;
        }
        temp = temp->prev;
        i++;
    }while(temp != head->prev);
    cout << "Data terbesar adalah " << max << endl;
}
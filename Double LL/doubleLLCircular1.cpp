#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node *next;
	struct Node *prev;
};

void traverse(struct Node *temp); 
void mundur(struct Node *temp);
int main(){
	
	Node *node1 = NULL;
	Node *node2 = NULL;
	Node *node3 = NULL;
	Node *node4 = NULL;
	Node *node5 = NULL;
	
	node1 = new Node;
	node2 = new Node;
	node3 = new Node;
	node4 = new Node;
	node5 = new Node;
	
	node1->data = 10;
	node1->next = node2;
	node1->prev = NULL;
	
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
	node5->next = NULL;
	node5->prev = node4;

	cout << "data linked list : " << endl;
	traverse(node1);
	mundur(node5);
	cin.get();
	return 0;
}

void traverse(struct Node *temp){
	int i = 1;

	while (temp != NULL){
		cout << "Data ke " << i << ": ";
		cout << temp->data<<endl;

		temp = temp->next;
		
		i++;
	}
	cout<<"jumlah datanya ada "<<i-1<<endl;
}

void mundur(struct Node *temp){
	int i = 1;

	while(temp != NULL){
		cout << "Data ke " << i << ": ";
		cout<<temp->data<<endl;
		temp = temp->prev;
		i++;
	}
	cout << "jumlah datanya ada " << i-1 << endl;

}
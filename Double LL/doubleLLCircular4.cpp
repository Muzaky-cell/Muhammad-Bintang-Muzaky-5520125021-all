#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node* insertDepan(Node *head, int nilai){
    Node *baru = new Node;
    baru->data = nilai;

    if(head == NULL){
        baru->next = baru;
        return baru;
    }

    Node *tail = head;
    while(tail->next != head){
        tail = tail->next;
    }

    baru->next = head;
    tail->next = baru;
    head = baru;

    return head;
}

void traverse(Node *head){
    if(head == NULL){
        cout << "List kosong" << endl;
        return;
    }

    Node *temp = head;

    do{
        cout << temp->data << " -> ";
        temp = temp->next;
    }while(temp != head);

    cout << "(kembali ke head)" << endl;
}

int main(){
    int n, data, tambah;
    Node *head = NULL;
    Node *tail = NULL;
    cout << "Masukkan jumlah data: ";
    cin >> n;

    for(int i = 1; i <= n; i++){
        cout << "Masukkan data ke " << i << ": ";
        cin >> data;
        Node *baru = new Node;
        baru->data = data;
        if(head == NULL){
            head = tail = baru;
            baru->next = head;
        } else {
            tail->next = baru;
            tail = baru;
            tail->next = head;
        }
    }

    cout << "\nData Circular Linked List awal:" << endl;
    traverse(head);

    cout << "\nMasukkan data yang ditambahkan di awal: ";
    cin >> tambah;

    head = insertDepan(head, tambah);

    cout << "\nData setelah ditambah di awal:" << endl;
    traverse(head);
    
    return 0;
}

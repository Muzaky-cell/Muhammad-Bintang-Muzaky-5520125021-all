#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

Node* insertBelakang(Node *head, int nilai){
    Node *baru = new Node;
    baru->data = nilai;

    if(head == NULL){
        baru->next = baru;
        baru->prev = baru;
        return baru;
    }

    Node *tail = head->prev;

    tail->next = baru;
    baru->prev = tail;

    baru->next = head;
    head->prev = baru;

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

void traverseBalik(Node *head){
    if(head == NULL){
        cout << "List kosong" << endl;
        return;
    }

    Node *temp = head->prev;

    do{
        cout << temp->data << " -> ";
        temp = temp->prev;
    }while(temp != head->prev);

    cout << "(kembali ke tail)" << endl;
}

int main(){
    int n, data, tambah;
    Node *head = NULL;

    cout << "Masukkan jumlah data: ";
    cin >> n;

    for(int i = 1; i <= n; i++){
        cout << "Masukkan data ke " << i << ": ";
        cin >> data;
        head = insertBelakang(head, data);
    }

    cout << "\nMasukkan data yang ditambahkan di akhir: ";
    cin >> tambah;

    head = insertBelakang(head, tambah);

    cout << "\nData setelah ditambah di akhir (Forward):" << endl;
    traverse(head);

    cout << "\nData setelah ditambah di akhir (Backward):" << endl;
    traverseBalik(head);

    return 0;
}
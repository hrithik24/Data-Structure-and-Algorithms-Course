#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;

        Node(){
            this->next = NULL;
        }

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

void displayLL(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int lengthLL(Node *head){
    Node *temp = head;
    int length = 0;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    return length;
}

void insertAtHead(Node *&head,Node *&tail,int data){
    if(head == NULL){
        // create new node
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        // create new node
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(Node *&head,Node *&tail,int data){
    if(head == NULL){
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node *newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtAnyPosition(Node *&head,Node *&tail,int data,int position){
    int length = lengthLL(head);
    if(position == 1){
        insertAtHead(head,tail,data);
    }
    else if(position == length){

    }
}
int main(){
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head,tail,10);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    insertAtTail(head,tail,40); 
    insertAtTail(head,tail,50);
    displayLL(head);
}
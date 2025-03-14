#include<iostream>
using namespace std;
class Node{
    public: 
        int data;
        Node *prev;
        Node *next;

        Node(){
            this->prev = NULL;
            this->next = NULL;
        }

        Node(int data){
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
};

void printLL(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

int lengthLL(Node *head){
    Node *temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node *&head,Node *&tail,int data){
    // empty linked list
    if(head == NULL){
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    // create new node
    else{
        Node *newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtTail(Node *&head,Node *&tail,int data){
    // linked list is empty
    if(head == NULL){
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    // linked list is not empty
    else{
        Node *newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertAtAnyPosition(Node *&head,Node *&tail,int data,int position){
    if(head == NULL){
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }

    else{
        int len = lengthLL(head);

        if(position == 1){
            insertAtHead(head,tail,data);
        }
        else if(position == len){
            insertAtTail(head,tail,data);
        }
        else{

            Node *newNode = new Node(data);

            Node *prevNode = NULL;
            Node *currNode = head;

            while(position != 1){
                position--;
                prevNode = currNode;
                currNode = currNode->next;
            }
            newNode->prev = prevNode;
            prevNode->next = newNode;
            newNode->next = currNode;
            currNode->prev = newNode;
        }
    }
}

void deleteNode(Node *&head,Node *&tail,int position){
    if(head == NULL){
        cout << "Cannot delete because linked list is empty." << endl;
        return;
    }

    // for single node
    if(head == tail){
        Node *temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
    }

    int len = lengthLL(head);

    if(position == 1){
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }

    else if(position == len){
        Node *prevNode = tail->prev;
        prevNode->next = NULL;
        tail->prev = NULL;
        delete tail;
        tail = prevNode;
    }
    
    else{
        Node *prevNode = NULL;
        Node *currNode = head;

        while(position != 1){
            position--;
            prevNode = currNode;
            currNode = currNode->next;
        }
        prevNode->next = currNode->next;
        currNode->next->prev = prevNode;
        currNode->next = NULL;
        currNode->prev = NULL;
        delete currNode;
    }
}

int main(){
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head,tail,10);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,40);
    insertAtTail(head,tail,50);
    insertAtTail(head,tail,60);
    printLL(head);
    insertAtAnyPosition(head,tail,100,4);
    printLL(head);
    deleteNode(head,tail,5);
    printLL(head);
}
#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;

        // default constructor
        Node(){
            cout << "I am inside default constructor" << endl;
            this->next = NULL;
        }

        // parameterized constructor
        Node(int data){
            cout << "I am inside parameterized constructor" << endl;
            this->data = data;
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
    int length = 0;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    return length;
}

void insertAtHead(Node *&head,Node *&tail,int data){
    if(head == NULL){
        //create new node
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        // create a new node
        Node *newNode = new Node(data);
        //attach new node to head node
        newNode->next = head;
        //update head
        head = newNode;
    }
}

void insertAtTail(Node *&head,Node *&tail,int data){
    if(head == NULL){
        // empty LL
        // create new node
        Node* newNode = new Node(data);
        // head and tail ko new node pe point kar do
        head = newNode;
        tail = newNode;
    }
    else{
        //create new node
        Node* newNode = new Node(data);
        // tail node ko attach karo newNode se
        tail->next = newNode;
        //update tail node
        tail = newNode;
    }
}

void insertAtAnyPosition(Node *&head,Node *&tail,int data,int position){
    // if(position < 1){
    //     cout << "Cannot insert, please enter a valid position" << endl;
    //     return;
    // }
    int length = lengthLL(head);
    // if(position > length){
    //     cout << "Cannot insert, please enter a valid position." << endl;
    //     return;
    // }
    if(position == 1){
        insertAtHead(head,tail,data);
    }
    else if(position == length+1){
        insertAtTail(head,tail,data);
    }
    else{
        // create a new node
        Node *newNode = new Node(data);
        // traverse prev and current to a position
        Node *prev = NULL;
        Node *curr = head;
        while(position != 1){
            prev = curr;
            curr = curr->next;
            position--;
        }
        // attach prev to new node 
        prev->next = newNode;
        //attach new node to curr
        newNode->next = curr;
    }
     

}

void deleteNode(Node *&head,Node *&tail,int position){

    int len = lengthLL(head);

    // empty linked list
    if(head == NULL){
        cout << "Cannot delete,because linked list is empty" << endl;
        return;
    }

    // single element case
    if(head == tail){
        Node *temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return; 
    }

    // delete from head
    if(position == 1){
        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp; 

    }

    // delete from tail
    else if(position == len){   
        Node *prev = head;
        while(prev->next != tail){
            prev = prev->next;
        }

        prev->next = NULL;
        delete tail;
        tail = prev; 
    }

    // delete from any given position
    else{
        // set prev and curr pointer
        Node *prev = NULL;
        Node *curr = head;

        while(position != 1){
            position--;
            prev = curr;
            curr = curr->next;
        }
        
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

    }

}

// reverse a linked list
void reverseLL(Node *&head){
    Node *temp = head;
    Node *ptr = NULL;
    Node *ptr1 = head;
    while(temp != NULL){
        ptr1 = temp->next;
        temp->next = ptr;
        ptr = temp;
        temp = ptr;
    }
    head = ptr;
}

int main(){
    // creation of node
    // Node a; // static object creation
    // Node *head = new Node(); dynamic object creation 
    // Node *first = new Node(10);
    // Node *second = new Node(20);
    // Node *third = new Node(30);
    // Node *fourth = new Node(40);
    // Node *fifth = new Node(50);

    // linked list created here
    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;

    // Node *head = first;
    // Node *tail = fifth;
    // printLL(head);
    // lengthLL(head);
    // insertAtHead(head,tail,33);
    // printLL(head);
    // insertAtTail(head,tail,44);
    // printLL(head);

    Node *head = NULL;
    Node *tail = NULL;

    // insertAtHead(head,tail,10);
    // insertAtHead(head,tail,20);
    // insertAtHead(head,tail,30);
    // insertAtTail(head,tail,50);
    // printLL(head);

    insertAtTail(head,tail,10);
    insertAtTail(head,tail,20);
    insertAtTail(head,tail,30);
    insertAtTail(head,tail,50);
    printLL(head);
    // insertAtAnyPosition(head,tail,500,2);
    // deleteNode(head,tail,1);  
    // deleteNode(head,tail,4 );
    printLL(head);
    reverseLL(head);
    printLL(head);

} 
#include<iostream>
using namespace std;
// creating a node structure
class Node{
    public:
        int data;
        Node* next;

        // default constructor
        Node(){
            this->next = NULL;
        }

        // parameterized constructor
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

// display the given linked list
void display(Node *head){
    Node *temp = head;
    if(head == NULL){
        cout << "Linked list is empty" << endl;
    }
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

// count nodes of linked list
int countNodes(Node *head){
    Node *temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

// insert at head
void insertAtHead(Node *&head,int data){
    if(head == NULL){
        Node *newNode = new Node(data);
        head = newNode;
    }
    else{
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}

// insert at tail
void insertAtTail(Node *&head,int data){
    if(head == NULL){
        Node *newNode = new Node(data);
        head = newNode;
    }
    else{
        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        Node *newNode = new Node(data);
        temp->next = newNode;
    }
}

// insert at given position
void insertAtGivenPosition(Node *&head,int data,int pos){
    int length = countNodes(head);
    if(pos == 1){
        insertAtHead(head,data);
    }
    else if(pos == length+1){
        insertAtTail(head,data);
    }
    else{
        Node *newNode = new Node(data);
        Node *prev = NULL;
        Node *curr = head;
        while(pos != 1){
            prev = curr;
            curr = curr->next;
            pos--;
        }
        prev->next = newNode;
        newNode->next = curr;
    }
}

// delete head Node
void deleteHeadNode(Node *&head){
    if(head == NULL){
        cout << "Linked List is Empty" << endl;
    }
    else{
        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
}

// delete tail node
void deleteTailNode(Node *&head){
    if(head == NULL){
        cout << "Linked List is empty" << endl;
    }
    // for single node
    else if(head->next == NULL){
        Node *temp = head;
        head = NULL;
        delete temp;
    }
    else{
        Node *prev = NULL;
        Node *curr = head;
        while(curr->next != NULL){
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        curr->next = NULL;
        delete curr;
    }
}

// delete given node
void deleteGivenNode(Node *&head,int pos){
    int length = countNodes(head);
    if(pos == 1){
        deleteHeadNode(head);
    }
    else if(pos == length+1){
        deleteTailNode(head);
    }
    else{
        Node *prev = NULL;
        Node *curr = head;
        while(pos != 1){
            prev = curr;
            curr = curr->next;
            pos--;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main(){
    Node *head = NULL;
    int choice,data,pos;
    while(true){
        cout << "Select Operation: " << endl;
        cout << "1. Display the linked list" << endl;
        cout << "2. Count Nodes of linked list" << endl;
        cout << "3. Insert at head node" << endl;
        cout << "4. Insert at tail node" << endl;
        cout << "5. Insert at any given position" << endl;
        cout << "6. Delete head node" << endl;
        cout << "7. Delete tail node" << endl;
        cout << "8. Delete the given node" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch(choice){
            case 1: display(head);
                break;
            case 2: cout << "Total Nodes: " << countNodes(head) << endl;
                break;
            case 3: cout << "Enter data for node: " << endl;
                cin >> data;
                insertAtHead(head,data) ;
                break;
            case 4: cout << "Enter data for node: " << endl;
                cin >> data;
                insertAtTail(head,data);
                break;
            case 5: cout << "Enter data for node: " << endl;
                cin >> data;
                cout << "Enter the position: " << endl;
                cin >> pos;
                insertAtGivenPosition(head,data,pos);
                break;
            case 6: deleteHeadNode(head);
                break;
            case 7: deleteTailNode(head);
                break;
            case 8: cout << "Enter the position: " << endl;
                cin >> pos;
                deleteGivenNode(head,pos);
                break;
            case 9: cout << "Exiting..." << endl;
                return 0;
            default: cout << "Invalid choice, Please try again" << endl;
        }
    }
    return 0;
}
#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *prev;
        Node *next;

        // default constructor
        Node(){
            this->prev = NULL;
            this->next = NULL;
        }

        // paramaterized constructor
        Node(int data){
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
};

// display the linked list
void display(Node *head){
    if(head == NULL){
        cout << "Linked list is empty" << endl;
        return;
    }
    else{
        Node *temp = head;
        do {
            cout << temp->data << "->";
            temp = temp->next;
        } while(temp != head);
        cout << endl;
    }
}

// count nodes of linked list
int countNodes(Node *head){
    if(head == NULL){
        return 0;
    }
    int count = 0;
    Node *temp = head;
    do{
        count++;
        temp = temp->next;
    }while(temp != head);
    return count;
}

// insert at head node
void insertAtHead(Node *&head, int data){
    Node *newNode = new Node(data);
    if(head == NULL){
        newNode->prev = newNode;
        newNode->next = newNode;
        head = newNode;
    }
    else{
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}

// insert at tail node
void insertAtTail(Node *&head,int data){
    if(head == NULL){
        Node *newNode = new Node(data);
        newNode->prev = newNode;
        newNode->next = newNode;
        head = newNode;
    }
    else{
        Node *newNode = new Node(data);
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
    }
}

// insert at any position
void insertAtAnyPosition(Node *&head,int data,int pos){
    int length = countNodes(head);
    // if insert at first node
    if(pos == 1){
        insertAtHead(head,data);
    }
    // if insert at last node
    else if(pos == length+1){
        insertAtTail(head,data);
    }
    // if single node is present
    else if(head->next == head){
        Node *newNode = new Node(data);
        newNode->next = head;
        newNode->prev = head;
        head->prev = newNode;
        head->next = newNode;
    }
    else{
        Node *newNode = new Node(data);
        Node *temp = head;
        while(pos != 1){
            pos--;
            temp = temp->next;
        }
        newNode->prev = temp->prev;
        newNode->next = temp;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }
}

// delete head node
void deleteHeadNode(Node *&head){
    if(head == NULL){
        cout << "Linked list is empty" << endl;
        return;
    }
    else if(head->next == head){
        Node *temp = head;
        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
        head = NULL;
    }
    else{
        Node *temp = head;
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        head = head->next;
        temp->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
}

// delete tail node
void deleteTailNode(Node *&head){
    if(head == NULL){
        cout << "Linked list is empty" << endl;
        return;
    }
    else if(head->next == head){
        Node *temp = head;
        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
        head = NULL;
    }
    else{
        Node *temp = head->prev;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
}

// delete at any position
void deleteAtAnyPosition(Node *&head,int pos){
    int length = countNodes(head);

    if(pos == 1){
        deleteHeadNode(head);
    }
    else if(pos == length+1){
        deleteTailNode(head);
    }
    else{
        Node *temp = head;
        while(pos != 1){
            pos--;
            temp =temp->next;
        }
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        temp->prev = NULL;
        temp->next = NULL;
        delete temp;
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
                insertAtAnyPosition
                (head,data,pos);
                break;
            case 6: deleteHeadNode(head);
                break;
            case 7: deleteTailNode(head);
                break;
            case 8: cout << "Enter the position: " << endl;
                cin >> pos;
                deleteAtAnyPosition(head,pos);
                break;
            case 9: cout << "Exiting..." << endl;
                return 0;
            default: cout << "Invalid choice, Please try again" << endl;
        }
    }
}


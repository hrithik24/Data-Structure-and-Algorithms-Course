#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;

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

// display the linked list
void display(Node *head){
    if(head == NULL){
        cout << "Linked list is empty" << endl;
    }
    else{
        Node *temp = head;
        do{
            cout << temp->data << "->";
            temp = temp->next;
        }while(temp != head);
        cout << endl;
    }
}

// count nodes in linked list
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
void insertAtHead(Node *&head,int data){
    // case 1:- If linked list is empty
    if(head == NULL){
        Node *newNode = new Node(data);
        head = newNode;
        head->next = head;
    }
    // case 2:- If linked list is not empty
    else{
        Node *newNode = new Node(data);
        newNode->next = head;
        Node *temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        head = newNode;

    }
}

// insert at tail node
void insertAtTail(Node *&head,int data){
    // case 1:- if linked list is empty
    if(head == NULL){
        Node *newNode = new Node(data);
        head = newNode;
        head->next = head;
    }
    // case 2:- If linked list is not empty
    else{
        Node *temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        Node *newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// insert at any given position
void insertAtAnyGivenPosition(Node *&head,int data,int pos){
    int length = countNodes(head);

    // if inserting at head node
    if(pos == 1){
        insertAtHead(head,data);
    }
    // if inserting at tail node
    else if(pos == length+1){
        insertAtTail(head,data);
    }
    // if single node is present
    else if(head->next == head){
        Node *newNode = new Node(data);
        newNode->next = head->next;
        head->next = newNode;
    }
    // insert at any position
    else{
        Node *prev = NULL;
        Node *curr = head;
        while(pos != 1){
            pos--;
            prev = curr;
            curr = curr->next;
        }
        Node *newNode = new Node(data);
        prev->next = newNode;
        newNode->next = curr;
    }
}

// delete head node
void deleteHeadNode(Node *&head){
    if(head == NULL){
        cout << "Linked List is empty" << endl;
    }
    else{
        Node *temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        Node *ptr = head;
        temp->next = ptr->next;
        ptr->next = NULL;
        head = temp->next;
        delete ptr;
    }
}

// delete tail node
void deleteTailNode(Node *&head){
    if(head == NULL){
        cout << "Linked list is empty" << endl;
    }
    else{
        Node *curr = head;
        Node *prev = NULL;
        while(curr->next != head){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

// delete from any postion
void deleteAtAnyPosition(Node *&head,int pos){
    int length = countNodes(head);
    if(pos == 1){
        deleteHeadNode(head);
    }
    else if(pos == length+1){
        deleteTailNode(head);
    }
    else if(head->next == head){
        Node *temp = head;
        temp->next = NULL;
        delete temp;
        head = NULL;
    }
    else{
        Node *prev = NULL;
        Node *curr = head;
        while(pos != 1){
            pos--;
            prev = curr;
            curr = curr->next;
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
                insertAtAnyGivenPosition(head,data,pos);
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
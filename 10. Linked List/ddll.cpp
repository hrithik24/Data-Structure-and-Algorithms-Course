#include<iostream>
using namespace std;
// creating node structure
class Node{
    public:
        int data;
        Node *next;
        Node *prev;

        // default constructor
        Node(){
            this->prev = NULL;
            this->next = NULL;
        }

        // parameterized constructor
        Node(int data){
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
};

// display linked list
void display(Node *head){
    if(head == NULL){
        cout << "Linked list is empty" << endl;
    }
    else{
        Node *temp = head;
        while(temp != NULL){
            cout << temp->data << "->";
            temp = temp->next;
        }
    }
    cout << endl;
}

// count nodes of linked list
int countNodes(Node *head){
    int count = 0;
    Node *temp = head;
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
        head->prev = newNode;
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
        newNode->prev = temp;
    }
}

// insert at any position
void insertAtAnyGivenPosition(Node *&head,int data,int pos){
    int length = countNodes(head);
    if(pos == 1){
        insertAtHead(head,data);
    }
    else if(pos == length+1){
        insertAtTail(head,data);
    }
    else{
        Node *temp = head;
        while(pos != 1){
            pos--;
            temp = temp->next;
        }
        Node *newNode = new Node(data);
        newNode->prev = temp->prev;
        newNode->next = temp;
        newNode->prev->next = newNode;
        newNode->next->prev = newNode;
    }
}

// delete head node
void deleteHeadNode(Node *&head){
    if(head == NULL){
        cout << "Linked list is empty" << endl;
    }
    else{
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
}

// delete tail node
void deleteTailNode(Node *&head){
    if(head == NULL){
        cout << "Linked list is empty" << endl;
    }
    else{
        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->prev->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
}

// delete from any position
void deleteAtGivenPosition(Node *&head,int pos){
    int length = countNodes(head);

    if(pos == 1){
        deleteHeadNode(head);
    }
    else if(pos == length+1){
        deleteTailNode(head);
    }
    else if(head->next == NULL){
        Node *temp = head;
        delete temp;
        head = NULL;
    }
    else{
        Node *temp = head;
        while(pos != 1){
            pos--;
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
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
                insertAtAnyGivenPosition(head,data,pos);
                break;
            case 6: deleteHeadNode(head);
                break;
            case 7: deleteTailNode(head);
                break;
            case 8: cout << "Enter the position: " << endl;
                cin >> pos;
                deleteAtGivenPosition(head,pos);
                break;
            case 9: cout << "Exiting..." << endl;
                return 0;
            default: cout << "Invalid choice, Please try again" << endl;
        }
    }

}
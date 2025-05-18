#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << front->data << " ";
            if(front->left != NULL){
                q.push(front->left);
            }
            if(front->right != NULL){
                q.push(front->right);
            }
        }
    }
}

void convertBSTtoDLL(Node* root,Node* &head){
    if(root == NULL){
        return;
    }

    // RNL
    convertBSTtoDLL(root->right,head);

    root->right = head;
    if(head != NULL){
        head->left = root;
    }
    head = root;

    convertBSTtoDLL(root->left,head);
}

void printLinkedList(Node* head){
    Node* temp = head;
    cout << "Printing the entire linked list: " << endl;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->right;
    }
}

Node* convertDLLtoBST(Node* &head,int n){
    // base case
    if(head == NULL || n<=0){
        return NULL;
    }

    //LNR
    // L
    Node* leftSubtree = convertDLLtoBST(head,n/2);
    //N
    Node* root = head;
    root->left = leftSubtree;
    // head update
    head = head->right;

    //R
    Node* rightSubtree = convertDLLtoBST(head,n-n/2-1);
    root->right = rightSubtree;

    return root;

}
int main(){
    Node* root = new Node(40);
    root->left = new Node(20);
    root->right = new Node(60);
    root->left->left = new Node(10);
    root->left->right = new Node(30);
    root->right->left = new Node(50);
    root->right->right = new Node(70);
    Node* head = NULL;
    
    convertBSTtoDLL(root,head);
    printLinkedList(head);
    cout << endl;

    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    first->right = second;
    second->left = first;
    second->right = third;
    third->left = second;

    Node* h1 = first;
    Node* r1 = convertDLLtoBST(h1,3);
    levelOrderTraversal(r1);

}
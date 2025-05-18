#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* createTree(){
    int data;
    cout << "Enter the value for node: " << endl;
    cin >> data;

    // base case
    if(data == -1){
        return NULL;
    }

    // Step 1:- Create node
    Node* root = new Node(data);

    // Step 2:- Create left subtree
    cout << "left of node: " << root->data << endl;
    root->left = createTree();

    // Step 3:- Create right subtree
    cout << "right of node: " << root->data << endl;
    root->right = createTree();

    return root;
}

void preOrderTraversal(Node* root){
    // base case
    if(root == NULL){
        return;
    }

    // NLR
    // N
    cout << root->data << " ";
    // L
    preOrderTraversal(root->left);
    //R
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root){
    // base case
    if(root == NULL){
        return;
    }

    // LNR
    // L
    inOrderTraversal(root->left);
    // N
    cout << root->data << " ";
    // R
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }

    // LRN
    // L
    postOrderTraversal(root->left);
    // R
    postOrderTraversal(root->right);
    // N
    cout << root->data << " ";
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        cout << front->data << " ";

        if(front->left != NULL) {
            q.push(front->left);
        }
        if(front->right != NULL){
            q.push(front->right);
        }
    }
}

void levelTraversal(Node* root){
    queue<Node*> q;
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

            if(front->left != NULL) {
                q.push(front->left);
            }
            if(front->right != NULL){
                q.push(front->right);
            }
        }
    }
}

int main(){
    Node* root = createTree();
    // cout << root->data << endl;
    cout << "PreOrder Traversal: ";
    preOrderTraversal(root);
    cout << endl;
    cout << "InOrder Traversal: ";
    inOrderTraversal(root);
    cout << endl;
    cout << "PostOrder Traversal: ";
    postOrderTraversal(root);
    cout << endl;
    cout << "LevelOrder Traversal: ";
    levelOrderTraversal(root);
    cout << endl;
    cout << "LevelOrder Traversal level by level: ";
    levelTraversal(root);
    cout << endl;
}
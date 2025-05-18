#include<iostream>
#include<vector>
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

void storeInorderTraversal(Node* root, vector<int>& in){
    if(root == NULL){
        return;
    }
    //LNR
    storeInorderTraversal(root->left,in);
    in.push_back(root->data);
    storeInorderTraversal(root->right,in);
}
void replaceUsingPostOrder(Node* root,vector<int> in,int& index){
    if(root == NULL){
        return;
    }

    //LRN
    replaceUsingPostOrder(root->left,in);
    replaceUsingPostOrder(root->right,in);
    root->data = in[index];
    index++;
}
void convertBSTIntoMaxHeap(Node* root){
    // 1. store inorder
    vector<int> inorder;
    storeInorderTraversal(root,inorder);
    // replace the node values with the sorted inorder values,using the postorder traversal
    int index = 0;
    replaceUsingPostOrder(root,inorder,index);
    return root;
}
int main(){

}
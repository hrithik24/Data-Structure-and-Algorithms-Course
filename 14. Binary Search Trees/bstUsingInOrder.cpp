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


Node* bstFromInorder(int inorder[],int start,int end){
    // base case
    if(start > end){
        return NULL;
    }
 
    // 1 case me solve karunga
    int mid = (start+end) / 2;
    int element = inorder[mid];
    Node* root = new Node(element);

    // baaki recursion sambhal lega
    root->left = bstFromInorder(inorder,start,mid-1);
    root->right = bstFromInorder(inorder,mid+1,end);
    return root;

}
int main(){
    int inorder[] = {10,20,30,40,50,60,70};
    int size = 7;
    int start = 0;
    int end = size - 1;
    Node* root = bstFromInorder(inorder,start,end);

    levelOrderTraversal(root);

}

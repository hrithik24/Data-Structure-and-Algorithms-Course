#include<iostream>
#include<queue>
#include<map>
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

// Node* createTree(){
//     int data;
//     cout << "Enter the value for node: " << endl;
//     cin >> data;

//     // base case
//     if(data == -1){
//         return NULL;
//     }

//     // Step 1:- Create node
//     Node* root = new Node(data);

//     // Step 2:- Create left subtree
//     cout << "left of node: " << root->data << endl;
//     root->left = createTree();

//     // Step 3:- Create right subtree
//     cout << "right of node: " << root->data << endl;
//     root->right = createTree();

//     return root;
// }

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

int searchInorder(int inOrder[],int size,int target){
    for(int i=0;i<size;i++){
        if(inOrder[i] == target){
            return i;
        }
    }
    return -1;
}

void createMapping(int inOrder[],int size,map<int,int> &valueToIndexMap){
    for(int i=0;i<size;i++){
        int element = inOrder[i];
        int index = i;
        valueToIndexMap[element] = index;
    }
}

Node* constructTreeFromPreAndInorderTraversal(map<int,int> &valueToIndexMap,int preOrder[],int inOrder[],int &preIndex,int inOrderStart,int inOrderEnd,int size){
    // base case
    if(preIndex >= size || inOrderStart > inOrderEnd){
        return NULL;
    }

    // 1 case main solve karunga
    int element = preOrder[preIndex];
    preIndex++;
    Node* root = new Node(element);
    // element search karna padega inorder me
    // int position = searchInorder(inOrder,size,element);
    int position = valueToIndexMap[element];

    // baaki recursion sambhal lega
    root->left = constructTreeFromPreAndInorderTraversal(valueToIndexMap,preOrder,inOrder,preIndex,inOrderStart,position-1,size);
    root->right = constructTreeFromPreAndInorderTraversal(valueToIndexMap,preOrder,inOrder,preIndex,position+1,inOrderEnd,size);

    return root;

}

Node* constructTreeFromPostAndInorderTraversal(map<int,int> &valueToIndexMap,int postOrder[],int inOrder[],int &postIndex,int inOrderStart,int inOrderEnd,int size){
    // base case
    if(postIndex < 0 || inOrderStart > inOrderEnd){
        return NULL;
    }
 
    // 1 case main solve karunga
    int element = postOrder[postIndex];
    postIndex--;
    Node* root = new Node(element);
    // element search karna padega inorder me
    // int position = searchInorder(inOrder,size,element);
    int position = valueToIndexMap[element];

    // baaki recursion sambhal lega
    root->right = constructTreeFromPostAndInorderTraversal(valueToIndexMap,postOrder,inOrder,postIndex,position+1,inOrderEnd,size);
    root->left = constructTreeFromPostAndInorderTraversal(valueToIndexMap,postOrder,inOrder,postIndex,inOrderStart,position-1,size);

    return root;

}

int main(){
    int inOrder[] = {10,8,6,2,4,12};
    int preOrder[] = {2,8,10,6,4,12};
    int postOrder[] = {10,6,8,12,4,2};
    int size = 6;
    int preOrderIndex = 0;
    int inOrderStart = 0;
    int inOrderEnd = 5;
    int postIndex = size-1;

    map<int,int> valueToIndexMap;
    createMapping(inOrder,size,valueToIndexMap);
    
    Node* root = constructTreeFromPreAndInorderTraversal(valueToIndexMap,preOrder,inOrder,preOrderIndex,inOrderStart,inOrderEnd,size);
    cout << "Printing the entire tree: " << endl;
    levelTraversal(root);

    Node* r1 = constructTreeFromPostAndInorderTraversal(valueToIndexMap,postOrder,inOrder,postIndex,inOrderStart,inOrderEnd,size);
    cout << "Printing the entire tree: " << endl;
    levelTraversal(r1);
    return 0;
}
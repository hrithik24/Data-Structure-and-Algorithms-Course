#include<iostream>
#include<queue>
#include<map>
using namespace std;
// Node creation for tree
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

// createTree function
Node* createTree(){
    int data;
    cout << "Enter the data for node: " << endl;
    cin >> data;

    if(data == -1){
        return NULL;
    }

    // root node creation
    Node* root = new Node(data);
    // left child
    cout << "left of node: " << root->data << endl;
    root->left = createTree();

    // right child
    cout << "right of node: " << root->data << endl;
    root->right = createTree();

    return root;
}

// preorder traversal
void preOrderTraversal(Node* root){
    // base case
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// inorder Traversal
void inOrderTraversal(Node* root){
    // base case
    if(root == NULL){
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// postorder Traversal
void postOrderTraversal(Node* root){
    // base case
    if(root == NULL){
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

// levelOrder Traversal
void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        // print the element
        cout << front->data << " ";

        // left child
        if(front->left != NULL){
            q.push(front->left);
        }

        // right child
        if(front->right != NULL){
            q.push(front->right);
        }
    }
}

// levelOrder Traversal(level by level)
void levelByLevelTraversal(Node* root){
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

// create Mapping for elements of Inorder Traversal
void createMapping(int inOrder[],int size,map<int,int> &valueToIndexMap){
    for(int i=0;i<size;i++){
        int element = inOrder[i];
        int index = i;
        valueToIndexMap[element] = index;
    }
}

// binary tree using PreOrder and InOrder Traversal
Node* constructTreeUsingPreAndInorderTraversal(map<int,int> &valueToIndexMap,int preOrder[],int inOrder[],int &preOrderIndex,int inOrderstart,int inOrderEnd,int size){
    // base case
    if(preOrderIndex >= size || inOrderstart > inOrderEnd){
        return NULL;
    }

    // 1 case mein solve karunga
    int element = preOrder[preOrderIndex];
    preOrderIndex++;

    Node* root = new Node(element);

    // element search karna padega inorder me
    int position = valueToIndexMap[element];

    // baaki recursion sambhal lega
    root->left = constructTreeUsingPreAndInorderTraversal(valueToIndexMap,preOrder,inOrder,preOrderIndex,inOrderstart,position-1,size);
    root->right = constructTreeUsingPreAndInorderTraversal(valueToIndexMap,preOrder,inOrder,preOrderIndex,position+1,inOrderEnd,size);
    return root;
}

// binary tree using PreOrder and InOrer Traversal
Node* constructTreeUsingPostAndInorderTraversal(map<int,int> &valueToIndexMap,int postOrder[],int inOrder[],int &postOrderIndex,int inOrderStart,int inOrderEnd,int size){
    // base case
    if(postOrderIndex < 0 || inOrderStart > inOrderEnd){
        return NULL;
    }

    int element = postOrder[postOrderIndex];
    postOrderIndex--;

    Node* root = new Node(element);
    int position = valueToIndexMap[element];

    root->right = constructTreeUsingPostAndInorderTraversal(valueToIndexMap,postOrder,inOrder,postOrderIndex,position+1,inOrderEnd,size);
    root->left = constructTreeUsingPostAndInorderTraversal(valueToIndexMap,postOrder,inOrder,postOrderIndex,inOrderStart,position-1,size);
    
    return root;
}

// left view of binary tree
void printLeftView(Node* root,int level,vector<int> &leftView){
    // base case
    if(root == NULL){
        return;
    }

    if(level == leftView.size()){
        leftView.push_back(root->data);
    }

    printLeftView(root->left,level+1,leftView);
    printLeftView(root->right,level+1,leftView);
}

// right view of binary tree
void printRightView(Node* root,int level,vector<int> &rightView){
    // base case
    if(root == NULL){
        return;
    }

    if(level == rightView.size()){
        rightView.push_back(root->data);
    }

    printRightView(root->right,level+1,rightView);
    printRightView(root->left,level+1,rightView);
}

// top view of binary tree
void printTopView(Node* root){
    map<int,int> hdToNodeMap;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        if(hdToNodeMap.find(hd) == hdToNodeMap.end()){
            hdToNodeMap[hd] = frontNode->data;
        }

        if(frontNode->left != NULL){
            q.push(make_pair(frontNode->left,hd-1));
        }

        if(frontNode->right != NULL){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }

    cout << "Printing the top view: " << endl;
    for(auto i: hdToNodeMap){
        cout << i.second << " ";
    }
    cout << endl;
}

// bottom view of binary tree
void printBottomView(Node* root){
    map<int,int> hdToNodeMap;
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        hdToNodeMap[hd] = frontNode->data;

        if(frontNode->left != NULL){
            q.push(make_pair(frontNode->left,hd-1));
        }

        if(frontNode->right != NULL){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }

    cout << "Printing the bottom view: " << endl;
    for(auto i: hdToNodeMap){
        cout << i.second << " ";
    }
    cout << endl;
}

// boundary traversal -> printLeftBoundary , printLeafBoundary, printRightBoundary

void printLeftBoundary(Node* root){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        return;
    }

    cout << root->data << " ";
    if(root->left != NULL){
        printLeftBoundary(root->left);
    }
    else{
        printLeftBoundary(root->right);
    }
}

void printLeafBoundary(Node* root){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        cout << root->data << " ";
    }

    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
}

void printRightBoundary(Node* root){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        return;
    }

    if(root->right != NULL){
        printRightBoundary(root->right);
    }
    else{
        printRightBoundary(root->left);
    }
    cout << root->data << " ";
}

void boundaryTraversal(Node* root){
    if(root == NULL){
        return;
    }

    printLeftBoundary(root);
    printLeafBoundary(root);
    if(root->right != NULL){
        printRightBoundary(root->right);
    }
    else{
        printRightBoundary(root->left);
    }
}

int main(){
    Node* root = createTree();
    cout << "PreOrder Traversal: " << endl;
    preOrderTraversal(root);
    cout << endl;
    cout << "InOrder Traversal: " << endl;
    inOrderTraversal(root);
    cout << endl;
    cout << "PostOrder Traversal: " << endl;
    postOrderTraversal(root);
    cout << endl;
    cout << "LevelOrder Traversal: " << endl;
    levelOrderTraversal(root);
    cout << endl;
    cout << "LevelOrder Traversal Level by Level: " << endl;
    levelByLevelTraversal(root);
    cout << endl;
    
    int inOrder[] = {10,8,6,2,4,12};
    int preOrder[] = {2,8,10,6,4,12};
    int size = 6;
    int preOrderIndex = 0;
    int inOrderStart = 0;
    int inOrderEnd = 5;
    map<int,int> valueToIndexMap;
    createMapping(inOrder,size,valueToIndexMap);
    
    Node* r1 = constructTreeUsingPreAndInorderTraversal(valueToIndexMap,preOrder,inOrder,preOrderIndex,inOrderStart,inOrderEnd,size);
    cout << "Printing the entire tree: " << endl;
    levelByLevelTraversal(r1);
    
    int postOrder[] = {10,6,8,12,4,2};
    int postOrderIndex = size - 1;
    cout << "Printing the entire Tree: " << endl;
    Node* r2 = constructTreeUsingPostAndInorderTraversal(valueToIndexMap,postOrder,inOrder,postOrderIndex,inOrderStart,inOrderEnd,size);
    levelByLevelTraversal(r2);

    int level = 0;
    vector<int> leftView;
    cout << "Printing the left View of Binary tree: " << endl;
    printLeftView(root,level,leftView);
    for(int i=0;i<leftView.size();i++){
        cout << leftView[i] << " ";
    }
    cout << endl;

    vector<int> rightView;
    cout << "Printing the right View of Binary tree: " << endl;
    printRightView(root,level,rightView);
    for(int i=0;i<rightView.size();i++){
        cout << rightView[i] << " ";
    }
    cout << endl;

    printTopView(root);

    printBottomView(root);

    cout << "Boundary Traversal: " << endl;
    boundaryTraversal(root);

}
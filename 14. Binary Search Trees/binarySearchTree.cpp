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

Node* insertIntoBST(Node* root,int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    // if it is not the first node
    if(data > root->data){
        root->right = insertIntoBST(root->right,data);
    }
    else{
        root->left = insertIntoBST(root->left,data);
    }
    return root;

}

void createBST(Node* &root){
    int data;
    cout << "Enter the data of node: " << endl;
    cin >> data;

    while(data != -1){
        root = insertIntoBST(root,data);
        cout << "Enter data: " << endl;
        cin >> data;
    }
}

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

void preOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

Node* minValue(Node* root){
    if(root == NULL){
        cout << "No Minimum Value" << endl;
        return NULL;
    }
    Node* temp = root;

    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

Node* maxValue(Node* root){
    if(root == NULL){
        cout << "No Maximum Value" << endl;
        return NULL;
    }
    Node* temp = root;

    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

bool searchInBST(Node* root,int target){
    // base case
    if(root == NULL){
        return false;
    }

    // 1 case mujhe solve karna h
    if(root->data == target){
        return true;
    }

    // baaki recusion smbhal lega
    bool leftAns = false;
    bool rightAns = false;
    if(target > root->data){
        rightAns = searchInBST(root->right,target);
    }
    else{
        leftAns = searchInBST(root->left,target);
    }

    return leftAns || rightAns;
}

Node* deleteFromBST(Node* root,int target){
    // base case
    if(root == NULL){
        return NULL;
    }

    // target ko dhundo
    if(root->data == target){
        // ab delete karenge
        // 4 cases

        // 1 case of leaf node
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // 2 case left non null and right null
        else if(root->left != NULL && root->right == NULL){
            Node* childSubtree = root->left;
            delete root;
            return childSubtree;
        }
        // 3 case right non null and left null
        else if(root->right != NULL && root->left == NULL){
            Node* childSubtree = root->right;
            delete root;
            return childSubtree;
        }
        // 4 case left non null && right non null
        else{
            // left subtree ke max value
            Node* maxi = maxValue(root->left);
            // replacement
            root->data = maxi->data;

            // delete actual maxi wali node
            root->left = deleteFromBST(root->left,maxi->data);
            return root;

        }
    }
    else if(root->data > target){
        root->left = deleteFromBST(root->left,target);
    }
    else{
        root->right = deleteFromBST(root->right,target);
    }
    return root;
}

int main(){
    Node* root = NULL;
    createBST(root);
    cout << "Level by level order traversal: " << endl;
    levelOrderTraversal(root);
    cout << endl;
    cout << "PreOrder Traversal: " << endl;
    preOrderTraversal(root);
    cout << endl;
    cout << "InOrder Traversal: " << endl;
    inOrderTraversal(root);
    cout << endl;
    cout << "PostOrder Traversal: " << endl;
    postOrderTraversal(root);
    cout << endl;
    Node* minNode = minValue(root);
    if(minNode == NULL){
        cout << "There is no node is tree so no min value." << endl;
    }
    else{
        cout << "Min Value: " << minNode->data << endl;
    }

    Node* maxNode = maxValue(root);
    if(maxNode == NULL){
        cout << "There is no node is tree so no max value." << endl;
    }
    else{
        cout << "Max Value: " << maxNode->data << endl;
    }

    int target;
    cout << "Enter the target: " << endl;
    cin >> target;
    while(target != -1){
        bool ans = searchInBST(root,target);
        if(ans == true){
            cout << "Element Found" << endl;
        }
        else{
            cout << "Element Not Found" << endl;
        }
        cout << "Enter the target: " << endl;
        cin >> target;
    }

    int t1;
    cout << "Enter the element to delete: ";
    cin >> t1;
    while(t1 != -1){
        root = deleteFromBST(root,t1);
        cout << "Printing Level Order Traversal: " << endl;
        levelOrderTraversal(root);

        cout << "Enter the element to delete: " << endl;
        cin >> t1;
    }
 
}
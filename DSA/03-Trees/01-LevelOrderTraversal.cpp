#include <iostream>
#include <queue>
using namespace std;

class node {
    public: 
    int data;
    node* left;
    node* right;
    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node *buildTree(node* root) {
    cout<<"Enter the data: "<<endl; 
    int data;
    cin>>data;
    root = new node(data);
    
    if(data == -1) {
        return NULL;
    } 
    
    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left); 
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right); 
    return root;
} 

void levelOrderTraversal(node* root) {
    queue<node*>q;
    q.push(root);
    
    while(!q.empty()) {
        node* temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        
        if(temp==NULL) { //purana level complete traverse ho chuka hai
        cout<<endl;
        if(q.empty()) { //queue still has some child nodes 
        q.push(NULL);
        }
        } else {
        if(temp->left) {
            q.push(temp->left);
        } 
        if(temp->right) {
            q.push(temp->right);
        } 
        }
    }
}

int main() {
    node* root = NULL; 
    
    //creating a tree
    root = buildTree(root);
    
    //print level order traversal
    cout<<"Printing the level order traversal: "<<endl;
    levelOrderTraversal(root);
    return 0;
}

/* Sample input -> 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 */

/*
Function	           Time Complexity	     Space Complexity (Worst Case)	 Space Complexity (Average Case)
buildTree()	                O(N)	                   O(N)	                               O(log N)
levelOrderTraversal()	    O(N)	                   O(N)	                                  O(N)
main()	                    O(N)	                   O(N)	                                O(log N)
Overall	                    O(N)	                   O(N)	                                  O(N)
*/
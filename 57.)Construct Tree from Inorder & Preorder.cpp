//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int findpos(int in[],int element,int n){
        for(int i=0;i<n;i++){
            if(element==in[i])
            return i;
        }
        return -1;
    }
    Node* solve(int in[],int pre[], int &index,int start,int end,int n){
        if(start>end)
        return NULL;
        if(index>=n)
        return NULL;
    
        int element=pre[index];
        index++;
        Node* root=new Node(element);
        int pos=findpos(in,element,n);
        root->left=solve(in,pre,index,start,pos-1,n);
        root->right=solve(in,pre,index,pos+1,end,n);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int index=0;
    Node* root=solve(in,pre,index,0,n-1,n);  
    return root;
        
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


// } Driver Code Ends
/*
// structure of the node is as follows

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/
class Solution
{
   private:
   void insertattail(Node*&Head,int val){
       Node*temp=new Node(val);
       if(Head==NULL){
           Head=temp;
           return;
       }
       else{
           Node*temp1=Head;
           while(temp1->next!=NULL){
               temp1=temp1->next;
           }
           temp1->next=temp;
       }
   }
   
   
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        set<int>st;
        Node*temp=head1;
        Node*temp1=head2;
        Node*HEAD=NULL;
        while(temp!=NULL){
            st.insert(temp->data);
            temp=temp->next;
        }
        while(temp1!=NULL){
            st.insert(temp1->data);
            temp1=temp1->next;
        }
        for(auto it:st){
            insertattail(HEAD,it);
        }
        return HEAD;
    }
};


//{ Driver Code Starts.

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends
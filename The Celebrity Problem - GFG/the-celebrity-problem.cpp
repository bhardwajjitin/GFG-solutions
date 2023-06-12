//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int row=M.size();
        int column=M[0].size();
        vector<int>count(row);
        for(int i=0;i<row;i++){
            int c=0;
            for(int j=0;j<column;j++){
                if(M[i][j]==0 && i!=j){
                   c++;
                }
            }
            count[i]=c;
        }
        vector<int>count1(column);
        for(int j=0;j<column;j++){
            int c1=0;
            for(int i=0;i<row;i++){
                if(M[i][j]==1){
                   c1++;
                }
            }
            count1[j]=c1;
        }
        for(int i=0;i<count1.size();i++){
            if(count[i]==row-1 && count1[i]==column-1){
                return i;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends
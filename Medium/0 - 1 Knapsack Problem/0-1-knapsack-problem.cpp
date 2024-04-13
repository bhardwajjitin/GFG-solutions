//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
    int solve(int W,int wt[], int val[], int n,int ind,vector<vector<int>>&dp){
        if(ind<0)return 0;
        if(dp[ind][W]!=-1)return dp[ind][W];
        int inc=0;
        int exc=solve(W,wt,val,n,ind-1,dp);
        if(W>=wt[ind]){
            inc=val[ind]+solve(W-wt[ind],wt,val,n,ind-1,dp);
        }
        return dp[ind][W]=max(inc,exc);
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
    //   vector<vector<int>>dp(n,vector<int>(W+1,-1));
    //   return solve(W,wt,val,n,n-1,dp);
    //   vector<vector<int>>dp(n+1,vector<int>(W+1,0));
    //   for(int i=1;i<=n;i++){
    //       for(int w=0;w<=W;w++){
    //           int inc=0;
    //           int exc=dp[i-1][w];
    //           if(w>=wt[i-1]){
    //               inc=val[i-1]+dp[i-1][w-wt[i-1]];
    //             }
    //         dp[i][w]=max(inc,exc);
    //       }
    //   }
    //   return dp[n][W];
       
    //   space optimisation
     vector<int>prev(W+1,0),curr(W+1,0);
      for(int i=1;i<=n;i++){
          for(int w=0;w<=W;w++){
              int inc=0;
              int exc=prev[w];
              if(w>=wt[i-1]){
                  inc=val[i-1]+prev[w-wt[i-1]];
                }
            curr[w]=max(inc,exc);
          }
          prev=curr;
      }
      return prev[W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
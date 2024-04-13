//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    int solve(int n,int target,int arr[],int ind,vector<vector<int>>&dp){
        if(target==0)return 1;
        if(ind<0)return 0;
        if(dp[ind][target]!=-1)return dp[ind][target];
        int inc=0;
        int exc=solve(n,target,arr,ind-1,dp);
        if(target>=arr[ind]){
            inc=solve(n,target-arr[ind],arr,ind-1,dp);
        }
        return dp[ind][target]=inc|exc;
    }
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0)return 0;
        vector<vector<int>>dp(N,vector<int>(sum+1,-1));
        return solve(N,sum/2,arr,N-1,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
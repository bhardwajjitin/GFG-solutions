//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    private:
    bool solve(string&wild,string&patt,int i,int j,vector<vector<int>>&dp){
        if(i<0 && j<0)return true;
        if(i<0 && j>=0)return false;
        if(i>=0 && j<0){
            for(int k=0;k<=i;k++){
                if(wild[k]!='*')return false;
            }
            return true;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(wild[i]==patt[j] || wild[i]=='?'){
            return dp[i][j]= solve(wild,patt,i-1,j-1,dp);
        }
        else if(wild[i]=='*'){
            return dp[i][j]= solve(wild,patt,i-1,j,dp)|solve(wild,patt,i,j-1,dp);
        }
        else{
            return dp[i][j]=false;
        }
        
    }
    public:
    bool match(string wild, string pattern)
    {
        int m=wild.size();
        int n=pattern.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(wild,pattern,m-1,n-1,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
    private:
    void solve(vector<int>&arr,vector<int>&ans,int index,int size,int sum){
        if(index>=size){
            ans.push_back(sum);
            return;
        }
        sum+=arr[index];
        solve(arr,ans,index+1,size,sum);
        sum-=arr[index];
        solve(arr,ans,index+1,size,sum);
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>ans;
        solve(arr,ans,0,N,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
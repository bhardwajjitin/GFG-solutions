//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
    void update(stack<long long>&st,vector<long long>&ans,long long element){
        while(!st.empty()){
            if(st.top()>element){
                ans.push_back(st.top());
                st.push(element);
                break;
            }
            else{
                st.pop();
            }
        }
        if(st.empty()){
            ans.push_back(-1);
            st.push(element);
        }
        return;
    }
    public:
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long>ans;
        stack<long long>st;
        for(int i=n-1;i>=0;i--){
           long long temp=arr[i];
            update(st,ans,temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
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
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends
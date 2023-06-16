//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        unordered_map<int,int>umap;
        for(int i=0;i<n;i++){
            umap[arr[i]]++;
        }
        vector<int>ans;
        for(auto temp=umap.begin();temp!=umap.end();temp++){
            int key=temp->first;
            int value=temp->second;
            if(value>1){
                ans.push_back(key);
            }
        }
        sort(ans.begin(),ans.end());
        if(ans.size()==0){
            ans.push_back(-1);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
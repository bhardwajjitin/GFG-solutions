//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int allPoss(vector<vector<int>>&points , int n , int last , int curr , vector<vector<int>>&dp){
        if(curr == 0){
            int maxi = 0;
            for(int i = 0 ; i <= 2 ; i++){
                if(i != last)maxi = max(maxi,points[0][i]);
            }
            return dp[0][last] = maxi;
        }
        
        if(dp[curr][last] != -1)return dp[curr][last];
        
        int maxi = 0;
        for(int i = 0 ; i <= 2 ; i++){
            if(i != last && curr < points.size()){
                int pointScored = points[curr][i]+allPoss(points,n,i,curr-1,dp);
                maxi = max(maxi,pointScored);
            }
        }
        return dp[curr][last] = maxi;
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return allPoss(points,n,3,n-1,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
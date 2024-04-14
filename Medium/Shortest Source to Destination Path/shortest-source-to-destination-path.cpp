//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if(A[X][Y]==0 || A[0][0]==0)return -1;
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},0});
        int ans=INT_MAX;
        int di[]={-1,0,0,1};
        int dj[]={0,-1,1,0};
        vector<vector<int>>vis(N,vector<int>(M,0));
        vis[0][0]=1;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int step=q.front().second;
            q.pop();
            if(row==X && col==Y){
                ans=min(ans,step);
            }
            for(int i=0;i<4;i++){
                int nrow=row+di[i];
                int ncol=col+dj[i];
                if(nrow>=0 && nrow<N && ncol>=0 && ncol<M && A[nrow][ncol]==1 && !vis[nrow][ncol]){
                    q.push({{nrow,ncol},step+1});
                    vis[nrow][ncol]=1;
                }
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends
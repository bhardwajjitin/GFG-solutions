//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    private:
    void toposort(int node,int vis[],stack<int>&st,vector<pair<int,int>>adjlist[]){
        vis[node]=1;
        for(auto it:adjlist[node]){
            int v=it.first;
            if(!vis[v]){
                toposort(v,vis,st,adjlist);
            }
        }
        st.push(node);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>>adjlist[N];
        for(int i=0;i<M;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adjlist[u].push_back({v,wt});
        }
        int vis[N]={0};
        stack<int>st;
        for(int i=0;i<N;i++){
            if(!vis[i]){
                toposort(i,vis,st,adjlist);
            }
        }
        
        vector<int>dis(N);
        for(int i=0;i<N;i++){
            dis[i]=1e9;
        }
        dis[0]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            for(auto it:adjlist[node]){
                int v=it.first;
                int wt=it.second;
                if(dis[node]+wt<dis[v]){
                    dis[v]=dis[node]+wt;
                }
            }
        }
        for(int i=0;i<dis.size();i++){
            if(dis[i]==1e9){
                dis[i]=-1;
            }
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int m=image.size();
        int n=image[0].size();
        queue<pair<pair<int,int>,int>>q;
        q.push({{sr,sc},image[sr][sc]});
        int di[]={-1,0,0,1};
        int dj[]={0,-1,1,0};
        vector<vector<int>>vis(m,vector<int>(n,0));
        vis[sr][sc]=1;
        image[sr][sc]=newColor;
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            int row=top.first.first;
            int col=top.first.second;
            int color=top.second;
            for(int i=0;i<4;i++){
                int nrow=row+di[i];
                int ncol=col+dj[i];
                if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && image[nrow][ncol]==color && !vis[nrow][ncol]){
                    q.push({{nrow,ncol},image[nrow][ncol]});
                    image[nrow][ncol]=newColor;
                    vis[nrow][ncol]=1;
                }
            }
        }
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
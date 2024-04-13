//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        // code 
        map<int,int>mp;
        for(int i=0;i<N;i++){
            int first=arr[2*i];
            int second=arr[2*i+1];
            mp[first]=second;
        }
        queue<pair<int,int>>q;
        q.push({1,0});
        while(true){
            auto top=q.front();
            q.pop();
            if(top.first==30)return top.second;
            for(int i=1;i<=6;i++){
                int temp=top.first+i;
                if(temp<=30){
                    if(mp.find(temp)!=mp.end()){
                        (temp)=mp[temp];
                    }
                    q.push({temp,top.second+1});
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
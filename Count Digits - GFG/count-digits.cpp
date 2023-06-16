//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int evenlyDivides(int N){
        int temp=N;
        int count=0;
        vector<int>ans;
        while(N!=0){
            int r=N%10;
           if(r!=0 && temp%r==0){
               count++;
           }
            N=N/10;
        }
       /* for(int i=0;i<ans.size();i++){
           if(temp%ans[i]==0){
               count++;
           } 
        }*/
        return count;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
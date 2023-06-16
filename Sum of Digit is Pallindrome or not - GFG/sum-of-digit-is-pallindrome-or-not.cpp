//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isDigitSumPalindrome(int N) {
        int s=0;
        while(N!=0){
            int r=N%10;
            s=s+r;
            N=N/10;
        }
        int temp=s;
        int pal=temp;
        int p=0;
        while(temp!=0){
            int r=temp%10;
            p=p*10 + r;
            temp=temp/10;
        }
        if(pal==p){
            return 1;
        }
        return 0;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isDigitSumPalindrome(N) << "\n";
    }
}

// } Driver Code Ends
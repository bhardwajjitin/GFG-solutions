//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n){
        string str;
       int temp=n;
       int s;
      int a=n%10;
      n=n/10;
      int b=n%10;
      n=n/10;
      int c=n%10;
      s=pow(a,3)+pow(b,3)+pow(c,3);
       if(s==temp){
          str="Yes";
       }
       else{
           str="No";
       }
       return str;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
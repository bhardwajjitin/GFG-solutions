//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int countzero=0;
        int countone=0;
        int counttwo=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0){
                countzero++;
            }
            else if(a[i]==1){
                countone++;
            }
            else{
                counttwo++;
            }
        }
           int i=0;
            while(countzero!=0){
                a[i]=0;
                i++;
                countzero--;
            }
            while(countone!=0){
                a[i]=1;
                i++;
                countone--;
            }
            while(counttwo!=0){
                a[i]=2;
                i++;
                counttwo--;
            }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends
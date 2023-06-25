//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    private:
    bool isPossible(int mxpages, int m, int arr[], int n) {
        
        int students = 1, pages = 0;
        for(int i=0;i<n;i++) {
            if(arr[i] > mxpages) return false;
            
            if(pages + arr[i] > mxpages) {
                students += 1;
                pages = arr[i];
            }
            else {
                pages += arr[i];
            }
        }
            
        if(students > m) return false;
        return true;
    }
    
    public:
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m) 
    {
        //code here
        if(m > n) return -1;
        int low=INT_MAX, high=0;
        
        for(int i=0;i<n;i++) {
            low = min(arr[i], low);
            high += arr[i];
        }
        
        int res = -1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            
            if( isPossible(mid, m, arr, n) ) {
                res = mid;
                high = mid - 1;
            }
            else {
                low = mid+1;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
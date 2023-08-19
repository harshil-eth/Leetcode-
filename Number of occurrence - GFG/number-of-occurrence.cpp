//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	
	int fo(int arr[], int n, int x) {
	    int lo = 0, hi=n-1;
	    int ans = -1;
	    while(lo <= hi) {
	        int mid = lo + (hi-lo)/2;
	        
	        if(arr[mid] == x) {
	            ans = mid;
	            hi = mid-1;
	        }
	        else if(arr[mid] < x) {
	            lo = mid+1;
	        }
	        else {
	            hi = mid-1;
	        }
	    }
	    return ans;
	}
	
	int lo(int arr[], int n, int x) {
	    int lo = 0, hi=n-1;
	    int ans = -1;
	    while(lo <= hi) {
	        int mid = lo + (hi-lo)/2;
	        
	        if(arr[mid] == x) {
	            ans = mid;
	            lo = mid+1;
	        }
	        else if(arr[mid] < x) {
	            lo = mid+1;
	        }
	        else {
	            hi = mid-1;
	        }
	    }
	    return ans;
	}
	
	int count(int arr[], int n, int x) {
	    // code here
	    
	    int first = fo(arr, n, x);
	   // cout<<first<<endl;
	    int last = lo(arr, n, x);
	   // cout<<last<<endl;
	    
	    if(first == -1 && last == -1) return 0;
	    return last-first+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
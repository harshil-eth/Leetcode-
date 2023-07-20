//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    #define ll long long
	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    ll maxp = 1, minp = 1;
	    ll res = -1e9;
	    
	    for(int i=0; i<n; i++) {
	        if(arr[i] < 0) swap(maxp, minp);
	        maxp = max(maxp*arr[i], 1LL*arr[i]);
	        minp = min(minp*arr[i], 1LL*arr[i]);
	        
	        res = max(res, maxp);
	    }
	    
	    return res;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
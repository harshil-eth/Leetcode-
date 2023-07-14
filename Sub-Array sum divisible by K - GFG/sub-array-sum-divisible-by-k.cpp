//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	#define ll long long
	long long subCount(long long arr[], int n, long long k)
	{
	    // Your code goes here
	    ll sum = 0, ans = 0;
	    unordered_map<ll, ll> mp;
	    mp[0]++;
	    
	    for(int i=0; i<n; i++) {
	        sum += arr[i];
	        ll rem = sum%k;
	        if(rem < 0) rem += k;
	        
	        if(mp.find(rem) != mp.end()) {
	            ans += mp[rem];
	        }
	        mp[rem]++;
	    }
	    
	    return ans;
	}
};


//{ Driver Code Starts.

int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
       	long long k;
		cin>>n >> k;
		long long a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
        

        Solution ob;
        cout << ob.subCount(a, n, k);
	    cout << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
        long long int getValue(long long int mid, int n, int m) {
            long long int ans=1;
            for(int i=1;i<=n;i++) {
                ans *= mid;
                if(ans > m) return 2;
            }
            if(ans == m) return 1;
            return 0;
        }
    
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	    int low=0,  high=m;
	    long long int ans=-1;
	    
	    while(low <= high) {
	        long long int mid = low + (high-low)/2;
	        
	        long long int val = getValue(mid, n, m);
	        
	        if(val == 1) 
	            return mid;
	        else if(val == 0) {
	            low = mid+1;
	        }
	        else {
	            high = mid-1;
	        }
	    }
	    
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends
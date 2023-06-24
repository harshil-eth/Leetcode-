//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
  #define ll long long int
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here
        ll low = 0, high = x;
        ll ans = -1;
        
        while(low <= high) {
            ll mid = low + (high-low)/2;
            
            ll val = mid*mid;
            
            if(val <= x) {
                ans = mid;
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends
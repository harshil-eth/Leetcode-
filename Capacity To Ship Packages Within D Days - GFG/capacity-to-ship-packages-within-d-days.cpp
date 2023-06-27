//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    private:
    bool haihimmat(int cap, int nums[], int d, int n) {
        int days=1;
        int load = 0;
        
        for(int i=0;i<n;i++) {
            if(load + nums[i] > cap) {
                days++;
                load = nums[i];
            }
            else {
                load += nums[i];
            }
        }
        return days <= d;
    }
    
  public:
    int leastWeightCapacity(int nums[], int n, int d) {
        // code here
        int low=0, high=0;
        for(int i=0;i<n;i++) {
            low = max(low, nums[i]);
            high += nums[i];
        }
        
        int ans = -1;
        while(low <= high) {
            int mid = (low+high) >> 1;
            
            if(haihimmat(mid, nums, d, n) == true) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends
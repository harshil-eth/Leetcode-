//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int nums[], int n, int target)
    {
        // code here
        // int n=nums.size();
        sort(nums, nums+n);
        int res = -1, min_diff = 1e9;

        for(int i=0; i<n; i++) {
            int s = i+1, e = n-1;
            while(s<e) {
                int sum = nums[i] + nums[s] + nums[e];
                if(sum == target) return sum;
                else if(sum < target) s++;
                else e--;

                if(abs(sum - target) < min_diff) {
                    min_diff = abs(sum - target);
                    res = sum;
                }
            }
        }

        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends
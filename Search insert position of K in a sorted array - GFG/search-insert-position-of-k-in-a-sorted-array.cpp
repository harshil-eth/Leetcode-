//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>arr, int n, int k)
    {
        // code here
        // simple bs
        int low=0, high=n-1;
        int mid = (low+high)/2;
        while(low<=high) {
            
            if(arr[mid] == k) return mid;
            else if(arr[mid] < k) low=mid+1;
            else high=mid-1;
            
            mid = (low+high)/2;
        }
        return low;
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
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
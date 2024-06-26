//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        
        sort(arr, arr+n);
        vector<int> ans;
        int prev = -1;
        for(int i=0;i<n-1;i++) {
            if(arr[i] == arr[i+1] && arr[i] != prev) {
                prev = arr[i];
                ans.push_back(arr[i]);
            } 
        }
        
        if(ans.size() == 0) return {-1};
        return ans;
        
        
        // map<int,int> mp;
        // for(int i=0;i<n;i++) {
        //     mp[arr[i]]++;
        // }
        // vector<int> ans;
        // for(auto it:mp) {
        //     if(it.second > 1) ans.push_back(it.first);
        // }
        
        // if(ans.size() != 0) return ans;
        // return {-1};
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
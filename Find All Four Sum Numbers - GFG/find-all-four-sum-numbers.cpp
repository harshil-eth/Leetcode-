//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here\
        
        vector<vector<int>> ans;
        
        int n= arr.size();
        sort(arr.begin(), arr.end());
        // int count = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                
                int a = arr[i] + arr[j];
                int t = k - a;
                int ii = j+1, jj = n-1;
                while(ii < jj) {
                    if(arr[ii] + arr[jj] == t) {
                        // count++;
                        ans.push_back({arr[i], arr[j], arr[ii], arr[jj]});
                        
                        while(ii+1 < n && arr[ii] == arr[ii+1]) ii++;
                        while(jj-1 >= 0 && arr[jj] == arr[jj-1]) jj--;
                        
                        ii++, jj--;
                    }
                    else if(arr[ii] + arr[jj] < t) {
                        ii++;
                    }
                    else jj--;
                    
                }
                
                while(j+1 < n && arr[j] == arr[j+1]) j++;
            }
            
            while(i+1 < n && arr[i] == arr[i+1]) i++;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
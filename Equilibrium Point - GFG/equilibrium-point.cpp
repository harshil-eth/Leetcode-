//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long arr[], int n) {
    
        // Your code here
        int ind = -1;
        long long pre[n], pre2[n];
        pre[0] = arr[0];
        for(int i=1; i<n; i++) pre[i] = pre[i-1] + arr[i];
        
        // for(int i=0; i<n; i++) cout<<pre[i]<<" ";
        
        // cout<<endl;
        // vector<long long> pre2(n);
        pre2[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--) {
            pre2[i] = pre2[i+1] + arr[i];
        }
        // for(int i=0; i<n; i++) cout<<pre2[i]<<" ";
        
        // cout<<endl;
        
        for(int i=0; i<n; i++) {
            if(pre[i] == pre2[i]) {
                ind = i;
            }
        }
        
        return ind == -1 ? -1 : ind+1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
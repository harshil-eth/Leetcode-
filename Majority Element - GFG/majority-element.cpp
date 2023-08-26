//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int arr[], int n)
    {
        int c = 0, el;
        for(int i=0; i<n; i++) {
            if(c == 0) {
                c = 1;
                el = arr[i];
            }
            else if(el == arr[i]) {
                c++;
            }
            else c--;
        }
        
        int cc = 0;
        for(int i=0; i<n; i++) {
            if(arr[i] == el) cc++;
        }
        
        if(cc > n/2) return el;
        return -1;
        // your code here
        
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends
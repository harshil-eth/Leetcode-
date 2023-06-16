//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        // Code here 
        int ans=0;
        for(int i=0;i<n;i++) {
            if(arr[i] == 'P') {
                int j = max(0, i-k);
                bool f = true;
                for(int run=j; run<i;run++) {
                    if(arr[run] == 'T') {
                        ans++;
                        arr[run] = 'C'; // catch
                        f = false;
                        break;
                    }
                }
                if(f) {
                    //right mai jao
                    j = min(n-1, i+k);
                    for(int run=i+1; run<=j; run++) {
                        if(arr[run] == 'T') {
                            ans++;
                            arr[run] = 'C';
                            f = false;
                            break;
                        }
                    }
                }
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
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 


// } Driver Code Ends
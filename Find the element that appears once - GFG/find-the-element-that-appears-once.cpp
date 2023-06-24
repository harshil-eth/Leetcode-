//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int nums[], int n){
	    //code
	   // int n=nums.size();
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        int low=1, high=n-2;

        while(low <= high) {
            int mid = low + (high-low)/2;
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])    
                return nums[mid];

            //on left part
            if((mid%2 == 1 && nums[mid] == nums[mid-1]) || 
                        (mid%2 == 0 && nums[mid] == nums[mid+1])) {

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

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends
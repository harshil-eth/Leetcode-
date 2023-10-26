//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    int minOperation(int num)
    {
        //code here.
        int count = 0;
        while(num != 0){
            if(num%2 != 0){
                num = num-1;
                count++;
                continue;
            }
            num = num/2;
            count++;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends
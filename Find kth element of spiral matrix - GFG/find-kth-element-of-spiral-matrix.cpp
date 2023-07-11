//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		vector<int> ans;
 		int cnt=0;
 		int tot = n*m;
 		
 		int srow=0, scol=0, erow=n-1, ecol=m-1;
 		
 		while(cnt < tot) {
 		    for(int i=scol; i<=ecol;i++) {
 		        ans.push_back(a[srow][i]);
 		        cnt++;
 		    }
 		    srow++;
 		    
 		    for(int i=srow; i<=erow; i++) {
 		        ans.push_back(a[i][ecol]);
 		        cnt++;
 		    }
 		    ecol--;
 		    
 		    for(int i=ecol; i>=scol;i--) {
 		        ans.push_back(a[erow][i]);
 		        cnt++;
 		    }
 		    erow--;
 		    
 		    for(int i=erow; i>=srow; i--) {
 		        ans.push_back(a[i][scol]);
 		        cnt++;
 		    }
 		    scol++;
 		}
 		
 		return ans[k-1];
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends
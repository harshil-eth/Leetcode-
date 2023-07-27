//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;

    double median = 0.0;

    int signum(int a, int b) {
        if(a == b) return 0;
        else if(a > b) return 1;
        else return -1;
    }
    //Function to insert heap.
    void insertHeap(int &num)
    {
        switch(signum(maxi.size(), mini.size())) {

            case 0:
            if(num > median) {
                mini.push(num);
                median = mini.top();
            }
            else {
                maxi.push(num);
                median = maxi.top();
            }
            break;

            case 1:
            if(num > median) {
                mini.push(num);
                median = (mini.top() + maxi.top()) / 2.0;
            }
            else {
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(num);
                median = (mini.top() + maxi.top()) / 2.0;
            }
            break;

            case -1:
            if(num > median) {
                maxi.push(mini.top());
                mini.pop();
                mini.push(num);
                median = (mini.top() + maxi.top()) / 2.0;
            }
            else {
                maxi.push(num);
                median = (mini.top() + maxi.top()) / 2.0;
            }
            break;
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        return median;
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends
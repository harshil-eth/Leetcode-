//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double, Item>> v;
        for(int i=0; i<n; i++) {
            double per_unit = double(arr[i].value) / double(arr[i].weight);
            v.push_back({per_unit, arr[i]});
        }
        
        sort(v.begin(), v.end(), [](const pair<double, Item> &a, const pair<double, Item> &b) {
            return a.first > b.first;
        });
        
        double ans = 0;
        for(int i=0; i<n; i++) {
            if(v[i].second.weight <= W) {
                W -= v[i].second.weight;
                ans += v[i].second.value;
            }
            else {
                ans += W*v[i].first;
                W = 0;
            }
        }
        
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends
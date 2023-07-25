//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    // int minEle;
    stack<int> s;
    stack<int> ss;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
           if(ss.size() == 0) return -1;
        return ss.top();
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           if(s.size() == 0) return -1;
            int ans = s.top();
        s.pop();
        if(ans == ss.top()) ss.pop();
        return ans;
           //Write your code here
       }
       
       /*push element x into the stack*/
       void push(int val){
           
           //Write your code here
            s.push(val);
        if(ss.size() == 0 || ss.top() >= val) ss.push(val);
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends
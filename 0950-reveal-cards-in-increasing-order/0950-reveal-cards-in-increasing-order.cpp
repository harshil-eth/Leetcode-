class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        int n=deck.size(),j=(deck.size()+1)/2;
        vector<int> ans(n);
        queue<int> q;

        for(int i=0;i<n;i++){
            if(i%2==0) {ans[i]=deck[i/2];}
            else q.push(i);
        }

        if(n%2!=0){
            q.push(q.front());
            q.pop();
        }

        while(!q.empty()){
            ans[q.front()]=deck[j++];
            q.pop();
            q.push(q.front());
            q.pop();
        }

        return ans;
    }
};
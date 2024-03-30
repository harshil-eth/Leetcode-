class Solution {
private:
    int f(vector<int> &arr, int k) {
        // atleast k diff
        int n = arr.size();
        int i=0, j=0;
        unordered_map<int, int> mp;
        int ans = 0;
        
        while(j < n) {
            mp[arr[j]]++;
            if(mp.size() <= k) {
                ans += (j-i+1);
                j++;
            }
            else if(mp.size() > k) {
                while(mp.size() > k) {
                    mp[arr[i]]--;
                    if(mp[arr[i]] == 0) {
                        mp.erase(arr[i]);
                    }
                    i++;
                }
                
                if(mp.size() <= k) {
                    ans += (j-i+1);
                }
                j++;
            }
        }
        
        return ans;
    }
    
public:
    int subarraysWithKDistinct(vector<int>& arr, int k) {
        int t1 = f(arr, k);
        int t2 = f(arr, k-1);
        return t1-t2;
    }
};
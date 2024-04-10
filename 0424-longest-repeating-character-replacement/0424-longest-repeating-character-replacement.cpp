class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int n = s.size();
        int i = 0;
        int maxLen = 0, maxCount = 0;

        for(int j=0; j<n; j++) {
            mp[s[j]]++;
            maxCount = max(maxCount, mp[s[j]]);

            int toReplace = (j-i+1) - maxCount;

            if(toReplace > k) {
                // move the start pointer
                mp[s[i]]--;
                i++;
            }

            maxLen = max(maxLen, j-i+1);
        }

        return maxLen;   
    }
};
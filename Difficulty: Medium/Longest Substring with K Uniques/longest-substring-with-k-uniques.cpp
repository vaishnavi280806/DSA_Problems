class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        unordered_map <char,int> hash;
        int l = 0, c = 0, maxLen = 0;
        
        for (int r = 0; r < s.size(); r++){
            if (!hash.count(s[r])){
                c++;
            }
            hash[s[r]]++;
            
            while (c > k){
                hash[s[l]]--;
                if (hash[s[l]] == 0){
                    c--;
                    hash.erase(s[l]);
                }
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        if (c != k) return -1;
        return maxLen;
    }
};
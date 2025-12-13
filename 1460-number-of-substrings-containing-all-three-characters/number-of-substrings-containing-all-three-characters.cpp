class Solution {
private:
    int helper(string s, int k) {
        unordered_map <char,int> hash;
        int l = 0, c = 0;
        for (int r = 0; r < s.size(); r++){
            hash[s[r]]++;
            while (hash.size() > k){
                hash[s[l]]--;
                if (hash[s[l]] == 0){
                    hash.erase(s[l]);
                }
                l++;
            }
            c += r-l+1;
        }
        return c;
    }
public:
    int numberOfSubstrings(string s) {
        return helper(s,3) - helper(s,2);
    }
};
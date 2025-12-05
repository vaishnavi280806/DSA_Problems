class Solution {
private:
    int expand(string s, int l, int r){
        while (l >= 0 && r < s.size()){
            if (s[l] == s[r]){
                l--;
                r++;
            }
            else{
                return r-l-1;
            }
        }
        return r-l-1;
    }
public:
    string longestPalindrome(string s) {
        int maxLen = 0, mid = 0;
        for (int i = 0; i < s.size(); i++){
            int even = expand(s, i, i+1);
            int odd = expand(s, i, i);

            if (even > maxLen){
                maxLen = even;
                mid = i;
            }
             if (odd > maxLen){
                maxLen = odd;
                mid = i;
            }
        }
        return s.substr(mid - (maxLen-1)/2, maxLen);
    }
};
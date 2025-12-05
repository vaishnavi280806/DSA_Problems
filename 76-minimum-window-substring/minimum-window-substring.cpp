class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map <char,int> need, window;
        for (char i: t){
            need[i]++;
        }
        int formed = 0, l = 0, bestL = 0, bestLen = INT_MAX;

        for (int r = 0; r < s.size(); r++){
            
            window[s[r]]++;

            if (need.count(s[r]) && need[s[r]] == window[s[r]]){
                formed++;
            }


            while (formed == need.size()){
                if (r - l + 1 < bestLen){
                    bestLen = r - l + 1;
                    bestL = l;
                }
                if (need.count(s[l]) && need[s[l]] == window[s[l]]){
                    formed--;
                }
                window[s[l]]--;
                l++;
            }

        }
        if (bestLen == INT_MAX){
            return "";
        }
        return s.substr(bestL, bestLen);
    }
};
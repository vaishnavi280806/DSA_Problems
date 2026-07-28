class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> arr(26, 0);
        for (char c : s){
            arr[c - 'a']++;
        }
        string res = "";
        for (int i = 0; i < s.size(); i++){
            res += '*';
        }
        int l = 0;
        int r = s.size() - 1;
        int flag = -1;
        for (int i = 0; i < 26; i++){
            while (arr[i] > 1){
                res[l] = (char)(i + 97);
                res[r] = (char)(i + 97);
                l++; r--;
                arr[i] -= 2;
            }
            if (arr[i] == 1) flag = i;
        }
        if (flag != -1) res[(int)(s.size())/2] = (char)(flag + 97);
        return res;
    }
};
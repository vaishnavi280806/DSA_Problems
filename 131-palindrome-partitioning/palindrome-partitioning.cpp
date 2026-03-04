class Solution {
    bool palindrome(int start, int end, string s){
        while (start < end){
            if (s[start] != s[end]) return false;
            start++; end--;
        }
        return true;
    }
    void helper(string s, int idx, vector<string>& ds, vector<vector<string>>& res){
        if (idx == s.size()){
            res.push_back(ds);
        }
        for (int i = idx; i < s.size(); i++){
            if (palindrome(idx, i, s)){
                ds.push_back(s.substr(idx, i - idx + 1));
                helper(s, i+1, ds, res);
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> ds;
        vector<vector<string>> res;
        helper(s, 0, ds, res);
        return res;
    }
};
class Solution {
    unordered_map <char, string> hash = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    void helper(int idx, string& digits, string& ds, vector<string>& res){
        if (idx == digits.size()){
            res.push_back(ds);
            return;
        }
        for (char x : hash[digits[idx]]){
            ds.push_back(x);
            helper(idx + 1, digits, ds, res);
            ds.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string ds;
        vector<string> res;
        helper(0, digits, ds, res);
        return res;
    }
};
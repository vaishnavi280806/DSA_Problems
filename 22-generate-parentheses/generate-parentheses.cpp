class Solution {
    void helper(int open, int close, string& ds, vector<string>& res, int n){
        if (ds.size() == 2*n){
            res.push_back(ds);
            return;
        }
        if (open < n){
            ds.push_back('(');
            helper(open + 1, close, ds, res, n);
            ds.pop_back();
        }
        if (close < open){
            ds.push_back(')');
            helper(open, close + 1, ds, res, n);
            ds.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string ds;
        helper(0, 0, ds, res, n);
        return res;
    }
};
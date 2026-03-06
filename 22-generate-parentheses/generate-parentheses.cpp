class Solution {
    vector<char> para = {'(', ')'};
    bool valid(string ds){
        int sum = 0;
        for (int i = 0; i < ds.size(); i++){
            if (ds[i] == '(') sum += 1;
            else sum -= 1;
            if (sum < 0) return false;
        }
        if (sum == 0) return true;
        return false;
    }
    void helper(string& ds, vector<string>& res, int n){
        if (ds.size() == 2*n){
            if (valid(ds)) res.push_back(ds);
            return;
        }
        for (int i = 0; i < 2; i++){
            ds.push_back(para[i]);
            helper(ds, res, n);
            ds.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
       vector<string> res;
       string ds;
       helper(ds, res, n);
       return res;
    }
};
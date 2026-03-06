class Solution {
    void helper(string& ds, vector<string>& res, int n){
        if (ds.size() == n){
            res.push_back(ds);
            return;
        }
        if (ds.size() == 0){
            ds.push_back('1');
            helper(ds, res, n);
            ds.pop_back();
            ds.push_back('0');
            helper(ds, res, n);
            ds.pop_back();
        }
        if (ds.size() != 0 && ds[ds.size() - 1] == '0'){
            ds.push_back('1');
            helper(ds, res, n);
            ds.pop_back();
        }
        if (ds.size() != 0 && ds[ds.size() - 1] == '1'){
            ds.push_back('1');
            helper(ds, res, n);
            ds.pop_back();
            ds.push_back('0');
            helper(ds, res, n);
            ds.pop_back();
        }
    }
public:
    vector<string> validStrings(int n) {
        string ds;
        vector<string> res;
        helper(ds, res, n);
        return res;
    }
};
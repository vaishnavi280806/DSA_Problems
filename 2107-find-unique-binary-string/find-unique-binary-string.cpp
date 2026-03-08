class Solution {
    string helper(string& ds, unordered_set<string>& hash, int n){
        if (ds.size() == n){
            if (!hash.count(ds)) return ds;
            else return "";
        }
        ds.push_back('0');
        string ans = helper(ds, hash, n);
        if (ans != "") return ans;
        ds.pop_back();
        ds.push_back('1');
        ans = helper(ds, hash, n);
        if (ans != "") return ans;
        ds.pop_back();

        return "";
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set <string> hash;
        for (auto it : nums){
            hash.insert(it);
        }
        string ds;
        return helper(ds, hash, nums.size());

    }
};
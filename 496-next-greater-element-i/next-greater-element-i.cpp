class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int, int> hash;
        vector<int> res;

        for (int i = nums2.size() - 1; i >= 0; i--){
            while (!stk.empty() && stk.top() <= nums2[i]) stk.pop();
            if (stk.empty()) hash[nums2[i]] = -1;
            else hash[nums2[i]] = stk.top();
            stk.push(nums2[i]);
        }
        for (int x : nums1) res.push_back(hash[x]);
        return res;
    }
};
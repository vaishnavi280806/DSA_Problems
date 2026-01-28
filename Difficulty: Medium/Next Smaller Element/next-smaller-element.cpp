class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        vector<int> res(arr.size());
        stack <int> stk;
        for (int i = arr.size() - 1; i >= 0; i--){
            while (!stk.empty() && arr[i] <= stk.top()) stk.pop();
            if (stk.empty()) res[i] = -1;
            else res[i] = stk.top();
            stk.push(arr[i]);
        }
        return res;
    }
};
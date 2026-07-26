class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> stk;
        vector<int> res(temp.size());
        for (int i = temp.size() - 1; i >= 0; i--){
            while (!stk.empty() && temp[stk.top()] <= temp[i]){
                stk.pop();
            }
            if (stk.empty()) res[i] = 0;
            else res[i] = stk.top() - i;

            stk.push(i);
        }

        return res;
    }
};
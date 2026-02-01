class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack <int> stk;
        int ans = 0, pse;
        for (int i = 0; i < heights.size(); i++){
            while (!stk.empty() && heights[stk.top()] > heights[i]){
                int tp = stk.top();
                stk.pop();
                if (!stk.empty()) pse = stk.top();
                else pse = -1;
                ans = max(ans, heights[tp] * (i - pse - 1));
            }
            stk.push(i);
        }
        while (!stk.empty()){
            int tp = stk.top(); stk.pop();
            if (!stk.empty()) pse = stk.top();
            else pse = -1;
            ans = max(ans, heights[tp] * ((int)heights.size() - pse - 1));
        }
        return ans;
    }
};
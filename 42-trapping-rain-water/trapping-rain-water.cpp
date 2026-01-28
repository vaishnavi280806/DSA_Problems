class Solution {
public:
    int trap(vector<int>& height) {
        stack <int> stk;
        int ans = 0;
        for (int i = 0; i < height.size(); i++){
            while (!stk.empty() && height[i] >= height[stk.top()]){
                int tp = stk.top();
                stk.pop();
                if (!stk.empty()){
                    int w = i - stk.top() - 1;
                    int h = min(height[stk.top()], height[i]) - height[tp];
                    ans += w*h;
                    cout << i << tp << stk.top() << w << endl;
                    cout << ans << endl;
                }
            }
            stk.push(i);
        }
        return ans;
    }
};
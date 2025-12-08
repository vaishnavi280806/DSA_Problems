class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, trap = 0, leftMax = height[0], rightMax = height[height.size() - 1];

        while (l != r){
            if (height[l] < height[r]){
                trap += min(leftMax, rightMax) - height[l];
                l++;  
                if (height[l] > leftMax) leftMax = height[l];     
            }
            else{
                trap += min(leftMax, rightMax) - height[r];
                r--;
                if (height[r] > rightMax) rightMax = height[r];
            }
        }
        return trap;
    }
};
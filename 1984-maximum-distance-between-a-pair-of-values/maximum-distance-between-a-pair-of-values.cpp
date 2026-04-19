class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        while (i < n1 && j < n2){
            while (i < n1 && j < n2 && nums1[i] > nums2[j]){
                i++; j++;
            }
            while (i < n1 && j < n2 && nums1[i] <= nums2[j]){
                ans = max(ans, j-i);
                j++;
            }
        }
        return ans;
    }
};
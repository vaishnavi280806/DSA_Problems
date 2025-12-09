class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), maxSum = 0;
        vector<int> arr;
        for (int i = n - k; i < n; i++){
            arr.push_back(cardPoints[i]);
            maxSum += cardPoints[i];
        }
        for (int i = 0; i < k; i++){
            arr.push_back(cardPoints[i]);
        }
        int l = 0, r = k - 1, s = maxSum;
        while (r < arr.size() - 1){
            s = s - arr[l] + arr[r+1];
            maxSum = max(maxSum, s);
            l++; r++; 
        }

        return maxSum;
    }
};
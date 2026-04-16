class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int q = queries.size();
        unordered_map <int, vector<int>> hash;
        unordered_map <int, int> size;
        for (int i = 0; i < n; i++){
            hash[nums[i]].push_back(i);
            size[nums[i]]++;
        }
        vector<int> res(q);
        for (int i = 0; i < q; i++){
            vector<int> &arr = hash[nums[queries[i]]];
            int m = size[nums[queries[i]]];
            if (m == 1){
                res[i] = -1;
                continue;
            }
            int low = 0;
            int high = m -1;
            while (low <= high){
                int mid = low + (high - low)/2;
                if (arr[mid] == queries[i]){
                    if (mid == 0) res[i] = min(n + (arr[0] - arr[m-1]), arr[1] - arr[0]);
                    else if (mid == m-1) res[i] = min(n + (arr[0] - arr[m-1]), arr[m-1] - arr[m-2]);
                    else res[i] = min(arr[mid] - arr[mid-1], arr[mid+1] - arr[mid]);
                    break;
                }
                else if (arr[mid] > queries[i]) high = mid - 1;
                else low = mid + 1;
            }

        }
        return res;
    }
};
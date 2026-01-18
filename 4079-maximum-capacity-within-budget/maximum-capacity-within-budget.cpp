class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        vector<pair<int, int>> v;
        for (int i = 0; i < costs.size(); i++){
            v.push_back({costs[i], capacity[i]});
        }
        sort(v.begin(), v.end());

        vector <int> preMax(costs.size());
        preMax[0] = v[0].second;
        for (int i = 1; i < costs.size(); i++){
            preMax[i] = max(v[i].second, preMax[i-1]);
        }
        
        int ans = 0;
        for (int i = 0; i < costs.size(); i++){
            if (v[i].first >= budget) continue;
            ans = max(ans, v[i].second);
            int low = 0, high = i - 1, idx = -1;
            while (low <= high){
                int mid = low + (high - low)/2;
                if (v[mid].first < budget - v[i].first){
                    idx = mid;
                    low = mid + 1;
                }
                else high = mid - 1;
            }
            if (idx != -1) ans = max(ans, v[i].second + preMax[idx]) ; 

        }
        return ans;
    }
};
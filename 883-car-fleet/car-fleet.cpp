class Solution {
    static bool compare(pair<int,int> a, pair<int,int> b){
        return a.first < b.first;
    }
    double time(int pos, int sp, int target){
        return (double)(target - pos)/sp;
    }
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        for (int i = 0; i < speed.size(); i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end(), compare);
        int ans = 0, i = speed.size() - 1;
        while (i > 0){
            if (time(cars[i].first, cars[i].second, target) < time(cars[i-1].first, cars[i-1].second, target)) ans++;
            else cars[i-1] = cars[i];
            i--;
        }
        return ans+1;
    }
};
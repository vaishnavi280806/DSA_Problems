class Solution {
    int helper(vector<int> &stations, double mid){
        int count = 0;
        for (int i = 0; i < stations.size() - 1; i++){
            if (stations[i + 1] - stations[i] > mid){
                count += ceil((stations[i + 1] - stations[i])/mid) - 1;
            }
        }
        return count;
    }
  public:
    double minMaxDist(vector<int> &stations, int K) {
        int n = stations.size();
        double low = 0, high = stations[n - 1] - stations[0];
        while (high - low > pow(10,-6) ){
            double mid = low + (high - low)/2;
            int count = helper(stations, mid);
            if (count <= K) high = mid;
            else low = mid;
            
        }
        return low;
        
    }
};
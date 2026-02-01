class RideSharingSystem {
public:
    queue <int> driver;
    queue <int> rider;
    unordered_set <int> hash;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        rider.push(riderId);
        hash.insert(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        while (!rider.empty() && !hash.count(rider.front())) rider.pop();
            
        
        if (!rider.empty() && !driver.empty()){
            vector <int> res = {driver.front(), rider.front()};
            driver.pop();
            hash.erase(rider.front());
            rider.pop();
            return res;
        }
        return {-1, -1};
    }
    
    void cancelRider(int riderId) {
        if (hash.count(riderId)){
            hash.erase(riderId);
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */
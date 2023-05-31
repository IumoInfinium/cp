class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> userMap;
    unordered_map<string, pair<int,int>> stationMap;

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        userMap[id]={stationName, t};
    }
    
    void checkOut(int id, string endStation, int endTime) {
        const auto &[startStation, startTime] = userMap[id];
        auto &[totalTime, trips] = stationMap[startStation + "->" + endStation];

        totalTime += endTime- startTime;
        trips++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto &[totalTime, trips] = stationMap[startStation + "->" + endStation];
        return (double) totalTime/trips;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

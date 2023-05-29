class ParkingSystem {
public:
    int park1, park2, park3;

    ParkingSystem(int big, int medium, int small) {
        park1=big;
        park2=medium;
        park3=small;
    }
    
    bool addCar(int carType) {
        if(carType == 1 && park1 > 0 ){
            park1--;
            return true;
        }
        else if(carType == 2 && park2 > 0){
            park2--;
            return true;
        }
        else if(carType == 3 && park3 > 0){
            park3--;
            return true;
        }
        else return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

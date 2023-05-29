class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small): still_big(big), still_medium(medium), still_small(small) {}
    
    bool addCar(int carType) {
        switch(carType)
        {
            case 1:
                return still_big-- > 0;
            case 2:
                return still_medium-- > 0;
            default:
                return still_small-- > 0;
        }
    }
private:
    int still_big, still_medium, still_small;
};



/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
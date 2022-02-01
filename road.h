#ifndef ROAD_H
#define ROAD_H

class Road {
    public:
    enum type{open = 0, trafic = 1, advanced = 2};
    int type, car_number;
    double length, factor;
    
    Road(){
        type = open;
        length = -1;
        car_number=0; 
        factor = 1;
    }
    Road(int t, double l, int c, double f){
        type = t;
        length = l;
        car_number = c;
        factor = f;
    }
    
    double travel_time(){
        if(type == open) return length;
        if(type == trafic) return (double)car_number/length;
        if(type == advanced) return ((double)car_number/factor + length);
        return 0;
    }
};

#endif
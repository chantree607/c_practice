//
//  main.cpp
//  mathPractice
//
//  Created by Chan Yong Lee on 28.02.20.
//  Copyright © 2020 Chan Yong Lee. All rights reserved.
//

#include <iostream>
class Point{
    int x, y;
public:
    Point(){
        x = 0;
        y = 0;
    }
    Point(int pos_x, int pos_y){
        x = pos_x;
        y = pos_y;
    }
    
    int get_x() const{
        return x;
    }
    
    int get_y() const{
        return y;
    }
};

class Geometry{
private:
    Point **point_array;
    int arr_length;
    
public:
    Geometry(){
        arr_length = 0;
        point_array = new Point*[arr_length];
    }
    
    Geometry(Point **point_list, int length){
        point_array = new Point*[length];
        point_array = point_list;
        arr_length = length;
    }
    
    void addPoint(const Point &point);
    
    int getArrLength();
    
    void setArrLength(int length);
    
    Point** getPointArray();
    void setPointArray(Point** point_list);
    
    Point* getPoint(int ind);
    
    void showAllPoints();
};


int main(int argc, const char * argv[]) {
    Geometry geom = Geometry();
    geom.showAllPoints();
    geom.addPoint(Point(1,2));
    geom.addPoint(Point(2,2));
    geom.addPoint(Point(3,2));
    geom.addPoint(Point(4,2));
    geom.showAllPoints();
    return 0;
}

int Geometry::getArrLength(){
    return arr_length;
}

void Geometry::setArrLength(int length){
    arr_length = length;
}

Point** Geometry::getPointArray(){
    return point_array;
}

void Geometry::setPointArray(Point** point_list){
    point_array = point_list;
}

Point* Geometry::getPoint(int ind){
    return *(getPointArray() + ind);
}

void Geometry::addPoint(const Point &point){
    Point** tmpArray = new Point*[getArrLength() + 1];
    tmpArray = getPointArray();
    *(tmpArray + getArrLength()) = new Point(point.get_x(), point.get_y());
    setArrLength(getArrLength() +1);
    setPointArray(tmpArray);
}

void Geometry::showAllPoints(){
    if(getArrLength() == 0){
        std::cout << "No points saved" << std::endl;
    }
    for(int i = 0 ; i < getArrLength() ; i++){
        std::cout << i+1 <<" Point : " << "(" <<getPoint(i)->get_x() << "," << getPoint(i)->get_y() << ")" << std::endl;
    }
}

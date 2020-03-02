//
//  main.cpp
//  n_dim_array
//
//  Created by Chan Yong Lee on 01.03.20.
//  Copyright © 2020 Chan Yong Lee. All rights reserved.
//

#include <iostream>

class Array_2d{
private:
    int row_num;
    int column_num;
    int* arr;
    
public:
    //constructor
    Array_2d();
    Array_2d(int rows, int columns);
    Array_2d(const Array_2d& a);
    ~Array_2d();
    
    //
    void set_row_num(int row);
    void set_column_num(int column);
    int get_row_num() const;
    int get_column_num() const;
    void set_elem(int row, int column, int val);
    int get_elem(int row, int column) const;
    
    //operator overload
    Array_2d operator[](const int row);
    
    //wrapper class overload
    operator int(){return *arr;}
};
//default constructor for 2d array
Array_2d::Array_2d(){
    std::cout << "number of rows : ";
    std::cin >> row_num;
    std::cout << std::endl;
    
    std::cout << "number of columns : ";
    std::cin >> column_num;
    std::cout << std::endl;
    
    //allocates memeory for the 2d array
    arr = (int*)malloc(sizeof(int) * row_num * column_num);
    for(int i = 0 ; i < row_num*column_num ; i++){
        *(arr + i) = 0;
    }
    
    std::cout << row_num << " x " << column_num << " array is created!" << std::endl;
}

Array_2d::Array_2d(int rows, int columns){
    row_num = rows;
    column_num = columns;
    
    //allocates memeory for the 2d array
    arr = (int*)malloc(sizeof(int) * row_num * column_num);
    for(int i = 0 ; i < row_num*column_num ; i++){
        *(arr + i) = 0;
    }
    
    std::cout << row_num << " x " << column_num << " array is created!" << std::endl;
}

Array_2d::Array_2d(const Array_2d& a){
    row_num = a.row_num;
    column_num = a.column_num;
    
    arr = (int *)malloc(sizeof(int) * row_num * column_num);
    for(int i = 0 ; i < row_num ; i++){
        for(int j = 0 ; j < column_num ;j++){
            set_elem(i, j, a.get_elem(i,j));
        }
    }
}

//destructor;
Array_2d::~Array_2d(){
    std::cout<<"destructor"<<std::endl;
    delete [] arr;
}
void Array_2d::set_row_num(int row){ row_num = row; }
void Array_2d::set_column_num(int column){ column_num = column; }
int Array_2d::get_row_num() const{ return row_num;}
int Array_2d::get_column_num() const{ return column_num; }

//get&set elements
void Array_2d::set_elem(int row, int column, int val){
    if(0 <= row && row < row_num
       && 0 <= column && column < column_num){
        *(arr + column_num*row + column) = val;
    }
    else{
        std::cout << "out of index" << std::endl;
    }
    
}

int Array_2d::get_elem(int row, int column) const{
    return *(arr + column_num*row + column);
}

//operator overlaod;
Array_2d Array_2d::operator[](const int row){
    if(row >= 0 && row < row_num){
        Array_2d tmp(column_num, 1);
        for(int i = 0 ; i < column_num ; i++){
            tmp.set_elem(i, 0, get_elem(row, i));
        }
        return tmp;
    }
    else{
        std::cout << "out of index" << std::endl;
        return Array_2d(1,1);
    }
}
    
int main(int argc, const char * argv[]) {
    
    Array_2d arr(3,3);
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            arr.set_elem(i, j, i+j);
            std::cout << arr.get_elem(i, j)<< " ";
        }
        std::cout<<std::endl;
    }
    
    Array_2d b = arr;
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            arr.set_elem(i, j, i+j);
            std::cout << arr.get_elem(i, j)<< " ";
        }
        std::cout<<std::endl;
    }
    int a = arr[2][2];
    std::cout << "value of a : " << a << std::endl;
    
    return 0;
}

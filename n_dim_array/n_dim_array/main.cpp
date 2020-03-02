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
    int* get_arr();
    
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
    std::cout<<"2d destructor"<<std::endl;
    delete [] arr;
}
void Array_2d::set_row_num(int row){ row_num = row; }
void Array_2d::set_column_num(int column){ column_num = column; }
int Array_2d::get_row_num() const{ return row_num;}
int Array_2d::get_column_num() const{ return column_num; }
int* Array_2d::get_arr(){return arr;}

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

class Array_3d{
private:
    int first_dim_num;
    int second_dim_num;
    int third_dim_num;
    Array_2d **arr;
    
public:
    Array_3d();
    Array_3d(int first, int second, int third);
    Array_3d(const Array_3d& a);
    ~Array_3d();
    
    void set_first_dimension(int first);
    void set_second_dimension(int second);
    void set_third_dimension(int third);
    int get_first_dim_num() const;
    int get_second_dim_num() const;
    int get_third_dim_num() const;
    void set_elem(int first, int second, int third, int val);
    int get_elem(int first, int second, int third) const;
    
    //operator overload
    Array_2d operator[](const int first);
    
};

//Constructors
Array_3d::Array_3d(){
    std::cout << "first dimension size  : ";
    std::cin >> first_dim_num;
    std::cout << std::endl;
    
    std::cout << "second dimension size : ";
    std::cin >> second_dim_num;
    std::cout << std::endl;
    
    std::cout << "third dimension size : ";
    std::cin >> third_dim_num;
    std::cout << std::endl;
    
    //allocates memeory for the 3d array
    arr = (Array_2d**)malloc(sizeof(Array_2d*) * first_dim_num);
    for(int i = 0 ; i < first_dim_num ; i++){
        *(arr + i) = new Array_2d(second_dim_num, third_dim_num);
    }
    
    std::cout << first_dim_num << " x " << second_dim_num << " x " << second_dim_num << " array is created!" << std::endl;
}
Array_3d::Array_3d(int first, int second, int third){
    first_dim_num = first;
    second_dim_num = second;
    third_dim_num = third;
    
    //allocates memeory for the 3d array
    arr = (Array_2d**)malloc(sizeof(Array_2d*) * first_dim_num);
    for(int i = 0 ; i < first_dim_num ; i++){
        *(arr + i) = new Array_2d(second_dim_num, third_dim_num);
    }
    
    std::cout << first_dim_num << " x " << second_dim_num << " x " << second_dim_num << " array is created!" << std::endl;
}
Array_3d::Array_3d(const Array_3d& a){
    first_dim_num = a.first_dim_num;
    second_dim_num = a.second_dim_num;
    third_dim_num = a.third_dim_num;
    
    //allocates memeory for the 3d array
    arr = (Array_2d**)malloc(sizeof(Array_2d*) * first_dim_num);
    for(int i = 0 ; i < first_dim_num ; i++){
        *(arr + i) = new Array_2d(second_dim_num, third_dim_num);
    }
    
    for(int i= 0 ; i < first_dim_num ; i++){
        for(int j = 0 ; j < second_dim_num ; j++){
            for(int k = 0 ; k < third_dim_num ; k++){
                (*(arr+i))->set_elem(j, k, (*(a.arr+i))->get_elem(j, k));
            }
        }
    }
}
Array_3d::~Array_3d(){
    std::cout<<"3d destructor"<<std::endl;
    /*
    for(int i = 0 ; i < first_dim_num ; i++){
        delete [] arr;
    }
     */
}
//public methods;
void Array_3d::set_first_dimension(int first){
    first_dim_num = first;
}
void Array_3d::set_second_dimension(int second){
    second_dim_num = second;
}
void Array_3d::set_third_dimension(int third){
    third_dim_num = third;
}
int Array_3d::get_first_dim_num() const{
    return first_dim_num;
}
int Array_3d::get_second_dim_num() const{
    return second_dim_num;
}
int Array_3d::get_third_dim_num() const{
    return third_dim_num;
}
void Array_3d::set_elem(int first, int second, int third, int val){
    (*(arr+first))->set_elem(second, third, val);
}
int Array_3d::get_elem(int first, int second, int third) const{
    return (*(arr+first))->get_elem(second, third);
}

Array_2d Array_3d::operator[](const int first){
    return *(*(arr + first));
}

int main(int argc, const char * argv[]) {
    
    /*
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
     */
    Array_3d arr(3,3,3);
    for(int i= 0 ; i < arr.get_first_dim_num() ; i++){
        for(int j = 0 ; j < arr.get_second_dim_num() ; j++){
            for(int k = 0 ; k < arr.get_third_dim_num() ; k++){
                arr.set_elem(i, j, k, i+j+k);
            }
        }
    }
    for(int i= 0 ; i < arr.get_first_dim_num() ; i++){
        for(int j = 0 ; j < arr.get_second_dim_num() ; j++){
            for(int k = 0 ; k < arr.get_third_dim_num() ; k++){
                std::cout<< arr.get_elem(i, j, k) << "";
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
        
    }
    int a = arr[2][2][2];
    return 0;
}

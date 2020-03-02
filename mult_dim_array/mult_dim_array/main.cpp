//
//  main.cpp
//  mult_dim_array
//
//  Created by Chan Yong Lee on 02.03.20.
//  Copyright © 2020 Chan Yong Lee. All rights reserved.
//

#include <iostream>

class Array{
private:
    
    typedef struct Address{
        int level;
        void* next;
    }Address;
    
    Address addr;
    int* dim_sizes;
    int dim_num;
    
    int get_elem(Address* addr, int dim, int* dims);
    void set_elem(Address* addr, int dim, int* dims, int val);
    
public:
    Array();
    Array(int dim, int* dims);
    Array(int dim, int* dims, Address* addr_);
    ~Array();
    
    void allocate_levels(Address* addr,int level_);
    void copy_levels(Address* dest, Address* src, int level_);
    void deallocate_levels(Address* addr);
    
    int get_elem(int dim, int* dims);
    void set_elem(int dim, int* dims, int val);
    int* get_dim_sizes();
    
    //operator overlaod
    Array operator[](int ind);
    
    //wrapper class overload
    operator int(){return *((int*)addr.next);}
    
};

Array::Array(){
    
    int counter = 0;
    
    std::cout << "enter number of dimensions : ";
    std::cin >> counter;
    
    dim_num = counter;
    
    dim_sizes = (int*)malloc(sizeof(int) * counter);
    
    for(int i = 0 ; i < counter ; i++){
        std::cout << "enter the size of " << i+1 << " th dimension : ";
        std::cin >> *(dim_sizes + i);
    }
    
    allocate_levels(&addr, 0);
    
}
Array::Array(int dim, int* dims){
    dim_num = dim;
    dim_sizes = (int *)malloc(sizeof(int) * dim);
    for(int i = 0 ; i < dim ; i++){
        *(dim_sizes + i)  = *(dims + i);
    }
    
    allocate_levels(&addr, 0);
}
Array::Array(int dim, int* dims, Address* addr_){
    dim_num = dim;
    dim_sizes = (int *)malloc(sizeof(int) * dim);
    for(int i = 0 ; i < dim ; i++){
        *(dim_sizes + i)  = *(dims + i);
    }
    copy_levels(&addr, addr_, 0);
}
Array::~Array(){
    deallocate_levels(&addr);
    delete [] dim_sizes;
}



int Array::get_elem(Address* addr, int dim, int* dims){
    if(addr -> level == dim - 1){
        return *((int *)(addr->next) + dims[addr->level]);
    }
    else{
        return get_elem(&(*((Address*)(addr->next) + dims[addr->level])), dim, dims);
    }
}
void Array::set_elem(Address* addr, int dim, int* dims, int val){
    if(addr -> level == dim - 1){
        *((int *)(addr->next) + dims[addr->level]) = val;
    }
    else{
        set_elem(&(*((Address*)(addr->next) + dims[addr->level])), dim, dims, val);
    }
}

int Array::get_elem(int dim, int* dims){
    return get_elem(&addr, dim, dims);
}
void Array::set_elem(int dim, int* dims, int val){
    set_elem(&addr, dim, dims, val);
}
int* Array::get_dim_sizes(){
    return dim_sizes;
}

void Array::allocate_levels(Address* addr, int level_){
    addr->level = level_;
    if(level_ == dim_num - 1){
        addr->next = malloc(sizeof(int) * (*(dim_sizes + level_)));
    }
    else{
        addr->next = malloc(sizeof(Address) * (*(dim_sizes + level_)));
        for(int i  = 0 ; i < *(dim_sizes + level_) ; i++){
            allocate_levels(&(*((Address *)addr->next + i)), level_ + 1);
        }
    }
}
void Array::copy_levels(Address* dest, Address* src, int level_){
    dest->level = level_;
    if(dest->level == dim_num-1){
        dest->next = malloc(sizeof(int) * (*(dim_sizes + dim_num - 1)));
        for(int i = 0 ; i < *(dim_sizes + dim_num - 1) ; i++){
            *((int*)(dest->next) + i) = *((int*)(src->next) + i);
        }
    }
    else{
        dest->next = malloc(sizeof(Address) * (*(dim_sizes + src->level)));
        for(int i = 0; i < *(dim_sizes + src->level) ; i++){
            copy_levels((Address*)(dest->next) + i, (Address*)(src->next) + i, level_ + 1);
        }
    }
}


void Array::deallocate_levels(Address* addr){
    
    if(addr->level == dim_num - 1){
        delete [] static_cast<Address*>(addr->next);
        
    }
    else{
        for(int i = 0 ; i < dim_sizes[addr->level] ; i++){
            deallocate_levels((&(*((Address *)addr->next + i))));
        }
        delete [] static_cast<Address*>(addr->next);
    }
    
    //std::cout << "deleted level " << addr->level <<std::endl;
}

Array Array::operator[](int ind){
    if(dim_num == 1){
        int tmpDim[1] = {1};
        Array tmp(1, tmpDim);
        int tmpInd[2] = {0,0};
        tmp.set_elem(1, tmpInd, *((int*)(addr.next) + ind));
        
        return tmp;
    }
    else{
        int tmp[dim_num - 1];
        for(int i = 0 ; i < dim_num - 1 ; i++){
            tmp[i] = dim_sizes[i+1];
        }
        return Array(dim_num - 1, tmp, ((Address *)(addr.next) + ind));
    }
}



int main(int argc, const char * argv[]) {
    
    //constructor 작동
    int tmp[3] = {3,3,3};
    Array ar(3, tmp);
    //Array ar;
    
    //set_elem 함수 작동
    for(int i  =  0 ; i < *ar.get_dim_sizes() ; i++){
        for(int j = 0 ; j < *(ar.get_dim_sizes() + 1) ; j++){
            for(int k = 0 ; k < *(ar.get_dim_sizes() + 2) ; k++){
                int ind[3] = {i ,j ,k};
                ar.set_elem(3, ind, i+j+k);
            }
        }
    }
    
    //get_elem 함수 작동
    for(int i  =  0 ; i < *ar.get_dim_sizes() ; i++){
        for(int j = 0 ; j < *(ar.get_dim_sizes() + 1) ; j++){
            for(int k = 0 ; k < *(ar.get_dim_sizes() + 2) ; k++){
                //int ind[3] = {i ,j ,k};
                
                //[]operator 작동!!!
                int a = ar[i][j][k];
                std::cout << a<< " ";
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }
    
    
    int tmp2[4] = {4,4,4,4};
    Array ar2(4, tmp2);
    for(int i  =  0 ; i < *ar2.get_dim_sizes() ; i++){
        for(int j = 0 ; j < *(ar2.get_dim_sizes() + 1) ; j++){
            for(int k = 0 ; k < *(ar2.get_dim_sizes() + 2) ; k++){
                for(int l = 0 ; l < *(ar2.get_dim_sizes() + 3) ; l++){
                    int ind[4] = {i ,j ,k, l};
                    ar2.set_elem(4, ind, i+j+k+l);
                }
            }
        }
    }
    for(int i  =  0 ; i < *ar2.get_dim_sizes() ; i++){
        for(int j = 0 ; j < *(ar2.get_dim_sizes() + 1) ; j++){
            for(int k = 0 ; k < *(ar2.get_dim_sizes() + 2) ; k++){
                for(int l = 0 ; l < *(ar2.get_dim_sizes() + 3) ; l++){
                    int a = ar2[i][j][k][l];
                    std::cout << a << " ";
                }
                std::cout<<std::endl;
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }
    
    
}

//
//  main.cpp
//  Complex
//
//  Created by Chan Yong Lee on 01.03.20.
//  Copyright © 2020 Chan Yong Lee. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>

class Complex {
private:
    double real, img;
    
public:
    Complex(double real, double img) : real(real), img(img){};
    Complex(const Complex &c){
        real = c.real;
        img = c.img;
    }
    Complex(const char* str);
    
    //리턴값을 무엇으로 할지 항상 고민해봐야한다!!
    Complex operator+(const Complex& c);
    Complex operator-(const Complex& c);
    Complex operator*(const Complex& c);
    Complex operator/(const Complex& c);
    Complex& operator=(const Complex& c);
    
    Complex operator+(const char* str);
    Complex operator-(const char* str);
    Complex operator*(const char* str);
    Complex operator/(const char* str);
    
    Complex& operator+=(const Complex& c);
    Complex& operator-=(const Complex& c);
    Complex& operator*=(const Complex& c);
    Complex& operator/=(const Complex& c);
    
    double before_comma_to_double(const char* str, int digits);
    double after_comma_to_double(const char* str, int digits);
    //converts real number written in string into double type
    double str_to_double(const char* str, int digist_before_comma, int digits_after_comma);
    
    void println() {
        std::cout << "( " << real << " , " << img << " ) " << std::endl; }
    
    friend Complex operator+(const Complex& a, const Complex& b);
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};
Complex::Complex(const char* str){
    int pos_i = -1;
    int len = strlen(str);
    int first_comma = len;
    for(int i = 0 ; i < len ; i++){
        if(*(str+i) == 'i'){
            pos_i = i;
        }
        if(*(str+i) == '.'){
            first_comma = i;
        }
    }
    double real_tmp = 0;
    double img_tmp = 0;
    //no imaginary number
    if(pos_i == -1){
        int digit_before_comma;
        int digit_after_comma;
        
        if(*(str) == '-'){
            digit_before_comma = first_comma - 1;
        }
        else{
            digit_before_comma = first_comma;
        }
        
        digit_after_comma = len - first_comma -1;
        
        char* before = new char[len];
        for(int i= 0 ; i < len; i++){
            *(before + i)  = *(str + i);
        }
        
        real_tmp = str_to_double(before, digit_before_comma, digit_after_comma);
    }
    else{
        int digit_before_comma_real = 0;
        int digit_after_comma_real = 0;
        int digit_before_comma_img = 0;
        int digit_after_comma_img = 0;
        int iter = 0;
        int counter = 0;
        bool real_minus = false;
        bool img_minus = false;
        if(*str == '-'){
            iter = 1;
            real_minus =true;
        }
        if(*(str + pos_i - 1) == '-'){
            img_minus = true;
        }
        
        
        while(*(str + iter) != '.'){
            iter++;
            counter++;
        }
        digit_before_comma_real = counter;
        counter = 0;
        iter++;
        
        while(*(str + iter) >= 48 && *(str + iter) <= 57){
            iter++;
            counter++;
        }
        digit_after_comma_real = counter;
        counter = 0;
        iter = pos_i + 1;
        
        while(*(str + iter) != '.' && iter < len){
            iter++;
            counter++;
        }
        digit_before_comma_img = counter;
        counter = 0;
        iter++;
        
        while(*(str + iter) >= 48 && *(str + iter) <= 57){
            iter++;
            counter++;
        }
        digit_after_comma_img = counter;
        
        
        char* real_str;
        char* img_str;
        if(real_minus){
            real_str = new char[1 + digit_before_comma_real + 1 + digit_after_comma_real];
        }
        else{
            real_str = new char[digit_before_comma_real + 1 + digit_after_comma_real];
        }
        if(img_minus){
            img_str = new char[1 + digit_before_comma_img + 1 + digit_after_comma_img];
        }
        else{
            img_str = new char[digit_before_comma_img + 1 + digit_after_comma_img];
        }
        
        for(int i = 0 ; i < pos_i - 1 ; i++){
            *(real_str + i) = *(str+i);
        }
        if(img_minus){
            *img_str = '-';
            for(int i = pos_i + 1 ; i < len ; i++){
                *(img_str + i - pos_i) = *(str + i);
            }
        }
        else{
            for(int i = pos_i + 1 ; i < len ; i++){
                *(img_str + i - pos_i -1) = *(str + i);
            }
        }
        
        real_tmp = str_to_double(real_str, digit_before_comma_real, digit_after_comma_real);
        img_tmp = str_to_double(img_str, digit_before_comma_img, digit_after_comma_img);
    }
    
    real = real_tmp;
    img = img_tmp;
}

Complex operator+(const Complex& a, const Complex& b){
    Complex tmp(a.real+b.real , a.img+b.img);
    return tmp;
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
  os << "( " << c.real << " , " << c.img << " ) ";
  return os;
}

Complex Complex::operator+(const Complex& c){
    Complex tmp(real + c.real, img + c.img);
    return tmp;
}
Complex Complex::operator-(const Complex& c){
    Complex tmp(real - c.real, img - c.img);
    return tmp;
}
Complex Complex::operator*(const Complex& c){
    Complex tmp(real * c.real - img * c.img, real * c.img + c.real * img);
    return tmp;
}
Complex Complex::operator/(const Complex& c){
    Complex tmp(
        (real*c.real + img*c.img)/(c.real*c.real + c.img*c.img),
        (c.real*img - real*c.img)/(c.real*c.real + c.img*c.img)
        );
    return tmp;
}

Complex Complex::operator+(const char* str){
    Complex tmp(str);
    return *this + tmp;
}
Complex Complex::operator-(const char* str){
    Complex tmp(str);
    return *this - tmp;
}
Complex Complex::operator*(const char* str){
    Complex tmp(str);
    return (*this)*tmp;
}
Complex Complex::operator/(const char* str){
    Complex tmp(str);
    return (*this)/tmp;
}

Complex& Complex::operator=(const Complex& c){
    real = c.real;
    img = c.img;
    
    return *this;
}
Complex& Complex::operator+=(const Complex& c) {
  (*this) = (*this) + c;
  return *this;
}
Complex& Complex::operator-=(const Complex& c) {
  (*this) = (*this) - c;
  return *this;
}
Complex& Complex::operator*=(const Complex& c) {
  (*this) = (*this) * c;
  return *this;
}
Complex& Complex::operator/=(const Complex& c) {
  (*this) = (*this) / c;
  return *this;
}

double Complex::str_to_double(const char* str, int digist_before_comma, int digits_after_comma){
    double res = 0;
    char* before_comma = new char[digist_before_comma];
    char* after_comma = new char[digits_after_comma];
    
    if(*str == '-'){
        for(int i = 0; i < digist_before_comma ; i++){
            *(before_comma + i) = *(str + 1 + i);
        }
        int tmp = digist_before_comma == 0? 1 : 0;
        for(int i = 0; i < digits_after_comma ; i++){
            *(after_comma + i) = *(str + 2 + digist_before_comma + tmp + i);
        }
        
        res = -1.0*(before_comma_to_double(before_comma, digist_before_comma)
                    + after_comma_to_double(after_comma, digits_after_comma));
    }
    else{
        for(int i = 0; i < digist_before_comma ; i++){
            *(before_comma + i) = *(str + i);
        }
        int tmp = digist_before_comma == 0? 1 : 0;
        for(int i = 0; i < digits_after_comma ; i++){
            *(after_comma + i) = *(str + tmp+ digist_before_comma + 1 + i);
        }
        
        res = (before_comma_to_double(before_comma, digist_before_comma)
                    + after_comma_to_double(after_comma, digits_after_comma));
    }
    
    return res;
}

double Complex::before_comma_to_double(const char* str, int digits){
    double res = 0;
    for(int i = digits-1 ; i >= 0 ; i--){
        res += (*(str+i)-48)*pow(10, digits-1 - i);
    }
    
    return res;
}

double Complex::after_comma_to_double(const char* str, int digits){
    double res = 0;
    for (int i = 0 ; i < digits ; i++){
        res += (*(str+i)-48)*pow(10, -(i+1));
    }
    
    return res;
}

int main(int argc, const char * argv[]) {
    
    /*
    std::cout<<a.str_to_double("111111.111111", 6, 6)<<std::endl;
    printf("%f \n", a.str_to_double("111111.111111", 6, 6));
    std::cout<<a.str_to_double("0.111", 0, 3)<<std::endl;
    std::cout<<a.str_to_double("112.111", 3, 3)<<std::endl;
    std::cout<<a.str_to_double("-111", 3, 0)<<std::endl;
    std::cout<<a.str_to_double("-0.111", 0, 3)<<std::endl;
    std::cout<<a.str_to_double("-112.111", 3, 3)<<std::endl;
     */
    Complex a(0, 0);
    a = "-1.1 + i3.923" + a;
    std::cout << "a 의 값은 : " << a << " 이다. " << std::endl;
    return 0;
}

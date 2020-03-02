//
//  main.cpp
//  myStringClass
//
//  Created by Chan Yong Lee on 29.02.20.
//  Copyright © 2020 Chan Yong Lee. All rights reserved.
//

#include <iostream>

class MyString {
    char *str;
    int len;
    int memory_capacity;

public:
    
    MyString(int capacity);
    MyString(char c);  // 문자 c 가 n 개 있는 문자열로 정의
    MyString(const char *s);
    MyString(const MyString &s);
    ~MyString();
    
    MyString& assign(const MyString& s);
    MyString& assign(const char* s);
    
    //returns the memomry capacity of this string objext
    int capacity();
    
    //only adjusts memory capacity, if there was some memory already reserved for str
    void reserve(int size);
    
    char at(int i) const;
    
    //이렇게 참조자를 쓰면 좋은것이, 함수를 호출하는 과정에서 불필요한 복사가 발생하지 않고 원래 객체를 참조만 하게 된다! 효율적!
    MyString& insert(int loc, const MyString& str);
    MyString& insert(int loc, const char* str);
    MyString& insert(int loc, char c);
    
    MyString& erase(int loc, int num);
    
    void add_string(const MyString &s);   // str 뒤에 s 를 붙인다.
    void copy_string(const MyString &s);  // str 에 s 를 복사한다.
    bool same_with(const MyString &s);
    
    MyString operator+(const MyString &s);
    MyString operator=(const MyString &s);
    char& operator[](const int index);
    
    int find(int find_from, const MyString &s) const;
    int find(int find_from, const char* s) const;
    int find(int find_from, char c) const;
    
    int compare(const MyString& s) const;
    
    int getLength() const;                       // 문자열 길이 리턴
    char* toString() const;
    void print();
    void println();
    
    //operator overloading
    bool operator==(MyString& str);
};
MyString::MyString(int capacity){
    str = new char[capacity];
    len = 0;
    memory_capacity = capacity;
}
MyString::MyString(char c){
    str = new char[1];
    str[0] = c;
    len = 1;
}

MyString::MyString(const char *s){
    int counter = 0;
    while(*(s + counter)){
        counter++;
    }
    len = counter;
    
    str = new char[counter + 1];
    //set the end of the string as null
    str[counter] = 0;
    for(int i = 0 ; i < counter ; i++){
        str[i] = s[i];
    }
}

MyString::MyString(const MyString &s){
    //std::cout<<"copy constructor called"<<std::endl;
    len = s.len;
    
    str = new char[len];
    //set the end of the string as null
    for(int i = 0 ; i < len ; i++){
        str[i] = s.str[i];
    }
}

MyString::~MyString(){
    delete[] str;
}

MyString& MyString::assign(const MyString& s){
    
    //reserves more memory if length of s is bigger than the length of str in this ob
    reserve(s.getLength());
    len = s.getLength();
    
    for(int i = 0 ; i < len ; i++){
        str[i] = s.toString()[i];
    }
    
    return *this;
    
}

MyString& MyString::assign(const char* s){
    MyString* tmp = new MyString(s);
    copy_string(*tmp);
    
    return *this;
}

char* MyString::toString() const{
    return str;
}

int MyString::capacity(){
    return memory_capacity;
}

void MyString::reserve(int size){
    if(size > memory_capacity){
        
        char* tmp = new char[size];
        for(int i = 0 ; i < len ; i++){
            tmp[i] = str[i];
        }
        delete [] str;
        
        memory_capacity = size;
        str = tmp;
    }
}

void MyString::add_string(const MyString &s){
    int newlen = len + s.getLength();
    
    char* tmp = new char[getLength() + s.getLength() + 1];
    
    for(int i = 0 ; i < len ; i++){
        *(tmp+i) = *(str + i);
    }
    for(int i = 0 ; i < s.getLength(); i++){
        *(tmp + len + i) = *(s.toString() + i);
    }
    
    delete [] str;
    
    str = tmp;
    len = newlen;
    
}

void MyString::copy_string(const MyString &s){
    reserve(s.getLength());
    len = s.getLength();
    for(int i = 0 ; i < s.getLength() ; i++){
        str[i] = s.toString()[i];
    }
}

MyString MyString::operator+(const MyString &s){
    MyString tmp(s);
    add_string(s);
    return *this;
}
MyString MyString::operator=(const MyString &s){
    MyString tmp(s);
    copy_string(s);
    return *this;
}
char& MyString::operator[](const int index){
    return str[index];
}

int MyString::getLength() const{
    return len;
}
bool MyString::same_with(const MyString &s){
    if(len != s.getLength()){
        return false;
    }
    else{
        for(int i = 0 ; i < len ; i++){
            if(str[i] != s.toString()[i]){
                return false;
            }
        }
        return true;
    }
}

int MyString::find(int find_from, const MyString &s) const{
    if(find_from > len - 1){
        return -1;
    }
    else if(len - find_from < s.getLength()){
        return -1;
    }
    else{
        int i1 = find_from;
        while(str[i1]){
            int tmp = i1;
            int i2 = 0;
            if(str[tmp] == s.toString()[i2]){
                if(tmp + s.getLength() > len){
                    return -1;
                }
                else{
                    while(s.toString()[i2]){
                        if(str[tmp] != s.toString()[i2]){
                            break;
                        }
                        else{
                            if(i2 == s.getLength() - 1){
                                return i1;
                            }
                        }
                        tmp++;
                        i2++;
                    }
                }
            }
            i1++;
        }
    }
    return -1;
}

int MyString::find(int find_from, const char* s) const{
    MyString tmp(s);
    return find(find_from, tmp);
}
int MyString::find(int find_from, char c) const{
    MyString tmp(c);
    return find(find_from, tmp);
}

char MyString::at(int i) const{
    if(i >= 0 && i < len){
        return str[i];
    }
    else{
        return NULL;
    }
}


MyString& MyString::insert(int loc, const MyString& s){
    if(loc >= 0 && loc < len){
        char* tmp = new char[len];
        tmp = str;
        reserve(len+s.getLength());
        
        for(int i = loc ; i < len; i++){
            str[s.getLength() + i] = tmp[i];
        }
        for(int i = 0 ; i < s.getLength() ; i++){
            str[loc + i] = s.toString()[i];
        }
        len += s.getLength();
        
        return *this;
    }
    else{
        std::cout << "invalid location(index)" << std::endl;
        return *this;
    }
}

MyString& MyString::insert(int loc, const char* str){
    MyString tmp(str);
    return insert(loc, tmp);
}
MyString& MyString::insert(int loc, char c){
    MyString tmp(c);
    return insert(loc, tmp);
}

MyString& MyString::erase(int loc, int num){
    if (num < 0 || loc < 0 || loc > len) return *this;
    for(int i = 0 ; i < len - loc - num; i++){
        str[loc +i] = str[loc+num+i];
    }
    len -= num;
    return *this;
}
 
int MyString::compare(const MyString& s) const{
    int shortLen = len <= s.getLength() ? len : s.getLength();
    
    while(str[shortLen]){
        
        if(str[shortLen] > s.toString()[shortLen]){
            return 1;
        }
        else if(str[shortLen] < s.toString()[shortLen]){
            return -1;
        }

        shortLen++;
    }
    
    if(len == s.getLength()){
        return 0;
    }
    else if( len > s.getLength()){
        return 1;
    }
    
    return -1;
}

void MyString::print(){
    for(int i = 0 ; i < len ; i++){
        std::cout<<str[i];
    }
}

void MyString::println(){
    for(int i = 0 ; i < len ; i++){
        std::cout<<str[i];
    }
    std::cout<<std::endl;
}

//operator overloading
bool MyString::operator==(MyString& str){
    return !compare(str);
}
int main(int argc, const char * argv[]) {
    
    // insert code here...
    
    MyString str = MyString("chan");
    /*
    MyString str1 = MyString("lee");
    std::cout << str.toString()<<std::endl;
    str.add_string(str1);
    std::cout << str.toString()<<std::endl;
    //str.copy_string(str1);
    //std::cout << str.toString()<<std::endl;
    std::cout << "length " << str.getLength() << std::endl;
    std::cout << str.same_with(str1) << std::endl;
    //std::cout << str.find("chanddd") <<std::endl;
     */
    
    /*
    MyString str1("hello world");
    MyString str2("hallo welt");
    
    str1.println();
    str1 = str2;
    str2.println();
    */
    
    /*
    MyString str3("very very very long string");
    str3.println();
    str3.assign("short string");
    str3.println();
    str3.assign("very long string");
    str3.println();
    str3 = (str);
    str3.println();
    MyString str4("very very very long string");
    str4.reserve(30);
    */
    /*
    std::cout << "Capacity : " << str4.capacity() << std::endl;
    std::cout << "String length : " << str4.getLength() << std::endl;
    str4.println();
    
    MyString str5("very long string");
    MyString str6("<some string inserted between>");

    std::cout << "Capacity : " << str5.capacity() << std::endl;
    std::cout << "String length : " << str6.getLength() << std::endl;
    str5.println();

    str5.insert(5, str6);
    str5.println();
    
    str5.erase(3, 3);
    str5.println();
    
    
    std::cout<<"--------------------------------------------------"<<std::endl;
    MyString str7("this is a very very long string");
    std::cout << "Location of first <very> in the string : " << str7.find(0, "very")
         << std::endl;
    std::cout << "Location of second <very> in the string : "
         << str7.find(str7.find(0, "very") + 1, "very") << std::endl;
    
    std::cout<<"--------------------------------------------------"<<std::endl;
    
    MyString str8("a word");
    MyString str9("sentence");
    MyString str10("sentence");

    if (str8 == str9)
      std::cout << "str8 와 str9 같다." << std::endl;
    else
      std::cout << "st8 와 str9 는 다르다." << std::endl;

    if (str9 == str10)
      std::cout << "str9 와 str10 는 같다." << std::endl;
    else
      std::cout << "st9 와 str10 는 다르다" << std::endl;
     */
    
    MyString s("abcdef");
    s[3] = 'c';

    s.println();
}

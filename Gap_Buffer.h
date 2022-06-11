#ifndef _GAP_BUFFER_INIT_H
#define _GAP_BUFFER_INIT_H
//#include"Gap_buffer_init.cpp"
#include <iostream>
#include <string>
#include <fstream>

class MyGap_Buffer{
    private:
    char *buffer;
	int gap_size;
	int gap_left;
	int gap_right;
	int size;
    public:
    MyGap_Buffer() ;
    MyGap_Buffer(std::string) ; 
    MyGap_Buffer(const MyGap_Buffer&) ;
    MyGap_Buffer(MyGap_Buffer &&) ;
    ~MyGap_Buffer();
    public:
    MyGap_Buffer &operator=(const MyGap_Buffer &);
    MyGap_Buffer &operator=(MyGap_Buffer && );
    public:
    void Print_buf();
    int get_left();
    int get_rigth();
    int get_gap_size();
    void move_left(int );
    void move_right(int );
    void move_cursor_to(int );
    void expand(int , int) ;
    void insert_string(std::string , int );
    void insert_char(char , int );
    int Size();
    void empty();
    std::string get_string(int , int );
    char get_char(int );
    void erase(int , int );
    bool is_empty();
};

#endif
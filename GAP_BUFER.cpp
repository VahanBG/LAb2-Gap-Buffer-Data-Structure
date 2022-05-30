//HELLO GAP BUFER!!!
// C++ program of implementation of gap buffer

#include <iostream>
#include<vector>
#include<string>
#include<cstring>

class MyGap_Buffer{ 
private:    
char *buffer;
int gap_size;
int gap_left;
int gap_right;
int size;

public:
MyGap_Buffer()
{
	gap_size = 50;
    buffer = new char[gap_size];     
    gap_left = 0;
    gap_right = gap_size - gap_left-1;
    size = 20;
	set_buffer(size);
}
MyGap_Buffer(int Gap_size,int Size):MyGap_Buffer()
{
this-> gap_size= Gap_size;
buffer = new char[gap_size];
this-> size = Size;
set_buffer(size);
}
MyGap_Buffer( const MyGap_Buffer & other){
    this->buffer = new char[50];
    this->gap_size = other.gap_size;
    this->gap_left =other.gap_left;
    this-> gap_right =other.gap_right;
    this->size = other.size;
	for(int i = 0 ; i < other.size ; i++){
        this->buffer[i] = other.buffer[i];
    }
}
MyGap_Buffer(MyGap_Buffer && other){
	this->buffer = new char[50];
    this->gap_size = other.gap_size;
    this->gap_left =other.gap_left;
    this-> gap_right =other.gap_right;
    this->size = other.size;
	for(int i = 0 ; i < other.size ; i++){
        this->buffer[i] = other.buffer[i];
    }

}
~MyGap_Buffer()
{
   delete []buffer;
}
MyGap_Buffer & operator=(const MyGap_Buffer& other){
        return *this;
    }
MyGap_Buffer& operator=(MyGap_Buffer&& other) {
	this->buffer = new char[50];
    this->gap_size = other.gap_size;
    this->gap_left =other.gap_left;
    this-> gap_right =other.gap_right;
    this->size = other.size;
	for(int i = 0 ; i < other.size ; i++){
        this->buffer[i] = other.buffer[i];
    }
            return *this;
    }
/*void operator<<(std::ostream& os, const string& str)
{
    std::cout << str;
    os << str;
}*/
//Ֆունկցիան տեղադրում է տող համապատասխան դիրքում, առաջին արգումենտը այն ինչ պետք է դնի
// երկրորդը ուտեղ
void insert_string(std::string input, int position)
{   
   
	int len = input.length();
	int i = 0;
    
	if (position != gap_left) {
	move_cursor(position);
	}
	while (i < len) {
	     if (gap_right == gap_left) {
			int k = 10;
			grow(k, position);
		}
		buffer[gap_left] = input[i];
		gap_left++;
		i++;
		position++;
	}
}
void insert_char(char input_char, int position)
{   
   	int i = 0;
    
	if (position != gap_left) {
	move_cursor(position);
	}
	if (gap_right == gap_left) {
		int k = 10;
		grow(k, position);
	}
		buffer[gap_left] = input_char;
		gap_left++;
		position++;
}
void set_buffer(int Size){
    this->size = Size;
    for (int i = 0; i < size; i++) {
        		buffer[i] = '_';
	}
}
char get_char(int position){
   return buffer[position];
}
std::string get_string(int first_pos , int last_pos){
	std::string rezult ={};
	for(int i = first_pos ; i <= last_pos ; ++i){
		rezult +=buffer[i];
	}
	return rezult;
}
void empty_buf(){
	buffer = nullptr;
	size = 0 ;
}
// ֆունկցիան տեղափոխում է դեպի աջ զանգվածով 
void left(int position)
{
	
	while (position < gap_left) {
		gap_left--;
		gap_right--;
		buffer[gap_right+1] = buffer[gap_left];
		buffer[gap_left]='_';
	}
}
//Ֆունկիան տեղաշարժում է դեպի ձախ զանգվածով
void right(int position)
{
	
	while (position > gap_left) {
		gap_left++;
		gap_right++;
		buffer[gap_left-1] = buffer[gap_right];
		buffer[gap_right]='_';
	}
}
void Print_buf(){
     std::cout << "the gap buffer "
		<< "with size "<< size << std:: endl;
        for (int i = 0; i < size; i++) {
		std::cout << buffer[i]<<" ";
	}
     std::cout<<std::endl;
 }
// Աճեցնում է զանգվածը տրված չափով
void grow(int  num_to_grow, int position)
{
	char copy_to_grow[size];
	    for (int i = position; i < size; i++) {
		copy_to_grow[i - position] = buffer[i];	
	    }
	
	for (int i = 0; i < num_to_grow; i++) {
		buffer[i + position] = '_';
	}
	
	for (int i = 0; i < position + num_to_grow; i++) {
		buffer[position + num_to_grow + i] = copy_to_grow[i];
	}
	size += num_to_grow;
	gap_right+=num_to_grow;
}
//Ֆունկցիան տեղաշարժում է կուրսորը ստուգելով դրա գտնվելու ինդեքսի դիրքը
void move_cursor(int position)
{
	if (position < gap_left) {
		left(position);
	}
	else {
		right(position);
	}
}
};

int main()
{

	 MyGap_Buffer aaa(50,15);
	 aaa.Print_buf();
	 aaa.insert_char('V',0);
	 aaa.Print_buf();
	 aaa.insert_string("Vahan",0);
	 aaa.Print_buf();
	 std::cout<<"get char "<<aaa.get_char(0)<<std::endl;
	 std::cout<<"get string "<<aaa.get_string(0 , 4)<<std::endl;
	 aaa.empty_buf();
	 aaa.Print_buf();
	  
     return 0;
}

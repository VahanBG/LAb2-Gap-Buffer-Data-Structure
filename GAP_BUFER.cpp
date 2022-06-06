//HELLO GAP BUFER!!!
// C++ program of implementation of gap buffer

#include <iostream>
#include<vector>
#include<string>
#include<cstring>
#include<fstream>

class MyGap_Buffer{ 
private:    
char *buffer;
int gap_size;
int gap_left;
int gap_right;
int size;

public:   //Default constructor
MyGap_Buffer():gap_size{},buffer{nullptr},gap_left{},gap_right{gap_size - gap_left-1},size{0}
{}
MyGap_Buffer(std::string Myword) //Parameterized constructor
{
this-> gap_size = Myword.length() * 2  ;
buffer = new char[gap_size];
set_buffer(gap_size);	
gap_left = 0;
gap_right = gap_size - gap_left-1;
this-> size = Myword.length() + gap_size;
insert_string(Myword , gap_left) ;

}
MyGap_Buffer( const MyGap_Buffer & other){ //Copy constructor
    this->gap_size = other.gap_size;
	this->buffer = new char[other.gap_size];
    this->gap_left =other.gap_left;
    this-> gap_right =other.gap_right;
    this->size = other.size;
	for(int i = 0 ; i < other.size ; i++){
        this->buffer[i] = other.buffer[i];
    }
}
MyGap_Buffer(MyGap_Buffer && other):gap_size{other.gap_size},gap_left{other.gap_left},gap_right{other.gap_right}
{
	std::swap(buffer , other.buffer);
	delete [] other.buffer;
	other.buffer = nullptr;
	other.gap_size = 0 ;	
	other.gap_left = 0 ;
    other.gap_right  = 0 ;
}
~MyGap_Buffer() //Destructor
{
   delete []buffer;
   buffer = nullptr;
}
MyGap_Buffer& operator = (const MyGap_Buffer& other){//Copy operator assignment =
          this->gap_size = other.gap_size;
          this->gap_left =other.gap_left;
          this-> gap_right =other.gap_right;
          this->size = other.size; 
		  this-> buffer = new char[other.gap_size];          
		  for(int i = 0 ; i < other.size ; i++){
             this->buffer[i] = other.buffer[i];
          }
          return *this ;
}
MyGap_Buffer& operator=(MyGap_Buffer&& other) //Move operator assignment =
{
	std::swap(gap_size , other.gap_size);
	std::swap(buffer , other.buffer);
	std::swap(gap_left , other.gap_left);
    std::swap( gap_right , other.gap_right );
    std::swap(size , other.size);
	     return *this ;
}



void set_buffer(int Size_buf ){
    for (int i = 0; i < Size_buf; i++) {
        		buffer[i] = '-';
	}
}
char get_char(int position){
	if(position >= size){
      std::cout<<"your position out of your ARRAY"<<std::endl;
	  return '0';
	}
	return buffer[position];
	
}
std::string get_string(int first_pos , int last_pos){
	std::string rezult ={};
	if((first_pos >= size) || (last_pos >= size)){
        return "your position out of your ARRAY";
	}
	for(int i = first_pos ; i <= last_pos ; ++i){
		rezult +=buffer[i];
	}
	return rezult;
}
void empty(){
	delete [] buffer;
	buffer = nullptr;
	size = 0 ;
}

void Print_buf(){
     std::cout << "the gap buffer "
		<< "with size "<< size << " and buf_size "<<gap_size<< std:: endl;
        for (int i = 0; i < gap_size + size; i++) {
		std::cout << buffer[i]<<" ";
	}
     std::cout<<std::endl;
 }
int Size(){
	return size;
}
int get_left(){
	return gap_left ;
}
int get_rigth(){
	return gap_right;
}

int get_gap_size(){
	return gap_size;
}
void left(int position)
{
    // Move the gap left character by character
    // and the buffers
    while (position < gap_left) {
        gap_left--;
        gap_right--;
        buffer[gap_right+1] = buffer[gap_left];
        buffer[gap_left]='_';
    }
}
 
// Function that is used to move the gap
// right in the array
void right(int position)
{
    // Move the gap right character by character
    // and the buffers
    while (position > gap_left) {
        gap_left++;
        gap_right++;
        buffer[gap_left-1] = buffer[gap_right];
        buffer[gap_right]='_';
    }
}
// Function to control the movement of gap
// by checking its position to the point of
// insertion
void move_cursor(int position)
{
    if (position < gap_left) {
        left(position);
    }
    else {
        right(position);
    }
}
 
// Function to insert the string to the buffer
// at point position
void insert_string(std::string input, int position)
{
    int len = input.length();
    int i = 0;
 
    // If the point is not the gap check
    // and move the cursor to that point
    if (position != gap_left) {
        move_cursor(position);
    }
 
    // Insert characters one by one
    while (i < len) {
        // If the gap is empty grow the size
        if (gap_right == gap_left) {
            int k = 10;
            grow(k, position);
        }
 
        // Insert the character in the gap and
        // move the gap
        buffer[gap_left] = input[i];
        gap_left++;
        i++;
        position++;
    }
	gap_size = gap_right - gap_left;
	
}
void grow(int k, int position)
{
 
    char a[size];
 
    // Copy characters of buffer to a[]
    // after position
    for (int i = position; i < size; i++) {
        a[i - position] = buffer[i];
         
    }
     
    // Insert a gap of k from index position
    // gap is being represented by '-'
    for (int i = 0; i < k; i++) {
        buffer[i + position] = '_';
    }
     
    // Reinsert the remaining array
    for (int i = 0; i < position + k; i++) {
        buffer[position + k + i] = a[i];
    }
 
    size += k;
    gap_right+=k;
}
void grow(int k, int position)
{
 
    char a[size];
 
    // Copy characters of buffer to a[]
    // after position
    for (int i = position; i < size; i++) {
        a[i - position] = buffer[i];
         
    }
     
    // Insert a gap of k from index position
    // gap is being represented by '-'
    for (int i = 0; i < k; i++) {
        buffer[i + position] = '_';
    }
     
    // Reinsert the remaining array
    for (int i = 0; i < position + k; i++) {
        buffer[position + k + i] = a[i];
    }
 
    size += k;
    gap_right+=k;
}
};

int main()
{ 
	MyGap_Buffer aaa("vahan");
	aaa.Print_buf();
	std::cout<<"left is in: "<<aaa.get_left()<<std::endl;
	std::cout<<"rigth is in: "<<aaa.get_rigth()<<std::endl;


     return 0;
}

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
MyGap_Buffer():gap_size{},buffer{nullptr},gap_left{},gap_right{gap_size - gap_left-1},size{}
{}
MyGap_Buffer(std::string Myword) //Parameterized constructor
{
this-> gap_size = Myword.length() * 2  ;
this-> size = Myword.length() + gap_size;
buffer = new char[size];
for(int i = 0 ; i < Myword.length() ; i++ ){
    buffer[i] = Myword[i];
}	
for(int i = Myword.length() ; i < size ; i++ ){
    buffer[i]= '-';
}
gap_left = size - gap_size;
gap_right = size - 1;



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

void Print_buf(){
     std::cout << "the gap buffer "
		<< "with size "<< size << " and buf_size "<<gap_size<< std:: endl;
        for (int i = 0; i < size; i++) {
		std::cout << buffer[i]<<" ";
	}
     std::cout<<std::endl;
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
void move_left(int index_to) // Move the gap left character by character and the buffers
{
    if(index_to >= 0){
         while (index_to < gap_left) {
             gap_left--;
             gap_right--;
             buffer[gap_right+1] = buffer[gap_left];
             buffer[gap_left]='-';
            }
    }
    else{std::cout<<"your cursot is out of your array"<<std::endl;}
}
void move_right(int index_to) //Move the gap right character by character and the buffers
{
    if(index_to + gap_size <= size){
         while (index_to > gap_left) {
             gap_left++;
             gap_right++;
             buffer[gap_left-1] = buffer[gap_right];
             buffer[gap_right]='-';
        }
    }
    else{std::cout<<"your cursot is out of your array"<<std::endl;}
}
void move_cursor_to(int index_to)
{
    if (index_to < gap_left) {
        move_left(index_to);
    }
    else {
        move_right(index_to);
    }
}
void expand(int num_to_exp, int index)
{
    char mid[ size  ];
    if((index < gap_left ) || (index > gap_right)){
        std::cout<<"you can not expend new buffer in that position"<<std::endl;
    }
    else{
        for (int i = index ; i < size; i++) { // Copy characters of buffer to mid[] after "index"
             mid[i - index ] = buffer[i];
        }   
       /* std::cout<<"mid[] is: ";
        for(int i = 0 ; i < size - index ; i++){
            std::cout<<mid[i];
        }*/
        std::cout<<std::endl;
        for (int i = 0; i < num_to_exp; i++) {// Insert a gap from index position gap is being represented by '-'
             buffer[i + index] = '-';
        }
        std::cout<<"buffer i + index = "<<std::endl;
        for(int i = 0 ; i < num_to_exp ; i++ ){
            std::cout<<buffer[i+index];
        }
        std::cout<<std::endl;
        for (int i = 0; i < index + num_to_exp; i++) { // Reinsert the remaining array
             buffer[ index + num_to_exp + i] = mid[i];
        }
          size += num_to_exp;
          gap_right+=num_to_exp;
          gap_size+= num_to_exp;
    }
}
void insert_string(std::string input, int position)
{
   // int len = input.length();
  //  int i = 0;
    if (position != gap_left) { //move the cursor to index
        move_cursor_to(position); 
        //std::cout<<"move to cursor"<<std::endl;
    }   
    for(int i = 0 ; i < input.length(); ++i){ //while (i < len) { // Insert characters one by one
           if (gap_right == gap_left) {  // If the gap is empty expend the buffer
             int exp_gap =  10 ;// input.length() * 2 ;
             expand(exp_gap, position);
            }           
            buffer[gap_left] = input[i]; // Insert the sring in the gap and  move the gap
            gap_left++;
            position++;
    }
	gap_size = gap_right - gap_left + 1;
	

}
};
int main(){
     MyGap_Buffer aaa("vahan");
     aaa.Print_buf();
     //aaa.insert_string("vahan" , 10);
     //aaa.move_cursor_to(0);
    //aaa.expand(4 , 9);
    aaa.expand( 20 , 5);
   // aaa.insert_string("his name is ansddddd ", 0 );  
     
     //aaa.insert_string("000000000" , 9);
     aaa.Print_buf();
     std::cout<<"left is: "<<aaa.get_left()<<std::endl;
     std::cout<<"rigth is: "<<aaa.get_rigth()<<std::endl;
   


    
}
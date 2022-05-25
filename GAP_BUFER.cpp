//HELLO GAP BUFER!!!
// C++ program of implementation of gap buffer

#include <bits/stdc++.h>
#include<string>
#include<cstring>

class MyGap_Buffer{ 
private:      

char *buffer;
int gap_size;
int gap_left;
int gap_right;
int size;

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

public:

MyGap_Buffer()
{
     buffer = new char[50];
     gap_size = 10;
      gap_left = 0;
      gap_right = gap_size - gap_left-1;
      size = 10;
	  set_buffer(size);
}
MyGap_Buffer(int Gap_size,int Size):MyGap_Buffer()
{
	buffer = new char[50];
this-> gap_size= Gap_size;
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


//Ֆունկցիան տեղադրում է տող համապատասխան դիրքում, առաջին արգումենտը այն ինչ պետք է դնի
// երկրորդը ուտեղ
void insert(std::string input, int position)
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
void set_buffer(int Size){
    this->size = Size;
    for (int i = 0; i < size; i++) {
        		buffer[i] = '_';
	}
}

 void Print_bugf(){
     std::cout << "the gap buffer "
		<< "with size "<< size << std:: endl;
        for (int i = 0; i < size; i++) {
		std::cout << buffer[i]<<" ";
	}
     std::cout<<std::endl;
 }
};

int main()
{
    MyGap_Buffer aaa;
    aaa.set_buffer(15);
    aaa.Print_bugf();
     std::string input = "VAHAN";
    int Position = 0; 
    //std::cout<<"Insert the word, wich you want tu insert"<<std::endl;
    //std::cin>>input;
    //std::cout<<"Insert where you want input"<<std::endl;
    //std::cin>>Position;
   // aaa.grow(5,Position);
   //aaa.insert(input ,5 );
    //aaa.Print_bugf();
    MyGap_Buffer bbb( 10 , 10);
	bbb.Print_bugf();
	bbb.insert("Vahan",0);
	bbb.Print_bugf();
    MyGap_Buffer ccc;
     ccc.Print_bugf();

     return 0;
}

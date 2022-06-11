#include<iostream>
#include "Gap_Buffer.h"
 
 int main()
 {
    
    MyGap_Buffer aaa("vahan");
	 aaa.Print_buf();
	 aaa.insert_string("vahan", 0);
	 aaa.Print_buf();
	 aaa.erase(10 , 14);
	 aaa.Print_buf();
	 aaa.erase( 0 , 1);
	 aaa.Print_buf();
	 aaa.expand( 10 , 5);
	 aaa.Print_buf();
	 aaa.erase( 1 , -5);
     
	return 0;
 }
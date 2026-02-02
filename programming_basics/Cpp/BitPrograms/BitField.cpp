

#include<iostream>


using u32 = std::uint32_t;

void test(u32& val){
  
  std::cout<<"val: "<<val<<std::endl;
  
  return;
}


void set(u32& val, u32 pos){
  val =  val | (u32(1) << pos);
}

void clear(u32 val, u32 pos){
  val = (val & ~(u32(1) << pos)); 
}

void toggle(u32& val, u32 pos){

  val =  val ^ (u32(1) << pos); 
}


int main(){
  
  u32 value = 0;
  
  set(value, 1);
  toggle(value, 1);
  clear(value, 1); 
  test(value);

  set(value, 1);
  toggle(value, 1);
  toggle(value, 1);
  toggle(value, 1);
  test(value);
  
  return 0;
}


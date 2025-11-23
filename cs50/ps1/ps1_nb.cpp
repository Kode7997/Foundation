#include<cstdlib>
#include<cstdio>
#include<cstring>

#define TRUE 1
#define FALSE 0


void number_of_bytes(){

    unsigned long int bc = 0;
    unsigned long int wc = 0;
    unsigned long int lc = 0;

    while (true){
        
        char c = fgetc(stdin);
        
        // $ used to the input text
        if (c == '$') break; 
        
        ++bc;

        if(c == ' ' || c == '.') {
           ++wc;
        }else if (c == '\n'){
          ++lc;
        }
    }

    fprintf(stdout, "number of bytes %lu, words: %lu lines:%lu\n", bc, wc, lc);

    return;
}


void is_substring(){
  
  char str[100];
  char substr[100];

  fprintf(stdout, "enter the string \n");
  fgets(str, sizeof(str), stdin);
  fprintf(stdout, "enter the substring\n");
  fgets(substr, sizeof(substr), stdin);

  fprintf(stdout, "strings entered, str: %s substr: %s\n",str,substr);
  
  // strstr search complete word and not partial word
  char *pos = strstr(str, substr);
  
  if(pos){
    fprintf(stdout, "yes substring present at pos %ld\n", pos - str);  
  }else{
    fprintf(stdout, "No not a substring\n");
  }

  return;
}



int main(int argc, char **argv) {

    //number_of_bytes();
    is_substring();
    return 0;
}

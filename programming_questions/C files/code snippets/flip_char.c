#include<string.h>
#include<stdio.h>
#include<stdlib.h>


void flip_char_in_string(char s[]){
    printf("%s\n",s);
    int i = 0;
    while (s[i] != '\0'){
        if (s[i] >= 'a' && s[i] < 'z'){
            s[i] = s[i] - 'a' + 'A';
        }else{
            s[i] = s[i] - 'A' +'a';
        }
        printf("%c",s[i]);
        i++;
    }

    return;
}

#define DELIMITER " \t"
#define TOKENS 6

void count_occurence_of_word(char *s1, char *word){

    char **words = (char **)malloc( TOKENS * sizeof(char *));
    int buff_size = TOKENS;
    char *token;
    int position = 0;
    token = strtok(s1, DELIMITER);
    int number_of_times = 0;

    while (token)
    {
        words[position] = token;
        position++;

        if (position >= buff_size){
            buff_size += TOKENS;
            words = realloc(words, (buff_size * sizeof(char *)));
        }
        token = strtok(NULL, DELIMITER);
    }

    for(int i=0;i<position;i++){
        printf("word: %s\n",words[i]);
        if (strcmp(words[i], word) == 0){
            number_of_times++;
        }
    }
    printf("word: %s occured %d times\n", word, number_of_times);

}





int main(){

    char s[] = "asjdhfKJNKDAdfn";
    //flip_char_in_string(s);

    // char *s1 = "hello world this is me" if passed this away, will lead to segmentation fault bcz *s1 stored in read only memory
    char s1[] = "hello world this is me me me me me";
    char *word = "me";
    count_occurence_of_word(s1, word);


    return 0;
}
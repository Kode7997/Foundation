#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFFER 1024

/*
shell has:
 - prompt
 - read string
 - take commands and input stirngs
 - terminate
*/

char* read_input_line() {

    int c;
    int position;
    int buf_size = BUFFER;
    char *buffer = (char *)malloc(BUFFER * sizeof(char));
    
    if(!buffer){
        fprintf(stderr, "kshl: failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        c = getchar();

        if (c == EOF || c == '\n'){
            buffer[position] = '\0';
            return buffer;
        }else{
            buffer[position] = c;
        }

        position++;

        if (position >= BUFFER){
            buf_size += BUFFER;
            buffer = realloc(buffer, buf_size);

            if(!buffer){
                fprintf(stderr, "Failed to allocate memory\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}


char *read_line_getline(){
    char *line = NULL;

    ssize_t buffer_size = 0;

    while(getline(&line, &buffer_size, stdin) ==  -1){
        if(feof(stdin)){
            exit(EXIT_FAILURE);
        }else{
            perror("failed to take input\n");
            exit(EXIT_FAILURE);
        }
    }
    return line;
}

#define TOK_BUFFER 64
#define DELIMITER " \t\b\n\a"

char** get_tokens_from_line(char *line){
    
    int bufsize = TOK_BUFFER, position = 0;
    char **tokens = (char **)malloc(sizeof(char *) * TOK_BUFFER);
    char *token;

    if(!tokens){
        perror("failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, DELIMITER);
    while (token)
    {
        tokens[position] = token;
        position++;

        if (position >= bufsize){
            bufsize += TOK_BUFFER;
            tokens = realloc(tokens, (bufsize * sizeof(char *)));
            if(!tokens){
                perror("memory not allocated\n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, DELIMITER);    
    }
    tokens[position] = NULL;
    return tokens;
}

void kshl_loop(){

    int status=0;
    char *read_line;
    char **args;
     
    do {
        printf("myshell> ");
        //read_line = read_input_line();
        read_line = read_line_getline();
        args = get_tokens_from_line(read_line);
        break;
        // split_input_string()
        // execute_input_command()
        // terminate()
    }while(status);
    
}


int main(){

    kshl_loop();
    return EXIT_SUCCESS;
}
#include <string.h>
#include <stdio.h>

int main (void){
    char *sep;
    char prompt[1080], input[1080];
    
    strcpy(prompt, "[Welcome to Shell]: ");
    
    while(1){
        printf("%s", prompt);
        gets(input);
        sep = strtok(input, " ");
        
        if (sep != NULL && strcasecmp(sep, "set") == 0)
        {
            sep = strtok(NULL, " ");
            
            if (sep != NULL && strcasecmp(sep, "prompt") == 0)
            {
                sep = strtok(NULL, "");
              
                if (sep != NULL)
                {
                    strcpy(prompt, sep);
                    strcat(prompt, " ");
                }
                else
                {
                    printf("Error: correct syntax: set prompt PROMPT");
                }
            }
        }
        
        
        else if (strcasecmp("quit", input) == 0)
        {
            return 0;
            
        }
        else
        {
            system(input);
        }
    }
}

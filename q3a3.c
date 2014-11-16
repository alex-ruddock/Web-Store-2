#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENGLISH
// #define FRENCH

typedef struct node
{
    char* word;
    struct node *next;
} node;

void add(node *head, char *input)
{
    node *newNode;
    newNode = (node*) malloc(sizeof(node));
    newNode->word = strdup(input);
    newNode->next = NULL;
    
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    
    temp->next = newNode;
}


int main()
{

#ifdef ENGLISH

    printf("Welcome to the infinite string storage program.\n");

#else

    printf("Bienvenue dans le programme de stockage de chaÓne infinie.\n");

#endif
    
    node* head;
    head = (node*) malloc(sizeof(node));
    head->word = "";
    head->next = NULL;
    char *token;
    
    while(1)
    {
        char word[1080];

#ifdef ENGLISH

        printf("Please input a single word.\n");
        gets(word);
        token = strtok(word, " \r\t\n");

#else
        
        printf("Veuillez saisir un seul mot.\n");
        gets(word);
        token = strtok(word, " \r\t\n");

#endif
        if(strcmp(token, "***END***")==0)
        {
            break;
        }
        
        add(head, token);
        
    }
    
    node *parse = head->next;
    while(parse != NULL)
    {
        printf("%s\n", parse->word);
        parse = parse->next;
    }
}


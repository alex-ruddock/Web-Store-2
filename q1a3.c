#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

char experiment[1080]={'\0'};

char name[1080]={'\0'};

int buff=0;

double parseData(){
    
    double total = 0, amntData = 0, avg;
    int commas = 0, temp = 0, i = 0;
    
    for(i=0; i<1080; i++)
    {
        if (experiment[i] == '\0')
        {
            total = total+temp;
            temp = 0;
            amntData++;
            avg = total/amntData;
            return (avg);
        }
        
        if (experiment[i] == ',' && commas == 0)
            commas++; //increment field value
        
        else if (experiment[i] == ',' && commas != 0)
        {
            total=total+temp;
            temp=0;
            amntData++;
        }
        
        if (isdigit(experiment[i]) && commas != 0)
        {
            while(isdigit(experiment[i]))
            {
                temp=(temp*10)+(experiment[i]-48);
                i++;             }
            i--;
        }
       
        if (isalpha(experiment[i]) && commas == 0){
            while(isalpha(experiment[i])){
                name[buff]=experiment[i];
                buff++;
                i++;
            }
            i--;
        }
        if (experiment[i] == '\'')
        {
            name[buff] = '\'';
            buff++;
        }
    }
}

void main(int argc, char *argv[])
{
    char *filename=argv[1];
    int i=0;
    if (filename=='\0')
        printf("Please enter a valid file name.\n");
    else
    {
        int j=1;
        while(filename!=NULL || filename != '\0')
        {
            FILE *fp = NULL;
            
            if (access(filename, F_OK) != -1)
            {
                (fp = fopen(filename, "rt"));
                while(!feof(fp))
                {
                    fgets(experiment, 1080, fp);
                    if(feof(fp)) break;
                    printf("%s %.2f\n", name, (ceil(parseData()*100)/100));
                    for(i=0; i<buff; i++){name[i]='\0';}
                    buff=0;
                }
                fclose(fp);
            }
            
            else
            {
                printf("There was an error with file: %d.\n", j);
                fclose(fp);
            }
            j++;
            filename=argv[j];
        }
    }
}

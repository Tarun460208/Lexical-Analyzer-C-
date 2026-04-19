#include<stdio.h>
#include<string.h>
#include"lexer.h"

int is_letter(char ch)
{
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

int is_digit(char ch)
{
    return(ch >= '0' && ch <= '9');
}

int is_keyword(char *str)
{
    char keywords[8][10] = {"int","float","char","if","else","for","while","return" };

    for(int i = 0;i < 8 ;i++)
    {
        if(strcmp(str, keywords[i]) == 0)
        return 1;
    }
    return 0;
}

void analyze(FILE *fp)
{
    char ch, buffer[30];
    int i = 0;

    while((ch = fgetc(fp)) != EOF)
    {
        if((ch == ' ' || ch == '\n' || ch == '\t'))
        {
            continue;
        }

    // IDENTIFIER / KEYWORD  
    if(is_letter(ch))
    {
        buffer[i++] = ch;
        while (is_letter(ch = fgetc(fp)) || is_digit(ch))
        {
            buffer[i++] = ch;
        }
        buffer[i] = '\0';
        i = 0;
        fseek(fp, -1, SEEK_CUR);

        if(is_keyword(buffer))
        printf("Keyword : %s\n",buffer);
        else
        printf("Indentifier : %s\n",buffer);
    }

    // NUMBER
    else if(is_digit(ch))
    {
        buffer[i++] = ch;
        while (is_digit(ch = fgetc(fp)))
        {
            buffer[i++] = '\0';
        }
        buffer[i] = '\0';
        i = 0; 
        fseek(fp, -1,SEEK_CUR);

        printf("Number : %s\n",buffer);
        
    }

    // OPERATOR
    else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=')
    {
        printf("Operator :%c\n",ch);
    }

    // SYMBOL
    else if (ch == ';' || ch == ',' ||ch == '(' || ch == ')' || ch == '{' || ch == '}')
        {
            printf("Symbol      : %c\n", ch);
        }

        else
        {
            printf("Unknown     : %c\n", ch);
        }
    }
}
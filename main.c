#include<stdio.h>
#include"lexer.h"

int main()
{
    int choice;
    FILE *fp;

    do
    {
        printf("\n*******LEXICAL ANALYZER MENU*******\n");
        printf("1. Analyze input.c file\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                fp = fopen("input.c", "r");
                if (fp == NULL)
                {
                    printf("Error opening file!\n");
                }
                else
                {
                    printf("\n--- Lexical Analysis Output ---\n");
                    analyze(fp);
                    fclose(fp);
                }
                break;

            case 2:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 2);

    return 0;
}
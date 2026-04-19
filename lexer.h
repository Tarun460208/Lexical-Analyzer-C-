#ifndef LEXER_H
#define LEXER_H

#include<stdio.h>
int is_keyword(char *str);
int is_letter(char ch);
int is_digit(char ch);
void analyze(FILE *fp);

#endif
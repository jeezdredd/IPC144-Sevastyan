/*
*****************************************************************************
                        Assignment 1 - Milestone 1
Full Name  : Sevastyan Che
Student ID#: 181071218
Email      : sche5@myseneca.ca
Section    : NCC
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "core.h"

void clearInputBuffer(void) {

    while (getchar() != '\n') {
        ; \
    }
}

void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

char* cus_strcpy(char* str2, const char* str1)
{
    char* tempHolder = str2;
    while ((*str2++ = *str1++) != '\0');
    return tempHolder;
}

int cus_strlen(char* str1)
{
    int length = 0;
    while (*str1 != '\0')
    {
        str1++;
        length++;
    }
    return length;
}

int inputInt(void)
{
    int a = 0;
    char newline = 'x';
    if (newline == '\n')
        return a;
    else {
        do {
            scanf("%d%c", &a, &newline);
            if (newline!='\n')
            {
                clearInputBuffer();
                printf("Error! Input a whole number: ");
            }
        } while (newline != '\n');
        return a;
    }
}

int inputIntPositive(void)
{
    int a = 0;
    do {
        a = inputInt();
        if (a < 0) 
            printf("ERROR! Value must be > 0: ");
    } while (a < 0);
    return a;
}

int inputIntRange(int lower, int upper)
{
    int a = 0;
    do {
        a = inputInt();
        if (a < lower || a > upper)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lower, upper);
        }
    } while (a < lower || a > upper);
    return a;
}

char inputCharOption(const char validChar[])
{
    char a ='a';
    char newline = 'x';
    int i, flag = 0;
    int stringLength = strlen(validChar);
    if (newline == '\n')
        return a;
    else {
        do {
            scanf("%c",&a);
            for (i = 0; i < stringLength; i++)
            {
                if (a == validChar[i])
                    flag = 1;
            }
            if (flag == 0)
            {
                clearInputBuffer();
                printf("ERROR: Character must be one of [%s]: ", validChar);

            }
        } while (flag == 0);
        return a;
    }
}

void inputCString(char* stringPtr, int lower, int upper)
{
    int flag = 0, stringLength = 0;
    char userInput[99];
    do {
        clearInputBuffer();
        scanf("%[^\n]", userInput);
        int i;
        for (i = 0; userInput[i] != '\0'; i++)
        {
            stringLength=i + 1;
        }
        if (lower == upper && stringLength != lower)
        {
            printf("ERROR: String length must be exactly %d chars: ", lower);
            flag = 1;
        }
        else if (stringLength < lower)
        {
            printf("ERROR: String length must be between %d and %d chars: ", lower, upper);
            flag = 1;
        }
        else if (stringLength > upper)
        {
            printf("ERROR: String length must be no more than %d chars: ", upper);
            flag = 1;
        }
        else
        {
            flag = 0;
            cus_strcpy(stringPtr, userInput);
        }
    } while (flag != 0);
    
}

void displayFormattedPhone(char* stringPtr)
{
    int i, length;
    int flag = 0;
    if(stringPtr) length = cus_strlen(stringPtr);
    if (stringPtr == NULL)
    {
        printf("(___)___-____");
    }
    else if (length < 10 || length > 10)
    {
        printf("(___)___-____");
    }
    else
    {
        for (i = 0; i < length; i++)
        {
            if (stringPtr[i] < '0' || stringPtr[i] > '9')
            {
                flag=1;
            }
        }
        if (flag == 0)
        {
            printf("(%c%c%c)%c%c%c-%c%c%c%c", stringPtr[0], stringPtr[1], stringPtr[2], stringPtr[3], stringPtr[4], stringPtr[5], stringPtr[6], stringPtr[7], stringPtr[8], stringPtr[9]);
        }
        else
        {
            printf("(___)___-____");
        }
    }
}
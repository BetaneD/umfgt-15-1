/******************************************************************************

Your Task:

     Write a program that takes a single character as input.
     It should test if the character is already uppercase.
     If it is not, it must convert the character to uppercase.
     Display the final character.


*******************************************************************************/
#include <stdio.h>

int main()
{
    char input;

    printf("please input a letter : ");
    scanf("%c",&input);

    if (input >= 'A' && 'Z' >= input){

        printf("\nthe character is uppercase");

    } else if (input >= 'a' && 'z' >= input){

        printf("\nthe character as an upper case character is %c",input - 32);

    }else {
        printf("\nERROR TRY AGAIN\n");
    }


    return 0;
}
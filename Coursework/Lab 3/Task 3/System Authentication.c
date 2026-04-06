/******************************************************************************

Your Task:

     Write a program that picks a random number between 1 and 100.
     It then prompts the user to guess the number.
     If the guess is correct, print a congratulatory message.
     Otherwise, tell the user if their guess was too high or too low.
     The user has a maximum of 3 guesses.


*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int password = rand() % 101;
    int attempt;

    printf("%d\n", password);


    for (int i = 0 ; i < 3  ; i++){

        printf("please input the password : ");
        scanf("%d",&attempt);

        if (password == attempt){

            printf("\ncongratulations you have input the password :D");
            break;
        }else if(password < attempt){

            printf("input too high :( , please try again\n\n");
        }else if (password > attempt){

            printf("input too low :( , please try again\n\n");
        }
    }

    (password == attempt)? printf(" "):printf("you have reched the maximum number of attempts");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

typedef struct
{
    int iq;
    int time;
    int startage;
    int age;
    char name[100];
}
chessplayer;

void Userinput(int *number);
void Experiencecalculate(int *startage, int *age, float *experience, int *hours, int *iq);
void PercentageCalculation(float *exp1, float *exp2, float *percent1, float *percent2);


int main(void)
{
    chessplayer chessplayer1;
    chessplayer chessplayer2;

    //takes input the 
    printf("Welcome to Chess Win Probabilty!");
    sleep(2);
    printf("\nPlease enter first player's name: ");
    sleep(1);
    scanf("%s", chessplayer1.name);
    printf("Please enter second player's name: ");
    scanf("%s", chessplayer2.name);
    printf("Loading...");
    sleep(2);

    if (isdigit(*chessplayer1.name) || isdigit(*chessplayer2.name))
    {
        printf("\nInvalid Inputs");
        return 1;
    }

    

    //First Player Stats
    printf("\n\nPlease Enter Stats for %s..\n", chessplayer1.name);

    printf("IQ: ");
    Userinput(&chessplayer1.iq);

    printf("Age: ");
    Userinput(&chessplayer1.age);

    printf("Age started: ");
    Userinput(&chessplayer1.startage);

    printf("Hours trained per day: ");
    Userinput(&chessplayer1.time);
    
    printf("Loading...");
    sleep(2);

    if (chessplayer1.age < chessplayer1.startage || chessplayer1.time > 24)
    {
        printf("\nInvalid inputs");
        return 1;
    }

     //Second Player Stats
 printf("\n\nPlease Enter Stats for %s..\n", chessplayer2.name);

    printf("IQ: ");
    Userinput(&chessplayer2.iq);

    printf("Age: ");
    Userinput(&chessplayer2.age);

    printf("Age started: ");
    Userinput(&chessplayer2.startage);

    printf("Hours trained per day: ");
    Userinput(&chessplayer2.time);
    
    printf("Loading...");
    sleep(2);

    if (chessplayer2.age < chessplayer2.startage || chessplayer2.time > 24)
    {
        printf("\nInvalid inputs");
        return 1;
    }
    
    printf("  Calculating results...");
    sleep(3);

    float experience1, experience2, finalresult1, finalresult2;
    Experiencecalculate(&chessplayer1.startage, &chessplayer1.age, &experience1, &chessplayer1.time, &chessplayer1.iq);
    Experiencecalculate(&chessplayer2.startage, &chessplayer2.age, &experience2, &chessplayer2.time, &chessplayer2.iq);
    PercentageCalculation(&experience1, &experience2, &finalresult1, &finalresult2);

    printf("\n\n%s's win percentage: %c%.2f.\n", chessplayer1.name, '%', finalresult1);
    printf("%s's win percentage: %c%.2f.\n", chessplayer2.name, '%', finalresult2);
    sleep(5);


    printf("\nThank you for using Chess Win Probability!");
    return 0;
    
    
}

void Experiencecalculate(int *startage, int *age, float *experience, int *hours, int *iq)
{
    *experience = (((age - startage) * 365) * *hours * *iq);
    return;
}

void PercentageCalculation(float *exp1, float *exp2, float *percent1, float *percent2)
{
    if (*exp1 > *exp2)
    {
       *percent2 = ((*exp2 / *exp1) / 2) * 100;
       *percent1 = 100 - *percent2;
    }
    else 
    {
        *percent1 = ((*exp1 / *exp2) / 2) * 100;
        *percent2 = 100 - *percent1; 

    }
}

//takes input of an integer. If not an integer, exits the program.
void Userinput(int *number)
{
    int temp;

    temp = scanf("%d", number);
    if(temp != 1)
    {
    printf("Please input a number..\n");
    exit(1);
    }
}



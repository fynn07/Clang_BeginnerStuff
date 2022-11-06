#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <conio.h>


void balanceFunction(int *startmoney, int *amount);
void betfunction(int *amount, int *bet);
void slotfunction(int *bet, int *amount);
void outofmoney(int *amount, int *startmoney);


int main(void)
{
    int startmoney = 100, balance, bet, loop = 1, temp;
    
    
    printf("Welcome to the Slots!");
    sleep(1);
    printf("\n\nCurrent Balance: %d$\n", startmoney);
    balanceFunction(&startmoney, &balance);
    printf("\n\nLoading...");
    sleep(2);
    betfunction(&balance, &bet);
    sleep(2);
    slotfunction(&bet, &balance);


    while (loop != 3)
    {
        printf("\nPress 1 to play again. Press 3 to exit.\n");
        scanf("%d", &loop);
        if (loop == 1)
        {
            system("CLS");
            betfunction(&balance, &bet);
            sleep(2);
            slotfunction(&bet, &balance);
        }
        else if (loop == 3)
        {
            printf("Thank you for playing!");
            sleep(1);
            exit(1);
        }
        else 
        {
            printf("Please Enter either 1 or 3.\n");
        }

        if (balance < 3)
        {
            outofmoney(&balance, &startmoney);
        }
    }


}

void balanceFunction(int *startmoney, int *amount)
{
    int temp, x = 1;
    while (x = 1)
    {
    printf("How much would you like to deposit: ");
    temp = scanf("%d", amount);
   
    
    if (temp != 1)
    {
        printf("Please enter a number\n");
        break;
    }
    else 
    {
        if (*amount > 0)
        {
            if (*amount > *startmoney)
            {
                printf("Not enough money for deposit.\n\n");
            }
            else
            {
                *startmoney -= *amount;
                printf("\n%d$ has been deducted from your balance. \nYour account balance is %d$.\n", *amount, *startmoney);
                printf("Your game balance is %d$.", *amount);
                return;
            }
        }
        else if (*amount <= 0)
        {
            printf("Amount must be greater than 0$.\n");
        }
    }
    }
    
}

void betfunction(int *amount, int *bet)
{
    int temp, x = 1;
    while (x = 1)
    {
        printf("\n%d$ Remaining.", *amount);
        printf("\nHow much do you want to bet per line : ");
       
        temp = scanf("%d", bet);
        
        if (temp != 1)
        {
            printf("Please enter a number.");
            exit(1);
        }
        else
        {
            if (*bet > 0)
            {
                if ((*bet * 3) <= *amount)
                {
                    printf("\nBetting %d$ on three lines...\n\n");
                    return;
                }
                else 
                {
                    printf("Not enough balance for bet.\n");
                }
            }
            else 
            {
                printf("Bet must be greater than 0.\n");
            }
        }

    }
}

void slotfunction(int *bet, int *amount)
{
    int multiplier = 1;
    int line1[3], line2[3], line3[3];



    for (int i = 0; i < 3; i++)
    {
        srand(time(NULL));
        line1[i] = (rand() % ((3 + 1) - 1) + 1);
        line2[i] = (rand() % ((3 + 1) - 1) + 1);
        line3[i] = (rand() % ((3 + 1) - 1) + 1);
    }

    printf("|%d | %d | %d |\n", line1[1], line1[2], line1[3]);
    printf("|%d | %d | %d |\n", line2[1], line2[2], line2[3]);
    printf("|%d | %d | %d |\n\n", line3[1], line3[2], line3[3]);

    if (line1[1] == line1[2] && line1[1] == line1[3])
    {
        printf("Won on line 1!\n");
        multiplier++;
    }

    if (line2[1] == line2[2] && line2[1] == line2[3])
    {
        printf("Won on line 2!\n");
        multiplier++;
    }

    if (line3[1] == line3[2] && line3[1] == line3[3])
    {
        printf("Won on line 3!\n");
        multiplier++;
    }

    if (multiplier > 1)
    {
    *amount -= *bet;
    *bet *= multiplier;
    *amount += *bet;
    printf("Total Winnings: %d$!\n", *bet);
    printf("New Balance = %d$\n", *amount);
    }
    else
    {
        *amount -= (*bet * 3);
        printf("New Balance = %d!\n", *amount);
    }
}

void outofmoney(int *amount, int *startmoney)
{
    int response, newdeposit;
    while (true)
    {
        printf("You are out of funds. Press 1 to deposit. 2 to exit slots.\n");
        scanf("%d", &response);

        if (response == 1)
        {
            while (true)
            {
                printf("You have %d$. Enter amount to deposit: ", *startmoney);
                scanf("%d", &newdeposit);

                if (newdeposit <= *startmoney)
                {
                *startmoney -= newdeposit;
                *amount += newdeposit;
                printf("Your new balance is %d.", *amount);
                return;
                }
                else 
                {
                    printf("not enough funds.\n");
                }
            }

        }

        else if (response == 2)
        {
            printf("Thank you for Playing!");
            sleep(1);
            exit(1);
        }
        else 
        {
            printf("Please enter either 1 or 2.\n");
        }
    }
        

    
}

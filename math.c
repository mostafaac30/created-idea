#include <stdio.h>
#include <cs50.h>
#include <time.h>   //fr number numbers
#include <stdlib.h> //for random numbers
#include <unistd.h> // notice this! you need it to sleep 
#include <string.h> //strcmp(timer, "yes") == 0

int main(void)
{

    long n;

    string timer1 =get_string("Do you want a timer? (yes or no): ");
    int timer2=0;
    if(strcmp(timer1, "yes") == 0)
    {
        timer2=1;
    }
    else if(strcmp(timer1, "Yes") == 0) 
    {
        timer2=1;
    }
    do
    {
        n = get_long("How many questions do you want? : ");    //number of questions
    }
    while (n <= 0);
    
    srand(time(NULL));   // Initialization, should only be called once.

    int x = 0;
    int y = 0;
    int s = 0;  //score var.

    for (int i = 0; i < n; i++) //iterate questions "n" times

    {
        x = rand() % 100;;  // Returns a pseudo-random integer between 0 and RAND_MAX.
        y = rand() % 100;;  //in loop to generate a new random nomber evry question.
        int z = x + y;

        printf("%i + %i ", x, y);
        int timer=0;    //to compare it with (for loop) in the next line.
        
        long r; //declaration is here like (do..while loop) ..to be in the general scope.
        if(timer2==1)
        {
            for(int t=0; t<timer; timer++)  //this loop makes user input limited by time in (sleep 5 )in line 44, and the input order will be skiped after some times.
            {
                r = get_long("write the answer: ");
            }
        sleep(5); // format is sleep(x); where x is # of seconds.
        }

        else
        {
            r = get_long("write the answer: ");
        }

 
        if (r == z)
        {
            printf("good answer\n");
            s++;
            printf("your score became %i\n", s);
        }
        else 
        {
            s--;
            printf("Try again\n");
            sleep(1);
            printf("The correct answer is %i\n", z);
            sleep(2);
            
        }

    }
    printf("your total score is %i\n", s);
}

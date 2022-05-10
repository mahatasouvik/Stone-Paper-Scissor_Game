#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int stonepaperscissor(char you[],char computer[]){
    if(strcmp(you,computer)==0)
    {
        return 0;
    }
    if(strcmp(you,"paper")==0 && strcmp(computer,"stone")==0)
    {
        return 1;
    }
    else if(strcmp(you,"stone")==0 && strcmp(computer,"paper")==0)
    {
        return -1;
    }
    if(strcmp(you,"scissor")==0 && strcmp(computer,"paper")==0)
    {
        return 1;
    }
    else if(strcmp(you,"paper")==0 && strcmp(computer,"scissor")==0)
    {
        return -1;
    }
    if(strcmp(you,"stone")==0 && strcmp(computer,"scissor")==0)
    {
        return 1;
    }
    else if(strcmp(you,"scissor")==0 && strcmp(computer,"stone")==0)
    {
        return -1;
    }
}
int main(){
    char you[20],*computer;
    int result,point,yp,cp,i,number;
    printf("Enter The Number Of Point Of The Game : ");
    scanf("%d",&point);
    for(i=0,yp=0,cp=0;(yp<point && cp<point);i++)
    {
        printf("\nEnter \"stone\" or \"paper\" or \"scissor\": ");
        scanf("%s",you);
        srand(time(0));
        number = rand()%100 + 1;
        if(number>0 && number<33)
        {
            computer="stone";
        }
        else if(number>33 && number<66)
        {
            computer="paper";
        }
        else
        {
            computer="scissor";
        }
        strlwr(you);
        if((strcmp(you,"stone")==0) || (strcmp(you,"paper")==0) || (strcmp(you,"scissor")==0))
        {
            result=stonepaperscissor(you,computer);
            if(result==0)
            {
            printf("Draw!");
            printf("\nYour Point Is %d and Computer Point Is %d.",yp,cp);
            printf("\nYou Chose %s and Computer Chose %s.\n", you,computer);
            }
            else if(result==1)
            {
                yp++;
                printf("You win!");
                printf("\nYour Point Is %d and Computer Point Is %d.",yp,cp);
                printf("\nYou Chose %s and Computer Chose %s.\n", you,computer);
            }
            else
            {
                cp++;
                printf("You Lose!");
                printf("\nYour Point Is %d and Computer Point Is %d.",yp,cp);
                printf("\nYou Chose %s and Computer Chose %s.\n", you,computer);
            }
        }
        else
        {
            printf("You Have Entered Wrong Input!\n");
        }
    }
    if(yp==point)
    {
        printf("\nHurray! You Win The Contest\n");
    }
    else
    {
        printf("\nHurray! Computer Win The Contest\n");
    }
    getch();
    return 0;
}
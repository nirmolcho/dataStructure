//
// Sean Lavi 206634529
// Nir Molcho 315126912
//
#include "main.h"
#include <time.h>       // for clock_t, clock(), CLOCKS_PER_SEC

int main(){

    //start
    printf("Enter the size of array: \n");
    scanf("%d",&num);

    //random array and number
    srand(time(NULL));
    int randArray[num],i;
    int randomNum;
    for(i=0;i<num;i++)
        randArray[i]=(rand()%100)+1;
    randomNum = (rand() % 300) + 1;

    printf("the given array is: \n");

    for(i=0;i<num;i++)
    {
        printf("%d ",randArray[i]);
        if (i %20 == 0)
            printf("\n");
    }
    printf("\nThe Random Number is: %d\n", randomNum);


    // the arrays of the numbers
    int *sumOf3, *SumOf3, *sum3;

    // timestamps
    double time_spent1 = 0.0;
    double time_spent2 = 0.0;
    double time_spent3 = 0.0;



    // check for On^3 run time
    clock_t begin = clock();
    if (SumOfTree1(randArray,randomNum) == 0)
        printf("\nN^3:       No math try again...");
    else {
        printf("\n");
        sumOf3 = SumOfTree1(randArray,randomNum);
        for (int j = 0; j < 3; ++j)
            printf("N^3: the numbers are: %d\n",sumOf3[j]);
        printf("the amount of times the program ran is: %d\n", sumOf3[3]);
    }
    clock_t end = clock();
    time_spent1 += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The total time is: %f\n", time_spent1);



    // check for On^2log(n) run time
    begin= clock();
    if (SumOfTree2(randArray,randomNum) == 0)
        printf("\nN^2log(n): No math try again...");
    else
    {
        printf("\n");
        SumOf3 = SumOfTree2(randArray,randomNum);
        for (int j = 0; j < 3; ++j)
            printf("N^2log(n): the numbers are: %d\n",SumOf3[j]);
        printf("the amount of times the program ran is: %d\n", SumOf3[3]);
    }
    end= clock();
    time_spent2 += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The total time is: %f\n", time_spent2);



    // check for On^2 run time
    begin= clock();
    if (SumOfTree3(randArray,randomNum) == 0)
        printf("\nN^2:       No math try again...");
    else
    {
        printf("\n");
        sum3 = SumOfTree3(randArray,randomNum);
        for (int j = 0; j < 3; ++j)
            printf("N^2: the numbers are: %d\n",sum3[j]);
        printf("the amount of times the program ran is: %d\n", sum3[3]);
    }
    end= clock();
    time_spent3 += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The total time is: %f\n", time_spent3);

};

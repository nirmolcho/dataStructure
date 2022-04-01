//
// Sean Lavi 206634529
// Nir Molcho 315126912
//

#include "main.h"


int * SumOfTree1(const int V[num], int s)
{
    int* sumOfnum;// an array for you to use
    sumOfnum = (int*) calloc(4,sizeof(int));

    int counter = 0;
    int summer = 0;
    for (int i = 0; i < num-2; ++i)
    {
        for (int j = i+1; j < num-1; ++j)
        {
            for (int k = j+1; k < num; ++k)
            {
                if(V[i]+V[j]+V[k] == s)
                {
                    counter++;
                    sumOfnum[0] = V[i];
                    sumOfnum[1] = V[j];
                    sumOfnum[2] = V[k];
                    sumOfnum[3] = counter;
                    return sumOfnum;
                }
            }
        }
    }
    for (int l = 0; l < 3; ++l) {
        if (sumOfnum[l] == 0)
            summer++;
    }
    if (summer == 3)
        return 0;
    return sumOfnum;
}

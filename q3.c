//
// Sean Lavi 206634529
// Nir Molcho 315126912
//
#include "main.h"



int *SumOfTree3(int V[num], int s)
{
    int i, key, j;
    int counter=0;
    int summer = 0;
    int k, sum, search;
    int* sumOfnum;// an array for you to use
    sumOfnum = (int*) calloc(4,sizeof(int));
    //***********************sorting the array O(n^2)************
    for (i = 1; i < num; i++) {
        key = V[i];
        j = i - 1;
        while (j >= 0 && V[j] > key) {
            V[j + 1] = V[j];
            j = j - 1;
        }
        V[j + 1] = key;
    }
    //***********************searching for a subset that equals S in array O(n^2)************
    for (int l = num-1; l > 0 ; --l){
        for (k = 0; k < num; ++k){
            if (V[k]+V[l]<s)
            {
                counter++;
                sum = V[k]+V[l];
                search = s - sum;
                //*********************** O(n)************
                for (int m = k+1; m <= l-1 ; ++m) {
                    counter++;
                    if (V[m]==search) {
                        counter++;
                        sumOfnum[0] = V[k];
                        sumOfnum[1] = V[l];
                        sumOfnum[2] = search;
                        sumOfnum[3] = counter;
                        return sumOfnum;
                    }
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
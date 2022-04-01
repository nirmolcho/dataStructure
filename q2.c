//
// Sean Lavi 206634529
// Nir Molcho 315126912
//


#include "main.h"
int * SumOfTree2(int V[num], int s)
{
    //***********************sorting the array O(n^2)************
    int i, key, j;
    int counter = 0;
    int summer = 0;
    int k, sum, search;
    int* sumOfnum;// an array for you to use
    sumOfnum = (int*) calloc(4,sizeof(int));
    for (i = 1; i < num; i++) {
        key = V[i];
        j = i - 1;
        while (j >= 0 && V[j] > key) {
            V[j + 1] = V[j];
            j = j - 1;
        }
        V[j + 1] = key;
    }
    for (int l = num - 1; l > 0; --l) {
        for (k = 0; k < num; ++k) {
            if (V[k] + V[l] < s) {
                counter++;
                sum = V[k] + V[l];
                search = s - sum;
                int first = k + 1;
                int last = l - 1;
                int middle = (first + last) / 2;
                //********NOW the Binary search of the number that is missing*************
                while (first <= last) {
                    counter++;
                    if (V[middle] < search) {
                        first = middle + 1;
                        counter++;
                    }
                    else if (V[middle] == search) {
                        counter++;

                        sumOfnum[0] = V[k];
                        sumOfnum[1] = V[l];
                        sumOfnum[2] = search;
                        sumOfnum[3] = counter;
                        return sumOfnum;
                    } else {
                        counter++;
                        last = middle - 1;
                    }
                    middle = (first + last) / 2;
                }
                //************end of the binary search****************
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


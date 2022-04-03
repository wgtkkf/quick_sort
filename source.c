// reference: https://qiita.com/omu58n/items/7794f097b2c569a469bc

#include <stdio.h>
#define size 10

void show(int *);
void swap(int *, int *);
int partition(int *, int, int);
void qsort(int *, int, int);

int main (void){
    int table[size] = {20, 6, 55, 74, 3, 45, 13, 87, 46, 30}; // 0 to (size-1)
    int i=0,j=0;
    int temp;

    // show before sorting
    show(&table[0]);

    // quick sort
    printf("quick sort start\n");
    qsort(&table[0], 0, size-1);

    // show after sorting
    show(&table[0]);

    return 0;
}

// display
void show(int *num)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(i<size-1)
        {
            printf("%d ", *num);
            num++;
        }else if(i==size-1)
        {
            printf("%d end\n", *num);
        }
    }
}

// exchange
void swap(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int *num, int left, int right)
{
    int i, j, pivot;
    i=left;
    j=right+1;

    pivot = left;

    do{
        do{i++;} while(num[i] < num[pivot]);
        do{j--;} while(num[pivot] < num[j]);

        if(i<j){
            swap(&num[i], &num[j]);
            }
    } while (i < j);

    swap(&num[pivot], &num[j]);

    return j;
}

// quick sort
void qsort(int *num, int left, int right)
{
    int pivot;

    if(left >=right){
        return;
    }
    
    if(left < right)
    {
        pivot = partition(num, left, right);
        qsort(num, left, pivot-1);
        qsort(num, pivot+1, right);
    }
    //show(num);
}
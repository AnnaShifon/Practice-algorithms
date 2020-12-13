#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void qs(int *s_arr, int first, int last)
{
    if (first < last)
    {
        int left = first, right = last, middle = s_arr[(left + right) / 2];
        do
        {
            while (s_arr[left] < middle) left++;
            while (s_arr[right] > middle) right--;
            if (left <= right)
            {
                int tmp = s_arr[left];
                s_arr[left] = s_arr[right];
                s_arr[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        qs(s_arr, first, right);
        qs(s_arr, left, last);
    }
}

main(int argc, char * argv[])
{
    FILE *f;
    f = fopen(argv[1], "r");
    int n;
    fscanf(f, "%d", &n);
    int *q = malloc(n*sizeof(int));
    for(int i = 0; i < n; i++)
    {
        fscanf(f, "%d", &q[i]);
    }

    clock_t start=clock();

    qs(q,0,n-1);

    clock_t stop=clock();

    printf("Time:%lf",(double)(stop-start)/CLOCKS_PER_SEC);

    printf("\n");
    for(int i = 0;i<n;i++)
    {
        printf("%d\n",q[i]);
    }
    fclose(f);
    free(q);
    return 0;
}

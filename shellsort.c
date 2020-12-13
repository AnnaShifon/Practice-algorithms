#include <stdio.h>
#include<stdlib.h>
#include <time.h>
int shell(int *A, int length)
{
int step=length;
step=step/2;
 while (step>0)
 {
  for (int i=0; i<length-step; i++)
 {
  int j=i;
  while(j>=0 && A[j]>A[j+d])
{
 int t=A[j];
 A[j]=A[j+step];
 A[j+d]=t;
 j--;
}
}
 step=step/2;
}
for (int i =0; i<length-1; i ++)
return A[i];
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

shell(*q, n-1);

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

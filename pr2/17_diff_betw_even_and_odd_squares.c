#include <stdio.h>
#include <math.h>
int main()
{
int n, i;
double a, c, d, e, sum=0;
(void)scanf ("%d", &n);
for (i=0; i<n; i++)
{
(void)scanf ("%lf", &a);
c=pow((-1), (double)(i+1));
d=pow(a,2);
e=c*d;
sum=sum+e;
}
printf ("%lf\n", sum);
return 0;
} 

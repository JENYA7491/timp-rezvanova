#include <stdio.h>
int main()
{
int n, i;
int a, b=0;
(void)scanf ("%d", &n);
for (i=0; i<n; i++)
{
(void)scanf ("%d", &a);
if (a<0)
{
b++;
}
}
printf ("%d", b);
return 0;
}

#include <stdio.h>
#include <omp.h>
int main()
{
int prime[1000], i, j, n;

printf("\n In order to find prime numbers from 1 to n, enter the value of n:");
scanf("%d", &n);

for(i = 1; i <= n; i++) {
prime[i] = 1;
}
prime[1] = 0;

for(i = 2; i * i <= n; i++) {
#pragma omp parallel for
for(j = i * i; j <= n; j = j + i) {
if(prime[j] == 1) {
prime[j] = 0;
}
}
}

printf("\n Prime numbers from 1 to %d are\n", n);
for(i = 2; i <= n; i++) {
if(prime[i] == 1) {
printf("%d\t", i);
}
}
double start, end;
start = omp_get_wtime();
prime[i];
end = omp_get_wtime();
printf("Sequential Time: %f seconds\n",end-start);
start = omp_get_wtime();
prime[i];
end = omp_get_wtime();
printf("Parallel Time: %f seconds\n",end-start);
printf("\n");
}

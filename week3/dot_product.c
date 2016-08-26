#include <stdio.h>
#include <malloc.h>

void sort(long int* initial, size_t length){
	size_t i, j, min;
	long int tmp;
	for ( i = 0; i < length - 1; ++i){
		min = i;
		for ( j = i + 1; j < length; ++j){
			if ( initial[j] < initial[min] ){
				min = j;
			}
		}
	tmp = initial[i];
	initial[i] = initial[min];
	initial[min] = tmp;
	}	
}

int main(void){
	size_t n, i;
	long int sum = 0;
	long int* a = calloc( n, sizeof( long int ) );
	long int* b = calloc( n, sizeof( long int ) );

	scanf("%lu", &n);

	for ( i = 0; i < n; ++i)
		scanf("%ld", &a[i]);

	for ( i = 0; i < n; ++i)
		scanf("%ld", &b[i]);

	sort( a, n );
	sort( b, n );
		
	for ( i = 0; i < n; ++i){
		sum += a[i]*b[n-i-1];
	}

	printf("%ld\n", sum);
	return 0;
}

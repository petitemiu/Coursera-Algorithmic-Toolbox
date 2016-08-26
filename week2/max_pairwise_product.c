#include <stdio.h>
#include <malloc.h>

long max_pairwise(long* arr, size_t length){
	long result = 0, temp;
	size_t i, j;
	for ( i = 0; i < length; ++i){
		for ( j = i + 1; j < length; ++j){ 
			temp = arr[i]*arr[j];
			if (temp > result)
				result = temp;
		}
	} 
	return result;
}

long max_pairwise_fast( long* arr, size_t length){
	int max_index1 = -1, max_index2 = -1;
	size_t i;
	
	for ( i = 0; i < length; ++i){
		if ( (max_index1 == -1) || (arr[i] > arr[max_index1]) ){
			max_index1 = i;
		}
	}

	for ( i = 0; i < length; ++i){
		if ( (i != max_index1) && ( (max_index2 == -1) || (arr[i] > arr[max_index2]) ) ){
			max_index2 = i;
		}
	}
	return arr[max_index1] * arr[max_index2];
}

int main(void){
	size_t length, i;
	long* arr, res1, res2;
	scanf("%lu", &length);
	arr = (long*)malloc(length*sizeof(long));
	
	for ( i = 0; i < length; ++i){
		scanf("%ld", &arr[i]);
	}

	res1 = max_pairwise(arr, length);
	res2 = max_pairwise_fast(arr, length);

	free(arr);
	printf("%ld", res2);

	return 0;
}

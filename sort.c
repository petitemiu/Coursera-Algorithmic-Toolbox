#include <stdio.h>
#include <stdlib.h>

typedef struct part_result{
	 int ml;
	 int mr;
} part_result;

part_result partition(long long int* arr,  int left, int right){
	part_result res;
	 int i, 
		j = left, 
		length = right - left + 1;
	srand(arr[left]);
	int pivot = left + rand() % length;
	long long int tmp = arr[left];
	arr[left] = arr[pivot];
	arr[pivot] = tmp;

	for ( i = left + 1; i <= right; ++i){
		if ( arr[i] <= arr[left] ){
			++j;
			if ( i > j ){
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;	
			}
		}
	}
	tmp = arr[left];
	arr[left] = arr[j];
	arr[j] = tmp;
	res.mr = j;
	
	i = left;
	while(j > left && j > i){
		while( j > left && arr[j-1] == arr[j] ){
			--j;
		}
		if(j > i && j > left){
			if(arr[i] == arr[j]){
				--j;
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
		++i;
	}
	res.ml = j;
	return res;
}

void quick_sort(long long int* arr,  int left, int right){
	if(left>=right)
		return;
	part_result res = partition(arr, left, right);
	
	quick_sort(arr, left, res.ml-1);
	quick_sort(arr, res.mr+1, right);
}

void selection_sort(long int* initial, size_t length){
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

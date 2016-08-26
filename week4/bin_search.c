#include <stdio.h>

int binary_search(size_t* arr, size_t low, size_t high, size_t key){
	int result;

	if (high < low || key > arr[high] || key < arr[low]){
		return -1;
	}

	size_t mid = low + ((high - low)/2);
	if (arr[mid] == key){
		result =  mid;
	}
	else if (arr[mid] > key){
		result = binary_search(arr, low, mid - 1, key);
	}
	else{
		result = binary_search(arr, mid + 1, high, key);
	}
	return result;
}

int main(void){
	size_t input_length, i, keys_length;

	scanf("%lu", &input_length);
	size_t input[input_length];

	for ( i = 0; i < input_length; ++i){
		scanf("%lu", &input[i]);
	}

	scanf("%lu", &keys_length);
	size_t keys[keys_length];

	for ( i = 0; i < keys_length; ++i){
		scanf("%lu", &keys[i]);
	}
	
	for ( i = 0; i < keys_length; ++i){
		int result = binary_search(input, 0, input_length - 1, keys[i]);
		printf("%d ", result);
	}
	return 0;
}

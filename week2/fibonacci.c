#include <stdio.h>
#include <malloc.h>

size_t fibonacci(size_t index){
	size_t i, result;
	size_t* numbers = calloc(index + 1, sizeof(size_t));
	
	numbers[0] = 0;
	numbers[1] = 1;
	for ( i = 2; i <= index; ++i){
		numbers[i] = numbers[i-1] + numbers[i-2];
	}
	result = numbers[index];
	free(numbers);
	return result;
}

int main(void){
	size_t index;
	scanf("%lu", &index);
	printf("%lu", fibonacci(index));
	return 0;
}

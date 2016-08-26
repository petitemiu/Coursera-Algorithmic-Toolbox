#include <stdio.h>

size_t fibonacci(size_t index){
	size_t first=0, second=1, result=0;
	if ( index==0 )
		return first;
	else if ( index==1 )
		return second;
	else 
		return fibonacci(index-1) + fibonacci(index-2);
}

int main(void){
	size_t index;
	scanf("%lu", &index);
	printf("%lu", fibonacci(index));
	return 0;
}

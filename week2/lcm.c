#include <stdio.h>

size_t gcd(size_t first, size_t second){
	size_t greater, less, temp;
	if ( first > second ){
		greater = first;
		less = second;
	}
	else if ( second > first ){
		greater = second;
		less = first;
	}
	else 
		return first;
	
	while ( less != 0){
		temp = less;
		less = greater % less;
		greater = temp;
	}
	return greater;
}

size_t lcm(size_t first, size_t second){
	size_t mult = first * second;
	size_t div = gcd(first, second);
	return mult/div;
}

int main(void){
	size_t a, b;
	scanf("%lu %lu", &a, &b);
	printf("%lu", lcm(a, b));
	return 0;
}

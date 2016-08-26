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

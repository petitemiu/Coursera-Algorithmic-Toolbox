#include <stdio.h>

size_t count(size_t amount){
	size_t res10, res5;
	res10 = amount / 10;
	amount %= 10;
	res5 = amount / 5;
	amount %= 5;
	return amount + res5 + res10;
}

int main(void){
	size_t given, changes;
	scanf("%lu", &given);
	changes = count(given);
	printf("%lu\n", changes);
	return 0;
}

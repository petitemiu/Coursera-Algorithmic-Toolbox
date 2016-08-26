#include <stdio.h>
#include <malloc.h>

typedef struct{
	int val;
	int prev;
} value;

int min(int a, int b){
	if( a > b )
		return b;
	return a;
}

value min_comb(int n){
	value memo[n+1];
	size_t i;
	memo[1].val = 0;
	memo[1].prev = -1;
	for( i = 2; i <= n; ++i){
		memo[i].val = 1 + memo[i-1].val;
		memo[i].prev = i-1;
		if( i%2 == 0 ){
			memo[i].val = min(memo[i].val, 1 + memo[i/2].val);
				if(memo[i].val == 1 + memo[i/2].val){
					memo[i].prev = i/2;
				}
		}
		if( i%3 == 0 ){
			memo[i].val = min(memo[i].val, 1 + memo[i/3].val);
				if(memo[i].val == 1 + memo[i/3].val){
					memo[i].prev = i/3;
			}
		}	
	}
	int count = memo[n].val;
	printf("%d\n", count);

	i = n;
	size_t sub = 1;
	int* tmp = calloc(count, sizeof(int));
	while( i > 1 ){
		i = memo[i].prev;
		tmp[count-sub] = i;
		++sub;
	}
	for(i = 0; i < count; ++i){
		printf("%d ", tmp[i]);
	}
	printf("%d", n);
	
	return memo[n];
}

int main(void){
	int n;
	size_t i;
	scanf("%d", &n);
	min_comb(n);
	return 0;
}

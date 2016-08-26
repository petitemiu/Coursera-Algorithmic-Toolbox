#include <stdio.h>
#include <malloc.h>

void selection_sort(int* initial, int length){
	int i, j, min;
	int tmp;
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


int knapsack(int weight, int* weights, int count){
	int i, w;
	/*int table[weight+1][count+1];*/
	int (*table)[count+1] = malloc((count+1)*sizeof(int)*(weight+1));
	for( i = 0; i <= count; ++i){
		table[0][i] = 0;
	}
	for( w = 0; w <= weight; ++w){
		table[w][0] = 0;
	}
	for( i = 1; i <= count; ++i){
		for( w = 1; w <= weight; ++w){
			table[w][i] = table[w][i-1];
			if(weights[i-1] <= w){
				int tmp = table[w-weights[i-1]][i-1] + weights[i-1];
				if(table[w][i] < tmp){
					table[w][i] = tmp;
				}
			}
		}
	}
	return table[weight][count];
}

int main(void){
	int W, count, i;
	scanf("%d %d ", &W, &count);//Weight needed, number of bars
	int w[count];//weights of bars
	for( i = 0; i < count; ++i ){
		scanf("%d", &w[i]);
	}
	selection_sort(w, count);
	int gold = knapsack( W, w, count );
	printf("%d", gold);
	return 0;
}

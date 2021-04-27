#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int n = 0;
	scanf("%d", &n);
	unsigned long long int mem[n];
	for (int i = 0; i < n; i++)
		scanf("%llx", &mem[i]);
	unsigned long long int dist = 0;
	scanf("%llx", &dist);
	unsigned long long int mask = 0, result = 0;
	for (int i = 0; i < 25; i++)
		mask = (mask | 1) << 1;
	mask = mask | 1;
	for (int i = 0; i < n; i++) {
		unsigned long long int free_space = mask - (mask & mem[i]) + 1;
		//printf("%llx\n", free_space);
		if (free_space >= dist) {
			result = mem[i] + dist;
			dist = 0;
			break;
		}
		else
			dist -= free_space;
	}
	if (dist == 0)
		printf("%llx\n", result);
	else
		printf("error\n");
	return 0;
	
}
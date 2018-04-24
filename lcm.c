#include <stdio.h>

long populationPrompt();
long scanNumber(long i);
long leastCommonMultiple(long *arr, long population);
long pairMultiple(long x, long y);

int main(void){
printf("This utility calculates the least common multiple of an infinite (theoretically)\namount of positive numbers (values up to 2^31-1)\n");

long population = populationPrompt();
long numbers[population];

for (int i = 0; i < population; i++) {
	numbers[i] = scanNumber(i);
}

long lcm = leastCommonMultiple(numbers, population);
printf("------------------------------------\nThe least common multiple is: %li\n------------------------------------\n", lcm);
getchar();
fputs("Press ENTER to terminate the utility",stdout);
getchar();
}

long populationPrompt(){
		long population = 0;
		while (population <= 0) {
			printf("How many numbers are you\ngoing to find the LCM for? : ");
			scanf( "%li", &population);
		}
		return population;
}

long scanNumber(long i) {
		long x;
		do {
			printf("Give me number %li: ",i+1);
			scanf( "%li", &x);
		} while (x <= 0);
		return x;
}

long leastCommonMultiple(long *arr, long population) {
		for (long i = 1; i < population; i++)
			arr[i] = pairMultiple(arr[i - 1], arr[i]);
		return arr[population - 1];
}

long pairMultiple(long x, long y) {
		long count = 1;
		while (count <= 2147483647) {
			if (count % x == 0 && count % y == 0)
				break;
			count++;
		}
		return count;
}
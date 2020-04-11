#include <stdio.h>
#include <limits.h>

unsigned int populationPrompt();
long long scanNumber(long long i);
long long leastCommonMultiple(long long *arr, unsigned int population);
long long pairMultiple(long long x, long long y);

int main(void)
{
	printf("This utility calculates the least common multiple of an infinite \namount of positive numbers (values up to 2^63-1)\n");

	unsigned int population = populationPrompt();
	long long numbers[population];

	for (int i = 0; i < population; i++)
	{
		numbers[i] = scanNumber(i);
	}

	long long lcm = leastCommonMultiple(numbers, population);
	printf("------------------------------------\nThe least common multiple is: %lli\n------------------------------------\n", lcm);
	getchar();
	fputs("Press ENTER to terminate the utility", stdout);
	getchar();
}

unsigned int populationPrompt()
{
	unsigned int population = 0;
	while (population <= 0)
	{
		printf("How many numbers are you\ngoing to find the LCM for? : ");
		scanf("%ui", &population);
	}
	return population;
}

long long scanNumber(long long i)
{
	long long x;
	do
	{
		printf("Give me number %lli: ", i + 1);
		scanf("%lli", &x);
	} while (x <= 0);
	return x;
}

long long leastCommonMultiple(long long *arr, unsigned int population)
{
	for (long long i = 1; i < population; i++)
		arr[i] = pairMultiple(arr[i - 1], arr[i]);
	return arr[population - 1];
}

long long pairMultiple(long long x, long long y)
{
	long long count = 1;
	while (count <= LLONG_MAX)
	{
		if (count % x == 0 && count % y == 0)
			break;
		count++;
	}
	return count;
}

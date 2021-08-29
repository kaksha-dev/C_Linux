#include <stdio.h>
#include <stdlib.h>

void generate_report(char *input_type, int initial_input_size, int increment_by)
{
	struct timeval te;
	int i;
	printf("----------------------------------------------");
	printf("\nsize \t bubble_sort\n");
	printf("----------------------------------------------");
	for (i = 0; i < 8; i++)
	{
		int s = initial_input_size + increment_by * i;
		printf("\n%d", s);
		int b[s];

		generateInput(b, s, input_type);

		gettimeofday(&te, NULL);
		long long start = te.tv_sec * 1000LL + te.tv_usec / 1000;
		bubble_sort(b, s);
		gettimeofday(&te, NULL);
		long long end = te.tv_sec * 1000LL + te.tv_usec / 1000;
		printf("\t %lld", end - start);
	}
}

void generateInput(int a[], int s, char *c)
{
	if (strcmp(c, "a") == 0)
	{
		generateAscending(a, s);
	}
	else if (strcmp(c, "d") == 0)
	{
		generateDescending(a, s);
	}
	else
	{
		generateRandom(a, s);
	}
}

void generateRandom(int a[], int s)
{
	int i;
	for (i = 0; i < s; i++)
	{
		a[i] = rand() % s + 1;
	}
}

void generateAscending(int a[], int s)
{
	int i;
	for (i = 0; i < s; i++)
	{
		a[i] = i;
	}
}

void generateDescending(int a[], int s)
{
	int i;
	for (i = 0; i < s; i++)
	{
		a[i] = s - i;
	}
}

void print(int a[], int s)
{
	int i;
	for (i = 0; i < s; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void bubble_sort(int a[], int ctr)
{
	int i = 0, j;
	for (i = 0; i < ctr - 1; i++)
	{
		for (j = 0; j < ctr - i - 1; j++)
		{
			if (a[j] < a[j + 1])
				swap(a, j, j + 1);
		}
	}
}

int main(int argc, char *argv[])
{

	int initial_input_size = 8000;
	int increment_by = 4000;
	char *input_type = "r";

	if (argc > 1)
		input_type = argv[1];
	if (argc > 2)
		initial_input_size = atoi(argv[2]);
	if (argc > 3)
		increment_by = atoi(argv[3]);
	printf("Sorting input data of type %s with size = %d (incremented by %d) \n", input_type, initial_input_size, increment_by);

	generate_report(input_type, initial_input_size, increment_by);

	printf("\n");
}

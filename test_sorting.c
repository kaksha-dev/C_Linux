#include <stdio.h>
#include <stdlib.h>
#include "q_sort.h"
#include "merge_sort.h"
#include "binary_search.h"
#include <assert.h>

struct emp
{
	char name;
	int age;
	int id;
};
int age_cmp(void *i, void *j)
{
	struct emp *x = (struct emp *)i;
	struct emp *y = (struct emp *)j;
	return x->age - y->age;
}

int emp_id_cmp(void *i, void *j)
{
	struct emp *x = (struct emp *)i;
	struct emp *y = (struct emp *)j;
	return x->id - y->id;
}

int int_cmp(void *a, void *b)
{
	int *i = (int *)a;
	int *j = (int *)b;
	if (*i == *j)
		return 0;
	if (*i > *j)
		return +1;
	return -1;
}

void print_arr(int **a, int length)
{
	int i;
	for (i = 0; i <= length; i++)
		printf("%d\n", *a[i]);
	printf("*******************************\n");
}
void print_emp_arr(struct emp **a, int length)
{
	int i;
	for (i = 0; i <= length; i++)
		printf("%c-%d-%d\n", a[i]->name, a[i]->age, a[i]->id);
	printf("*******************************\n");
}

void test_sort_with_int()
{
	int **a = (int **)malloc(sizeof(int *) * 5);
	int a1 = 5;
	int a2 = 7;
	int a3 = 1;
	int a4 = 3;
	int a5 = 6;
	a[0] = &a1;
	a[1] = &a2;
	a[2] = &a3;
	a[3] = &a4;
	a[4] = &a5;
	q_sort((void **)a, 0, 4, int_cmp);
	assert(*a[0] == 1);
	assert(*a[1] == 3);
	assert(*a[2] == 5);
	assert(*a[3] == 6);
	assert(*a[4] == 7);

	a[0] = &a1;
	a[1] = &a2;
	a[2] = &a3;
	a[3] = &a4;
	a[4] = &a5;
	int **b = (int **)malloc(sizeof(int *) * 5);
	merge_sort((void **)a, 0, 4, (void **)b, int_cmp);
	assert(*a[0] == 1);
	assert(*a[1] == 3);
	assert(*a[2] == 5);
	assert(*a[3] == 6);
	assert(*a[4] == 7);
}

void test_sort_with_emp(){
	struct emp **a = (struct emp **)malloc(sizeof(struct emp *) * 5);
	
	struct emp a1 = {'a', 5, 10};
	struct emp a2 = {'b', 7, 15};
	struct emp a3 = {'c', 1, 9};
	struct emp a4 = {'d', 3, 6};
	struct emp a5 = {'e', 6, 15};
	
	a[0] = &a1;
	a[1] = &a2;
	a[2] = &a3;
	a[3] = &a4;
	a[4] = &a5;
	q_sort((void **)a, 0, 4, age_cmp);
	assert(a[0]->name == 'c');
	assert(a[1]->name == 'd');
	assert(a[2]->name == 'a');
	assert(a[3]->name == 'e');
	assert(a[4]->name == 'b');

	a[0] = &a1;
	a[1] = &a2;
	a[2] = &a3;
	a[3] = &a4;
	a[4] = &a5;
	struct emp **b = (struct emp **)malloc(sizeof(struct emp *) * 5);
	merge_sort((void **)a, 0, 4, (void **)b, emp_id_cmp);
	assert(a[0]->name == 'd');
	assert(a[1]->name == 'c');
	assert(a[2]->name == 'a');
	assert(a[3]->name == 'b');
	assert(a[4]->name == 'e');

}

int main()
{
	test_sort_with_int();
	test_sort_with_emp();
	struct emp **a = (struct emp **)malloc(sizeof(struct emp *) * 5);
	
	struct emp a1 = {'a', 5, 10};
	struct emp a2 = {'b', 7, 15};
	struct emp a3 = {'c', 1, 9};
	struct emp a4 = {'d', 3, 6};
	struct emp a5 = {'e', 6, 15};
	
	a[0] = &a1;
	a[1] = &a2;
	a[2] = &a3;
	a[3] = &a4;
	a[4] = &a5;
	q_sort((void **)a, 0, 4, age_cmp);
	assert(b_search((void **)a, &a1, 0, 4, age_cmp) == 2);

	struct emp a6 = {'f', 100, 15};
	assert(b_search((void **)a, &a6, 0, 4, age_cmp) == -1);
}

void swap(void **a, int i, int j)
{
	void *temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void q_sort(void **a, int L, int R, int (*cmp)(void *, void *))
{
	if (L >= R)
	{
		return;
	}
	int last = L;
	int i = L + 1;
	for (; i <= R; i++)
	{
		if ((*cmp)(a[i], a[L]) < 0)
		{
			swap(a, i, ++last);
		}
	}
	swap(a, L, last);
	q_sort(a, L, last - 1, cmp);
	q_sort(a, last + 1, R, cmp);
}

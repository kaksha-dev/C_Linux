void merge(void **a, int L, int mid, int R, void **b, int(*cmp)(void *, void *)){
	int k = L;
	int i = L;
	int j = mid+1;
	while(k<=R){
		if(i>mid) b[k++] = a[j++];
		else if (j>R)  b[k++] = a[i++];
		else if ((*cmp)(a[i], a[j]) > 0) b[k++] = a[j++];
		else b[k++] = a[i++];

	}
	for(k = L; k<=R;k++)
		a[k] = b[k];
}

void merge_sort(void **a, int L, int R, void **b, int(*cmp)(void *, void *)){
	if (L == R) return; 
	int mid = (L+R)/2;
	merge_sort(a, L, mid, b,cmp);
	merge_sort(a, mid+1, R, b,cmp);
	merge(a,L,mid, R, b, cmp);
}


int b_search( void **a, void *key, int L, int R, int(*cmp)(void *, void*)){
	if (L>R) return -1;
	int mid = (L+R)/2;
	int camp = (*cmp)(key, a[mid]);
	if (camp==0) return mid;
	if (camp>0) return b_search(a, key, L, mid-1, cmp);
	return b_search(a, key, mid+1, R, cmp);
}

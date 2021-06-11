Decimal add(Decimal a, Decimal b) {
	Decimal result;
	result.n = (a.n > b.n) ? a.n : b.n;
	int ost = 0, x = 0;
	unsigned int mn = (a.n < b.n) ? a.n : b.n;
	for (unsigned int i = 0; i <= mn ; i++) {
		x = ost + a.a[i] + b.a[i];
//		printf("%d ;", x);
		result.a[i] = x % 10;
		ost = x / 10;
	}
//	printf("%d\n", result.n);
	for (unsigned int i = mn + 1; i <= result.n; i++) {
		if (a.n > b.n)
			x = ost + a.a[i];
		else
			x = ost + b.a[i];
//		printf("%d ;", x);
		result.a[i] = x%10 ;
		ost = x/10 ;
	}
	if (ost != 0) {
		result.n++;
		result.a[result.n] = ost ;
	}
	return result;
}

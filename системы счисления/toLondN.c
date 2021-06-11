LongN getLongN(char *s) {
	LongN result;
	int l = 0, kl = 1;
	while ((s[l] >= '0' && s[l] <= '9') || s[l] == '-' || s[l] == '+')
		l++;
	if (s[0] == '-')
		result.sign = 1;
	else
		result.sign = 0;
	char ts[201];
	ts[0] = (result.sign == 0) ? '+' : '-' ;
	int k = (s[0] == '-' || s[0] == '+') ? 1 : 0 ;
	while (s[k] == '0')
		k++;
	while (k < l) {
		ts[kl] = s[k];
		kl++;
		k++;
	}
//	printf("%d %d\n", kl, l-2);
	if (kl == 1 && s[l-1] == '0') {
		kl = 2;
		ts[1] = '0';
		ts[0] = '+';
		result.sign = 0;
	}
//	printf("%s\n", ts);
	int n = kl - 1;
	result.n = n/2 + n%2 ;
	int p1 = 0, p2 = 0 ;
	result.dig = (char *)malloc(n * sizeof(char));
//	printf("%d\n", result.n);
	for (int i = 0; i < result.n; i++) {
		p1 = n - i * 2;
		p2 = n - (i * 2 + 1);
		if (ts[p2] != '-' && ts[p2] != '+' && p2 >= 0)
			result.dig[i] = (ts[p2] - '0') * 10 + (ts[p1] - '0');
		else
			result.dig[i] = ts[p1] - '0';
	//	printf("%d %d ;", p1, p2);
	}
//	printf("\n"); */
	return result;
}

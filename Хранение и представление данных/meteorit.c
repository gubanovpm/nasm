union data convert(union data x) {

	union data result;
	result.u64 = 0;
	u_int64_t m = 255;
	for (int i = 7; i >= 0; i--) {
		u_int64_t mask = m & x.u64;
		x.u64 = x.u64 >> 8;
		if (i != 0)
			result.u64 = (result.u64 | mask) << 8;
		else
			result.u64 = (result.u64 | mask);
	}
	return result;
	
}
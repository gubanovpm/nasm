char *whatisyourname() {
	char *name = (char *)malloc(sizeof(char) * 257);
	name[0] = 'n';
	name[1] = 'e';
	name[2] = 'o';
	for (int i = 3; i < 257; i++)
		name[i] = 1;
	name[256] = 0;
	return name;
}

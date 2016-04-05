#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float i;
	int u;
	int n;
	int h;
	double test;
	char *str;

	u = 1;
	n = 0;
	i = 123.1234567;
	test = (double)i;
	printf("%f\n", test);
	while (i / 1 >= 10)
	{
		i = i / 10;
		u++;
	}
	str = (char*)malloc((u + 12 + 1) * sizeof(char));
	while (u + 12)
	{
		if (u == 0)
			str[n++] = '.';
		h = (int)i;
		str[n++] = h + '0';
		i = i - (double)h;
		i = i * 10;
		u--;
	}
	printf("%s\n", str);
}

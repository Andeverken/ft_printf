#include <math.h>
#include <stdio.h>

int main(void)
{
	float i;
	float u;
	int n;

	i = 100.1234567;
	n = (int) i;
	i = i - n;
	printf("%.20f\n", i);
}

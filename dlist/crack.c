#include <stdio.h>

unsigned int f1(unsigned int n)
{
	return ((n ^ 59) & 63);
}

int main()
{
	printf("%u\n", f1(40));
	return (0);
}


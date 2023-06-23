#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * f2 - digit two
 * @a: arg1
 * @n: size
 * Return: ans
 */
unsigned int f2(char *a, int n)
{
	int m = 0, i;

	for (i = 0; i < n; i++)
		m += *(a + i);
	return ((m ^ 0x4f) & 0x3f);
}

/**
 * f3 - digit three
 * @a: arg1
 * @n: size
 * Return: ans
 */
unsigned int f3(char *a, int n)
{
	int m = 1, i;

	for (i = 0; i < n; i++)
		m = (*(a + i) * m);
	return ((m ^ 0x55) & 0x3f);
}

/**
 * f4 - digit four
 * @a: arg1
 * @n: size
 * Return: ans
 */
unsigned int f4(char *a, int n)
{
	int m = *a, i;

	for (i = 0; i < n; i++)
		if (a[i] > m)
			m = a[i];
	srand(m ^ 0xe);
	return (rand() & 0x3f);
}

/**
 * f5 - digit five
 * @a: arg1
 * @n: size
 * Return: ans
 */
unsigned int f5(char *a, int n)
{
	int m = 0, i;

	for (i = 0; i < n; i++)
		m += (*(a + i) * (*(a + i)));

	return ((m ^ 0xef) & 0x3f);
}

/**
 * main - Entry point
 * @ac: argc
 * @av: argv
 * Return: Always 0
 */
int main(int ac, char **av)
{
	char pass[7], *user;
	int i = 0, len = 0, rnd = 0;
	char s[] = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	unsigned int (*funcs[])(char *, int) = {f2, f3, f4, f5};

	if (ac != 2)
	{
		printf("Usage: %s username\n", av[0]);
		return (1);
	}
	user = av[1];
	len = strlen(user);
	pass[0] = s[((len ^ 0x3b) & 0x3f)];
	for (i = 1; i < 5; i++)
		pass[i] = s[funcs[i - 1](user, len)];
	for (i = 0; *user > i; i++)
		rnd = rand();
	pass[5] = s[((rnd ^ 0xe5) & 0x3f)];
	pass[6] = '\0';
	printf("%s", pass);

	return (0);
}

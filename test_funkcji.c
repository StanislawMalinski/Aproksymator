#include <stdio.h>

int fi(int n, int x)
{
	if(n == 0)
	{
		return 1;
	}
	else if(n == 1)
	{
		return x;
	}
	else
	{
		return 2 * x * fi(n - 1, x) - fi(n - 2, x);
	}
}

int dfi(int n, int x)
{
	if(n == 0)
	{
		return 0;
	}
	else if(n == 1)
	{
		return 1;
	}
	else
	{
		return 2 * fi(n - 1, x) + 2 * x * dfi(n - 1, x) - dfi(n - 2, x);
	}
}

int d2fi(int n, int x)
{
	if(n == 0 || n == 1)
	{
		return 0;
	}
	else
	{
		return 4 * dfi(n - 1, x) + 2 * x * d2fi(n - 1, x) - d2fi(n - 2, x);
	}
}

int d3fi(int n, int x)
{
	if(n == 0 || n == 1)
	{
		return 0;
	}
	else
	{
		return 6 * d2fi(n - 1, x) + 2 * d3fi(n - 1, x) - d3fi(n - 2, x);
	}
}

int main()
{
	int i;
	int n = 5;

	for(i = 1; i < 6; i++)
	{
		printf("Dla x = %d:\n", i);
		printf("f(x) = %d\n", fi(n, i));
		printf("f'(x) = %d\n", dfi(n, i));
		printf("f''(x) = %d\n", d2fi(n, i));
		printf("f'''(x) = %d\n", d3fi(n, i));
	}

	return 0;
}

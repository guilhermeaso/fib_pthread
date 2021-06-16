#include <cstdio>
#include <pthread.h>

int fibroutine(int);

int main(int argc, char **argv)
{
	fibroutine(21);

	return 0;
}

int fibroutine(int len)
{
	int a = 1, b = 0, c = 0;
	for(int i = 0; i < len; i++) {
		printf("%d: %d\n", i, a);
		c = a + b;
		b = a;
		a = c;
	}
	return 0;
}

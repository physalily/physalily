#define call_sub(n) _Generic((n), \
	int: sub_int, \
	long: sub_long, \
	default: sub_any \
	)(n)

#include <stdio.h>

void sub_int (int val)
{
	printf("%s %d\n", __func__, val);
}

void sub_long (long val)
{
	printf("%s %ld\n", __func__, val);
}

void sub_any (char val)
{
	printf("%s %d\n", __func__, val);
}

int main (void)
{
	int n = 0;
	long ln = 2;
	char cn = 5;

	call_sub(ln);
	call_sub(cn);
	call_sub(n);

	return 0;
}


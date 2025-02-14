#include <stdio.h>
#include <stdarg.h>

int sum(int count, ...)
{
	va_list args;
	int total = 0;

	va_start(args, count);
	for (int i = 0; i < count; i++)
	{
		total += va_arg(args, int);
	}
	va_end(args);
	return total;
}

int main(){
	printf("sum: %d\n", sum(10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 111));
	return 0;
}

int ft_printf(const char *frmt, ...)
{
	va_list args;
	
}

void check_printable(int num_args, ...)
{
	
}
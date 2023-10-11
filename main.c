#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	int s = 100;
	ft_printf("\n%Xhello %%%%%%  %s\n", s, NULL);
	printf("\n%Xhello %%%%%%  %s\n", s, NULL);
	return (0);
}

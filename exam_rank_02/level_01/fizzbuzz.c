
#include <stdio.h>

int	main(void)
{
	int number, k, j;

	number = 1;

	while (number <= 100)
	{
		if (number % 3 == 0 && number % 5 == 0)
			write(1, "fizzbuzz", 8);
		if (number % 5 == 0)
			write(1, "buzz", 4);
		if (number % 3 == 0)
			write(1, "fizz", 4);
		else if (number > 10)
		{
			k = number / 10 + '0';
			j = number % 10 + '0';
			write (1, &k, 1);
			write (1, &l, 1);
		}
		else
		{
			k = i + '0';
			write(1, &k, 1);
		}
		write(1, "\n", 1);
		number++;
	}
}
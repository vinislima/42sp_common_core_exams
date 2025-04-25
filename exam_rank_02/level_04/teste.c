#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	
	char *str = argv[1];
	int len = 0;
	
	while (str[len])
		len++;
	if (len == 0)
	{
		write(1, "\n", 1);
		return 0;
	}
	int end = len - 1;

	while (end >= 0)
	{
		int i = end;
		while (i >= 0 && str[i] != ' ')
			i--;
		int word_start = i + 1;
		if (i < 0)
			word_start = 0;
		int j = word_start;
		while (j <= end)
			write(1, &str[j++], 1);
		if (i >= 0)
			write(1, " ", 1);
		end = i - 1;
	}
	write(1, "\n", 1);
	return 0;
}
#include "libft.h"
#include <stdio.h>

int main(void)
{
	int fd = 0;
	char *str;
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	return (0);
}

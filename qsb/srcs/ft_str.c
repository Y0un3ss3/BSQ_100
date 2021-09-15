#include <unistd.h>

void ft_putstr(char *s, int fd) {
	int i;

	i = 0;
	if (!s)
		return;
	while(s[i]) {
		write(fd, &s[i], 1);
		i++;
	}
}

int ft_strlen(char *s) {
	int i;

	i = 0;
	if (!s)
	return (0);
	while(s[i]) {
		i++;
	}
	return (i);
}

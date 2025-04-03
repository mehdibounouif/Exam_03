#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	int	i;
	int	bytes;
	char	*buffer;
	char	c;

	buffer = (char *)malloc(1000);
	if (fd < 0 || !buffer)
		return (NULL);
	bytes = read(fd, &c, 1);
	i = 0;
	while (bytes > 0)
	{
		buffer[i] = c;
		i++;
		if (c == '\n' || c == '\0')
			break;
		bytes = read(fd, &c, 1);
	}
	if (i == 0 || bytes < 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	return (buffer);
}

int	main()
{
	char	*line;
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
}

#include "get_next_line.h"

static void *new_buffer_extended_by(void *buffer, size_t len_buffer, char c_tmp)
{
	void *new_buffer;
	size_t len_new_buffer;

	len_new_buffer = len_buffer + 1;

	new_buffer = (void *) ft_calloc(len_new_buffer, sizeof(char));

	ft_memcpy(new_buffer, buffer, len_buffer);
	*((char *)(new_buffer + (len_new_buffer - 1))) = c_tmp;

	return (new_buffer);
}

static char *format_buffer_to_string(void *buffer, size_t len_buffer)
{
	char *buffer_formatted;
	

	buffer_formatted = (char *) new_buffer_extended_by(buffer, len_buffer, '\0');
	free(buffer);
	return (buffer_formatted);

}

char *get_next_line(int fd)
{
	int is_byte_read;
	char c_tmp;
	void *buffer_tmp;
	void *buffer;
	size_t len_buffer;

	len_buffer = 1;
	is_byte_read = read(fd, &c_tmp, 1);
	if (is_byte_read > 0)
		buffer = new_buffer_extended_by(NULL, 0, c_tmp);
	else
		return (NULL);
	while (c_tmp != '\n' && is_byte_read != 0)
	{
		is_byte_read = read(fd, &c_tmp, 1);
		if (is_byte_read > 0)
		{
			buffer_tmp = new_buffer_extended_by(buffer, len_buffer, c_tmp);
			free(buffer);
			buffer = buffer_tmp;
			len_buffer = len_buffer + 1;
		}
	}
	return format_buffer_to_string(buffer, len_buffer);
}

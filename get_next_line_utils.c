
#include "get_next_line.h"

void	*ft_calloc(size_t element_count, size_t element_size)
{
	unsigned char	*ptr;
	size_t			bytes_to_allocate;
	size_t			i;

	bytes_to_allocate = element_count * element_size;
	ptr = (unsigned char *) malloc(bytes_to_allocate);
	i = 0;
	if (!ptr)
		return ((void *)0);
	while (i < bytes_to_allocate)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest_casted;
	const char	*src_casted;
	size_t		i;

	if ((dest == src) || n == 0)
		return (dest);
	if (!dest && !src)
		return (dest);
	dest_casted = dest;
	src_casted = src;
	i = 0;
	while (i < n)
	{
		dest_casted[i] = src_casted[i];
		i = i + 1;
	}
	return (dest);
}

/* ************************************************************************** */
/**//**//*****//**//*   By: *//**//*   Created:   by *//*   Updated:   by *//**/
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst != src)
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src < dst && dst < src + len)
	{
		while (len--)
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		return (dst);
	}
	return (ft_memcpy(dst, src, len));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (0 < dstsize)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (dst[i] && i < dstsize)
		i++;
	if (0 < dstsize)
	{
		while (*src && i < dstsize - 1)
			dst[i++] = *(src++);
		if (i < dstsize)
			dst[i] = '\0';
	}
	while (*(src++))
		i++;
	return (i);
}

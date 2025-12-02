#include "../../inc/Solution.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		size;
	int		i;

	size = strlen(s);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < size)
		str[i] = s[i];
	str[size] = '\0';
	return (str);
}
#include "pipex.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(const char *s)
{
	write(1, s, ft_strlen(s));
}

char	*ft_strdup(const char *s1)
{
	size_t		len_s1;
	char		*res;
	int			i;

	i = 0;
	len_s1 = ft_strlen(s1);
	res = malloc(sizeof(char) * len_s1 + 1);
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}


#include "map.h"

void map_errors(char **ptr, size_t ptr_size, int error_num)
{
	free_double_ptr(ptr, ptr_size);
	error_handle(error_num, NULL);
}

char	*sl_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	i;
	size_t	j;
	size_t	trimmed_size;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
    if (s1[j] == '\n')
	{
        j--;
	}
	while (ft_strchr(set, s1[i]) && i < j)
		i++;
	while (ft_strchr(set, s1[j]) && j >= i)
		j--;
	trimmed_size = j - i + 1;
	if (i > j)
		trimmed = (char *)malloc(sizeof(char) * 1);
	else
		trimmed = ft_strndup(&s1[i], trimmed_size);
	if (!trimmed)
		return (NULL);
	trimmed[trimmed_size] = '\0';
	return (trimmed);
}
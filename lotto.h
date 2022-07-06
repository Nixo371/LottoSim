#ifndef LOTTO_H
# define LOTTO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <time.h>

typedef struct s_prize
{
	int	prizes[12][4];
}	t_prize;

char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);

#endif
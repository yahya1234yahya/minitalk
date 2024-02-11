#include "minilib.h"

void	ft_bzero(void	*s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = '\0';
		i++;
	}
}

void	*ft_calloc_exit(size_t count, size_t size)
{
	size_t	total_size;
	void	*ret;

	total_size = size * count;
	ret = malloc(total_size);
	if (!ret)
		exit(EXIT_FAILURE);
	ft_bzero(ret, total_size);
	return (ret);
}
int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0 && power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

static int	check_sign(char c, int *sign)
{
	if (c == '-' || c == '+')
	{
		if (c == '-')
			*sign = -1;
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;
	long	rs;

	sign = 1;
	i = 0;
	if (str[i] == '\0')
		return (0);
	while ((str [i] >= 9 && str [i] <= 13) || str[i] == 32)
		i++;
	if (check_sign(str[i], &sign))
		i++;
	res = 0;
	while (str [i] >= '0' && str [i] <= '9')
	{
		rs = res;
		res = (res * 10) + (str[i++] - '0');
		if (res < rs && sign == 1)
			return (-1);
		if (res < rs && sign == -1)
			return (0);
	}
	return ((int)res * sign);
}
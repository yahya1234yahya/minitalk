#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef MINI
# define MINI
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
int	ft_recursive_power(int nb, int power);
void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	*ft_calloc_exit(size_t count, size_t size);
void	ft_bzero(void	*s, size_t n);
int	ft_atoi(const char *str);
#endif
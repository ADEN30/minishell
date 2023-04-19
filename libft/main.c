#include "libft.h"
#include "ft_printf/ft_printf.h"
int	main(void)
{
	char *str;


	str = malloc(0);
	if (str)
	{
		str = NULL;
		ft_printf("%p", str);
	}
	else
		ft_printf("pas de mem\n");
	return (0);

}

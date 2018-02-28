#include "fractol.h"

int		validate_params(int argc, char **argv)
{
	int			i;
	int			parameter;
	int			valid_arg;

	i = 1;
	while (i < argc)
	{
		parameter = ft_atoi(argv[i]);
		valid_arg = 0;
		if (parameter / 100 >= 1 && parameter / 100 <= 2)
			if (parameter % 100 >= 1 && parameter % 100 <= NUM_OF_VARIATIONS)
				valid_arg = 1;
		if (!valid_arg)
			return (-1);
		i++;
	}
	return (0);
}

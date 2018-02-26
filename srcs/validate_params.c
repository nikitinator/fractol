#include "fractol.h"

t_frct_data	*get_frct_data()
{
	static t_frct_data	data[] = {
		{1 ,"Mandelbrot"                   ,iterate_mandelbrot	                  },
		{2 ,"Mandelbar / Tricorn"          ,iterate_mandelbar	                  },
		{3 ,"Perppendicular Mandelbrot"    ,iterate_perp_brot	                  },
		{4 ,"Celtic Mandelbrot"            ,iterate_celtic_brot	              	},
		{5 ,"Celtic Mandelbar"             ,iterate_celtic_bar	                  },
		{6 ,"Perpendicular Celtic"         ,iterate_perp_celtic					},
		{7 ,"Burning ship"                 ,iterate_burn_ship	                  },
		{8 ,"Heart Mandelbrot"             ,iterate_heart_brot	                  },
		{9 ,"Perpendicular Burning Ship"   ,iterate_perp_burn_ship                 },
		{10 ,"Buffalo"                      ,iterate_buffalo		              },
		{11 ,"Celtic Heart"                 ,iterate_celt_heart	                  },
		{12 ,"Perpendicular Buffalo"        ,iterate_perp_buffalo                 }
		//{"Buddabrot"                                      },
		//{"Julia"										  },
       	//{"Lyapunov"                                       },
       	//{"Newton"                                         }
	};
	return (data);
}

int		validate_params(int argc, char **argv)
{
	t_frct_data *data;
	int			i;
	int			parameter;

	data = get_frct_data();
	i = 1;
	while (i < argc)
	{
		ft_putendl("");
		ft_putendl(argv[i]);
		ft_putendl("");
		ft_putendl("");
		parameter = ft_atoi(argv[i]);
		if (parameter < 1 || parameter > 12)
			return (-1);
		i++;
	}
	return (0);
}

//,1.2, -1.2, 1.0,-2.0
//,1.2, -1.2, 1.0,-2.0
//,1.2, -1.2, 1.0,-2.0
//,1.2, -1.2, 1.0,-2.0
//,1.2, -1.2, 1.0,-2.0
//,1.2, -1.2, 1.0,-2.0
//,1.2, -1.2, 1.0,-2.0
//,1.2, -1.2, 1.0,-2.0
//,1.2, -1.2, 1.0,-2.0
//,1.2, -1.2, 1.0,-2.0
//,1.2, -1.2, 1.0,-2.0
//,1.2, -1.2, 1.0,-2.0
//,1.2, -1.2, 1.0,-2.0
//,1.2, -1.2, 1.0,-2.0
//,1.2, -1.2, 1.0,-2.0
//,1.2, -1.2, 1.0,-2.0

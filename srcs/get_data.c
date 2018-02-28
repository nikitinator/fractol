/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 14:16:05 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/27 14:24:38 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_frct_itr_data	*get_frct_itr_data(void)
{
	static t_frct_itr_data	data[] = {
		{1 ,"Default"                   ,iterate_default						},
		{2 ,"Tricorn"          	,iterate_tricorn},
		{3 ,"Perppendicular"    ,iterate_perp_brot	                  },
		{4 ,"Celtic"            ,iterate_celtic_brot	              	},
		{5 ,"Celtic Tricorn"             ,iterate_celtic_bar	                  },
		{6 ,"Perpendicular Celtic"         ,iterate_perp_celtic					},
		{7 ,"Burning ship"                 ,iterate_burn_ship	                  },
		{8 ,"Heart"             ,iterate_heart_brot	                  },
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

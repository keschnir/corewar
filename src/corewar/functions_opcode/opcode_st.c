/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opcode_st.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <fpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/07 10:04:04 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 10:04:04 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static int		check_st(t_var *data, unsigned int pc, int dir_oct)
{
	unsigned char	p[2];
	unsigned char	test;
	size_t 			i;

	i = 0;
	test = '\0';
	p[0] = data->vm[((pc + 1) % MEM_SIZE)] >> 6;
	p[1] = (unsigned char)(0x3 & (data->vm[((pc + 1) % MEM_SIZE)] >> 4));
	data->op_size += 1;
	while (i < 2)
	{
		if (p[i] == REG_CODE)
			data->op_size += 1;
		else if (p[i] == DIR_CODE)
			dir_oct == 2 ? (data->op_size += 2) : (data->op_size += 4);
		else if (p[i] == IND_CODE)
			data->op_size += 2;
		i++;
	}
	if (p[1] == REG_CODE)
		test = p[1];
	else if (p[1] == IND_CODE)
		test = p[1];
	if ((p[0] != REG_CODE) || !(test))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int				opcode_st(t_var *data, t_process *p_process)
{

	unsigned char	tmp_val[4];
	int 			i;

	if (!check_st(data, p_process->pc, 4) && !ft_params_opcode(data, p_process, 4, 0))
	{
		if (data->t_params[1][1] == 0)
		{
			tmp_val[0] = p_process->registre[data->t_params[1][0]].val >> 24;
			tmp_val[1] = p_process->registre[data->t_params[1][0]].val >> 16;
			tmp_val[2] = p_process->registre[data->t_params[1][0]].val >> 8;
			tmp_val[3] = p_process->registre[data->t_params[1][0]].val;
			i = 0;
			while (i < REG_SIZE)
			{
				data->vm[((p_process->pc + (data->t_params[0][1] % IDX_MOD) + i))
					% MEM_SIZE] = tmp_val[i];
				i++;
			}
			if (data->v == 4 || data->v == 6)
				ft_printf("P %4i | st r%i %i\n", p_process->id,
					data->t_params[1][0], data->t_params[0][1]);
		}
		else
		{
			p_process->registre[data->t_params[1][1]].val
				= p_process->registre[data->t_params[1][0]].val;
			if (data->v == 4 || data->v == 6)
				ft_printf("P %4i | st r%i %i\n", p_process->id,
					data->t_params[1][0], data->t_params[1][1]);
		}
		p_process->pc = ((p_process->pc + data->op_size) % MEM_SIZE);
		return (EXIT_SUCCESS);
	}
	p_process->pc = ((p_process->pc + data->op_size) % MEM_SIZE);
	return (EXIT_FAILURE);
}
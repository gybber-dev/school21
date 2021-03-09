#include "../ft_cub.h"

static void			print_error(t_msg *errors, int code)
{
	int				is_my_err;
	int				i;

	i = 0;
	is_my_err = 0;
	if (code != 0)
	{
		ft_putstr_fd("Error\n\tmessage: ", 1);
		while(errors[i].text != NULL && errors[i].code != 0)
		{
			if (code == errors[i].code)
			{
				ft_putstr_fd(errors[i].text, 1);
				is_my_err = 1;
				break ;
			}
			i++;
		}
		if (!is_my_err)
			ft_putstr_fd(strerror(code), 1);
		write(1, "\n", 1);
	}

}

void				ft_error(t_set *set, int code)
{
	t_msg			*errors;

	errors = (t_msg[9]){
			{ERR_READ_FILE, "File reading error"},
			{ERR_HEAD_0, "Not a valid head. Check path"},
			{ERR_HEAD_1, "Not a valid head. Double definition of element"},
			{ERR_HEAD_2, "Not a valid head. Incorrect format of data"},
			{ERR_LINE, "Not a valid string"},
			{ERR_FEW_DATA, "There is too few data in the file"},
			{ERR_PLAYERS, "There are too much players in the map"},
			{ERR_MAP, "Map is not valid"},
			{0, NULL}
	};
	print_error(errors, code);
	auto_clear(set);
	exit(EXIT_FAILURE);
}
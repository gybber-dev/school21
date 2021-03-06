#include "../ft_cub.h"

void				ft_error(t_set *set, int code)
{
	printf("code is %d\nerrno is %d\n", code, errno);
	int				is_my_err;
	int				i;
	const t_msgs	errors[] =
	{
		{ERR_READ_FILE, "File reading error"},
		{NOT_VALID_HEAD_0, "Not a valid head. Check path"},
		{NOT_VALID_HEAD_1, "Not a valid head. Double definition of element"},
		{NOT_VALID_HEAD_2, "Not a valid head. Incorrect format of data"},
		{NOT_VALID_LINE, "Not a valid string"},
		{ERR_FEW_DATA, "There is too few data in the file"},
		{ERR_PLAYERS, "There are too much players in the map"},
		{0, NULL}
	};
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
		auto_clear(set);
		exit(EXIT_FAILURE);
	}
}
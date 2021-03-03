#include "../ft_cub.h"

void		ft_error(int code)
{
	printf("code is %d\nerrno is %d\n", code, errno);


	const t_msgs text[] =
	{
		{1021, "ssss"},
		{1021, "ssss"},
		{0, NULL}
	};
	while(text->text != NULL && text->code != 0)
	{
		break ;
		// do something
	}
	if (code != 0)
	{
		ft_putstr_fd("Error\n\tmessage: ", 1);
		if (code == ERR_READ_FILE)
			ft_putstr_fd("File reading error", 1);
		if (code == NOT_VALID_HEAD_0)
			ft_putstr_fd("Not a valid head. Check path", 1);
		else
			ft_putstr_fd(strerror(code), 1);
//		auto_clear(all);
		exit(EXIT_FAILURE);
	}
}
#include "ft_errors.h"

void		ft_error(int code)
{
	printf("code is %d\nerrno is %d\n", code, errno);


	if (code != 0)
	{
		ft_putstr_fd("Error\n\tmessage: ", 1);
		if (code == ERR_READ_FILE)
			ft_putstr_fd("File reading error", 1);
		if (code == NOT_VALID_HEAD_0)
			ft_putstr_fd("Not a valid head. Check path", 1);
		else
			ft_putstr_fd(strerror(code), 1);
	//	auto_clear();
		exit(EXIT_FAILURE);
	}
}
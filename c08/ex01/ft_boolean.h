#ifndef _STDBOOL_
#define _FT_BOOLEAN_H
typedef int t_bool;
#define	TRUE	1
#define	FALSE	0
#define	EVEN(x)	x%2==0
#define	EVEN_MSG	"I have an even number of arguments.\n"
#define	ODD_MSG		"I have an odd number of arguments.\n"
#define	SUCCESS		1
#endif
void	ft_pustr(char *str);
t_bool	ft_is_even(int nbr);

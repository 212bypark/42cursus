#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>

# define MIN_INT -2147483648
# define MAX_INT 2147483647

typedef struct s_node
{
	int				value;
	struct s_node	*pre;
	struct s_node	*nxt;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
	char	name;
}	t_stack;

typedef struct s_data
{
	int		*origin;
	int		*arr;
	int		size;
	int		dir;
	int		box[4];
	int		move[8];

	t_stack	*a;
	t_stack	*b;
}		t_data;

/*  Function */

int		free_process(t_data *data);
void	error_process(t_data *data);
int		get_int(t_data *data, const char *str);

void	stack_build(t_data *data, t_stack *stack, int value);

void	parsing(t_data *data, char **str, int ac);
void	check_duplicates(t_data *data);
int		check_sorted(t_stack *stack);
void	quick_sort(int *arr, int x, int y);

void	sorting(t_data *data);
void	sort(t_data *data, t_stack *a, t_stack *b, int *box);

/*  Stack Function */

void	push(t_stack *stack, t_node *node);
t_node	*pop(t_stack *stack);

/*  Operations */
void	pa(t_data *data);
void	pb(t_data *data);

void	sx(t_stack *x);
void	ss(t_data *data);

void	rx(t_stack *x);
void	rr(t_data *data);
void	rrx(t_stack *x);
void	rrr(t_data *data);

/*  Libft function */
int		ft_max(int x, int y);
int		ft_min(int x, int y);
void	ft_bzero(void *ptr, size_t num);
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char const *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
// size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif

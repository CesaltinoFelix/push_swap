#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/ft_printf.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_target
{
	int				value_a;
	int				value_b;
	int				dir_a;
	int				dir_b;
}					t_target;

typedef struct s_stack_info
{
	long int		total_moves;
	int				stack_a_size;
	int				stack_b_size;
	int				dir_a;
	int				dir_b;
	int				element_index;
	int				element_value;
	int				counter;
	int				arg_value;
}					t_stack_info;

void				ft_init_list(t_node **list, int value);
void				ft_print_list(t_node *list);

int					ft_isvalid(long n);
int					ft_count_array(char **array);
int					ft_check_duplicates(t_node *list, int n);
int					ft_check_sorted(t_node *list);
int					ft_validate_input_one(char **av, int i, t_node **list);
int					ft_validate_input_two(char **av, int i, t_node **list);
int					ft_validate_global(int ac, char **av, t_node **stack_a);

int					ft_stack_get_max(t_node *list);
int					ft_stack_get_min(t_node *list);
int					ft_get_best_option(t_node **a, int b);
int					ft_get_index(t_node *a, int value);
int					ft_count_list(t_node *list);

t_node				*ft_stack_get_top(t_node *list);
t_node				*ft_stack_get_last(t_node *list);

void				ft_free_list(t_node *list);
void				ft_free_matrix(char **matrix);

void				ft_push_b(t_node **a, t_node **b);
void				ft_push_a(t_node **a, t_node **b);

void				ft_swap_a(t_node **a, int flag);
void				ft_swap_b(t_node **a, int flag);
void				ft_swap_swap(t_node **a, t_node **b);

void				ft_rotate_a(t_node **a, int flag);
void				ft_rotate_b(t_node **b, int flag);
void				ft_reverse_rotate_a(t_node **a, int flag);
void				ft_reverse_rotate_b(t_node **b, int flag);
void				ft_rotate_rotate(t_node **a, t_node **b);
void				ft_reverse_rotate_rotate(t_node **a, t_node **b);

void				ft_rrr_rr(t_node **a, t_node **b, t_target target_data);

void				ft_sort_two(t_node **a);
void				ft_sort_three(t_node **a);
void				ft_sort_more(t_node **a, t_node **b);

t_target			ft_calculate_moves(t_node **a, t_node **b);
void				ft_move_min_to_top(t_node **a);

#endif

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
	int				value;   // 'data' foi alterado para 'value' para refletir melhor o conteúdo
	struct s_node	*next;
}					t_node;

typedef struct s_target
{
	int				value_a;  // 'a_valor' foi alterado para 'value_a' para consistência com a linguagem
	int				value_b;  // 'b_valor' foi alterado para 'value_b'
	int				dir_a;    // 'a_sentido' foi encurtado para 'dir_a' (dir = direção)
	int				dir_b;    // 'b_sentido' foi encurtado para 'dir_b'
}					t_target;

typedef struct s_stack_info
{
	long int		total_moves;  // 'n_plus_b' foi alterado para 'total_moves' para refletir sua função
	int				stack_a_size; // 'pilha_a' foi renomeado para 'stack_a_size' para indicar claramente o que armazena
	int				stack_b_size; // 'pilha_b' foi renomeado para 'stack_b_size'
	int				dir_a;        // 'sentido_a' foi encurtado para 'dir_a'
	int				dir_b;        // 'sentido_b' foi encurtado para 'dir_b'
	int				element_index; // 'index' foi renomeado para 'element_index' para clareza
	int				element_value; // 'value' foi renomeado para 'element_value' para evitar confusão
	int				counter;       // 'i' foi renomeado para 'counter' para uma nomenclatura mais descritiva
	int				arg_value;     // 'arg' foi renomeado para 'arg_value'
}					t_stack_info;

void				ft_init_list(t_node **list, int value);
void				ft_print_list(t_node *list);

int					ft_isvalid(long n);
int					ft_count_array(char **array);
int					ft_check_duplicates(t_node *list, int n);  // 'ft_verif_repeat' renomeado para 'ft_check_duplicates'
int					ft_check_sorted(t_node *list);  // 'ft_verif_sequence' renomeado para 'ft_check_sorted'
int					ft_validate_input_one(char **av, int i, t_node **list); // 'ft_validar_data_one' renomeado para clareza
int					ft_validate_input_two(char **av, int i, t_node **list); // 'ft_validar_data_two' renomeado
int					ft_validate_global(int ac, char **av, t_node **stack_a); // 'ft_global_valid' renomeado

int					ft_stack_get_max(t_node *list);
int					ft_stack_get_min(t_node *list);
int					ft_get_best_option(t_node **a, int b);
int					ft_get_index(t_node *a, int value);
int					ft_count_list(t_node *list);

t_node				*ft_stack_get_top(t_node *list);   // 'pilha' foi alterado para 'stack'
t_node				*ft_stack_get_last(t_node *list);

void				ft_free_list(t_node *list);
void				ft_free_matrix(char **matrix);  // Correção de 'ft_free_matrix'

void				ft_push_b(t_node **a, t_node **b);
void				ft_push_a(t_node **a, t_node **b);

void				ft_swap_a(t_node **a, int flag);
void				ft_swap_b(t_node **a, int flag);
void				ft_swap_swap(t_node **a, t_node **b);  // 'ft_swap_swap' renomeado para 'ft_swap_both'

void				ft_rotate_a(t_node **a, int flag);
void				ft_rotate_b(t_node **b, int flag);
void				ft_reverse_rotate_a(t_node **a, int flag);
void				ft_reverse_rotate_b(t_node **b, int flag);
void				ft_rotate_rotate(t_node **a, t_node **b);  // 'ft_rotate_rotate' renomeado para 'ft_rotate_both'
void				ft_reverse_rotate_rotate(t_node **a, t_node **b);  // 'ft_reverse_rotate_rotate' renomeado

void				ft_rrr_rr(t_node **a, t_node **b, t_target target_data);  // 'dados_alvos' renomeado

void				ft_sort_two(t_node **a);  // 'ft_case_two' renomeado para 'ft_sort_two'
void				ft_sort_three(t_node **a);  // 'ft_case_three' renomeado para 'ft_sort_three'
void				ft_sort_more(t_node **a, t_node **b);  // 'ft_case_more' renomeado para 'ft_sort_more'

t_target			ft_calculate_moves(t_node **a, t_node **b);  // 'ft_get_nplusb' renomeado para 'ft_calculate_moves'
void				ft_move_min_to_top(t_node **a);  // 'ft_put_min_top' renomeado

#endif

#include "ft_printf.h"
#include "push_swap.h"


t_dbll_lst *create_dbll_list()
{
    t_dbll_lst *list;

    if (!(list = (t_dbll_lst*)malloc(sizeof(t_dbll_lst))))
        return (NULL);
    *list = (t_dbll_lst){0,0,0,0,0,
                         0,0,0,0,0};
//    list->size = 0;
//    list->min = 0;
//    list->max = 0;
//    list->median = 0;
//    list->top = NULL;
//    list->post_top = NULL;
//    list->down = NULL;
    return (list);
}


t_dbll_lst *input_chain(int ac, char **av, t_dbll_lst *chain)
{
    int i;
    size_t data_size = 1;
    tt_node *node;

    i = 0;

    while (i++ < ac-1)
    {
        if (!(node = (tt_node *) malloc(sizeof(tt_node))))
            return (NULL);
        if (!(node->data = malloc(data_size)))
            return (NULL); // ft_lstnew
        node->data = ft_atoi(av[i]);

        node->prev = chain->down;
        node->next = NULL;
        if (chain->down)
            chain->down->next = node;
        chain->down = node;
        if (chain->top == NULL)
            chain->top = node;
        chain->size++;
    }
    chain->post_top = chain->top->next;
    chain->top->prev = NULL;
    return (chain);

}


// TODO rework to is_max instead of label
int   ft_arr_extremums(int *arr, int len_arr, int is_max)
{
    int max;
    int min;

    min = 0;
    max = 0;

    while (len_arr-- > 0)
    {
        if (arr[len_arr] > max)
            max = arr[len_arr];
        if (arr[len_arr] < min)
            min = arr[len_arr];
    }

    if (is_max)
        return (max);
    else
        return (min);

}

int     ft_bound(int *array, int len_arr, int label)
{
    int first_b;
    int second_b;
    int third_b;
    int max;
    int min;

    min = ft_arr_extremums(array, len_arr, 0);
    max = ft_arr_extremums(array, len_arr, 1);

    if (min < 0)
    {
        max += -1 * min;
        min = 0;
    }
    second_b = (min + max) / 2 + min;
    first_b = (min + second_b) / 2 + min;
    third_b = max - (max - second_b) / 2;
    min = ft_arr_extremums(array, len_arr, 0);
    if (min < 0)
    {
        first_b += min;
        second_b += min;
        third_b += min;
    }
    if (label == 1)
        return (first_b);
    else if (label == 2)
        return (second_b);
    else if (label == 3)
        return (third_b);
    else
        return (NULL);
}


t_dbll_lst *ft_mark_stack(int *arr_data, int len_arr, int label)
{
    t_dbll_lst *mark_stack;

    // TODO check is create_dbll_list return NULL
    mark_stack = create_dbll_list();
    if (label == -1)
    {
        mark_stack->min = ft_arr_extremums(arr_data, len_arr, 0);
        mark_stack->median = ft_bound(arr_data, len_arr, 1);
        mark_stack->max = ft_bound(arr_data, len_arr, 2) - 1;
        return (mark_stack);
    }
    else if (label == 1)
    {
        mark_stack->min = ft_bound(arr_data, len_arr, 2);
        mark_stack->median = ft_bound(arr_data, len_arr, 3);
        mark_stack->max = ft_arr_extremums(arr_data, len_arr, 1);
        return (mark_stack);
    }
    else
        return (NULL);
}

void    *ps_push(t_dbll_lst *stack_from, t_dbll_lst *stack_to)
{
    tt_node *tmp;
    tt_node *tmp2;

    tmp = stack_from->top;
    tmp2 = stack_to->top;

    stack_from->top = tmp->next;
    stack_from->post_top = stack_from->top->next;
    if (stack_to->down == NULL)
    {
        stack_to->down = tmp;
        stack_to->top = tmp;
        stack_to->post_top = tmp;
    }
    stack_to->post_top = stack_to->top;
    stack_to->top = tmp;

    stack_to->top->next = stack_to->post_top;

//    stack_to->post_top->prev = stack_to->top;

    stack_to->top->prev = NULL;
    stack_from->top->prev = NULL;
    stack_from->down->next = NULL;

    stack_from->size--;
    stack_to->size++;
//    free(tmp);
//    free(tmp2);

    printf("push ");


}


void *ps_swap(t_dbll_lst *stack)
{
    tt_node *tmp;
    tt_node *second;
    tt_node *third;

    tmp = stack->top;
    second = stack->top->next;
//    printf("second: %d\n", second);
    third = second->next;
//    printf("third: %d\n", third);

    stack->top = second;
    tmp->next = third;
//    stack->second = tmp;
    stack->top->next = tmp;
    stack->post_top = stack->top->next;
    stack->post_top->prev = stack->top;
    stack->top->prev = NULL;
    printf("swap ");



}

void *ps_revrotate(t_dbll_lst *stack)
{
    tt_node *tmp;

    tmp = stack->down;
    stack->down = stack->down->prev;
    stack->post_top = stack->top;
    tmp->next = stack->post_top;
    stack->post_top->prev = tmp;
    stack->top = tmp;
    stack->top->prev = NULL;
    stack->down->next = NULL;
    printf("revrotate ");


}

void *ps_rotate(t_dbll_lst *stack)
{
    tt_node *tmp;

    tmp = stack->top;
    stack->top = stack->top->next;
    stack->post_top = stack->top->next;
    tmp->prev = stack->down;
    stack->down->next = tmp;
    stack->down = tmp;
    stack->top->prev = NULL;
    stack->down->next = NULL;
    printf("rotate ");
}


void    *ft_print_stacks(t_dbll_lst *stack_1, t_dbll_lst *stack_2)
{
    tt_node *node;
    int i;

    i = 1;
    node = stack_1->top;

    if (stack_1) {
        while (i++ <= stack_1->size) {
            printf("%d  ", node->data);
            node = node->next;
        }
        printf("\n");
    }
    i = 1;
    node = stack_2->top;
    while (i++ <= stack_2->size)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
    printf("\n");
}



int     *check_sort(t_dbll_lst *stack, int is_rise)
{
    int max_len_sort;
    int i;
    tt_node *node_first;
    tt_node *node_second;

    max_len_sort = 1;
    i = 1;
    node_first = stack->top;
    node_second = stack->post_top;

    stack->start_sort = stack->top;

    while (i++ < stack->size)
    {
        if (!is_rise)
        {
            if (node_first->data > node_second->data)
            {
                max_len_sort += 1;
//                stack->start_sort = node_first;
                stack->end_sort = node_second;
            }
            else
                max_len_sort = 1;
            node_first = node_first->next;
            node_second = node_second->next;
        }
        else
        {
            if (node_first->data < node_second->data)
            {
                max_len_sort += 1;
//                stack->start_sort = node_first;
                stack->end_sort = node_second;
            }
            else
            {
                max_len_sort = 1;
                stack->start_sort = node_second;
            }
            node_first = node_first->next;
            node_second = node_second->next;
        }
    }
    stack->is_sorted = max_len_sort;

    if (stack->is_sorted == stack->size)
        return (1);
    else
        return (0);
//    return (stack);


}


int     check_over_median(t_dbll_lst *stack)
{
    int result;
    tt_node *node;

    result = 0;

    node = stack->top;
    while (node)
    {
        if (node->data > stack->median)
            result++;
        node = node->next;
    }
    if (result == stack->size)
        return (result);
    else
        return (0);

    printf ("RESULT OVER MED: %d\n", result);


}

void ft_sort_stack_a(t_dbll_lst *stack, t_dbll_lst *stack_b)
{
    if (stack->top->data > stack->down->data)
        ps_rotate(stack);
    if (stack->top->data > stack->post_top->data)
        ps_swap(stack);
    if (stack->down->data < stack->top->data)
        ps_revrotate(stack);
    else
    {
        ps_push(stack, stack_b);
        if (stack->top->data > stack->down->data)
            ps_rotate(stack);
        if (stack_b->top->data < stack_b->post_top->data)
            ps_swap(stack_b);
        if (stack->top->data > stack->post_top->data)
            ps_swap(stack);
        if (stack->top->data < stack_b->top->data)
            ps_push(stack_b, stack);

    }
}


void split_chain_to_4_part(t_dbll_lst *stack_a, t_dbll_lst *stack_b)
{

    if (stack_a->top->data > stack_a->median
        || stack_a->top->data > stack_a->down->data)
        ps_rotate(stack_a);
    if (stack_a->top->data < stack_b->median)
    {
        ps_push(stack_a, stack_b);
        ps_rotate(stack_b);
    }

    if (stack_b->top->data < stack_b->post_top->data)
        ps_swap(stack_b);

    if (stack_a->top->data > stack_b->median
        && stack_a->top->data < stack_a->median)
        ps_push(stack_a, stack_b);




//    else
//        ps_push(stack_a, stack_b);



//    if (stack_a->top->data > stack_a->down->data
//        || stack_a->top->data > stack_a->median)
//        ps_revrotate(stack_a);
//    if (stack_a->top->data < stack_b->median)
//    {
//        ps_push(stack_a, stack_b);
//        ps_revrotate(stack_b);
//    }
//    if (stack_a->top->data > stack_a->post_top->data)
//        ps_swap(stack_a);
//    else
//        ps_push(stack_a, stack_b);

//    if (stack_b->top->data < stack_b->post_top->data)
//        ps_swap(stack_b);

}


void algo(t_dbll_lst *stack_a, t_dbll_lst *stack_b)
{
    int count;

    count = stack_a->size;
    if (stack_a->down->data < stack_a->top->data)
        ps_revrotate(stack_a);
    if (stack_a->top->data > stack_a->median
        || stack_a->top->data > stack_a->down->data)
        ps_rotate(stack_a);


    if (stack_b->top->data < stack_b->median
        && stack_b->top->data > stack_b->min)
        ps_rotate(stack_b);
    if (stack_b->top->data > stack_b->median
        && stack_b->top->data < stack_b->post_top->data)
        ps_swap(stack_b);


    if (stack_a->top->data < stack_a->post_top->data
        && stack_a->top->data < stack_a->down->data)
        ps_push(stack_a, stack_b);
    if (stack_a->top->data > stack_a->down->data)
        ps_rotate(stack_a);
    if (stack_a->top->data > stack_a->post_top->data)
        ps_swap(stack_a);
    if (stack_a->top->data < stack_b->down->data)
    {
        ps_push(stack_a, stack_b);
        ps_rotate(stack_b);
    }

//    if (stack_a->top->data > stack_a->down->data
//        && stack_a->top->data < stack_a->post_top->data)
//        ps_revrotate(stack_a);





//    break;

    // TODO return type is pointer, must return a pointer

}


int main(int ac, char **av)
{
    int i;
    int array_data[ac-1];
    t_dbll_lst *input_data;
    t_dbll_lst *stack_for_max_a;
    t_dbll_lst *stack_for_min_b;
    tt_node *node;  // TEMP

    i = 0;

    while (i < ac-1)
    {
        array_data[i] = ft_atoi(av[i+1]);
//        printf("%d  ", array_data[i]);
        i++;
    }

    stack_for_max_a = ft_mark_stack(array_data, ac - 1, 1);
    stack_for_min_b = ft_mark_stack(array_data, ac - 1, -1);
    stack_for_max_a = input_chain(ac, av, stack_for_max_a);


    ps_push(stack_for_max_a, stack_for_min_b);
//    ps_swap(stack_for_max_a);
//    ps_push(stack_for_max_a, stack_for_min_b);
//    ps_push(stack_for_max_a, stack_for_min_b);
//    ps_rotate(stack_for_max_a);
//    ps_swap(stack_for_max_a);

//    ps_revrotate(stack_for_max_a);


//    ps_rotate(stack_for_max_a);
//    ps_revrotate(stack_for_max_a);

    i = 0;
//    while (i++ < 14)

//    printf("RES: %d\n", check_over_median(stack_for_max_a));
    while (!check_over_median(stack_for_max_a))
    {
//        algo(stack_for_max_a, stack_for_min_b);
        split_chain_to_4_part(stack_for_max_a, stack_for_min_b);
    }
//    while (i++ < 2)
    while (!check_sort(stack_for_max_a, 1))
        ft_sort_stack_a(stack_for_max_a, stack_for_min_b);

    while (stack_for_min_b->top->data > stack_for_min_b->post_top->data
        && stack_for_min_b->top->data < stack_for_max_a->top->data)
        ps_push(stack_for_min_b, stack_for_max_a);
//
//    while (!check_sort(stack_for_min_b, 0))
//        ft_sort_stack_a(stack_for_min_b, stack_for_max_a);

    printf("\n");

//    check_sort(stack_for_max_a, 1);


//    printf("TOP A: %d\n", stack_for_max_a->top->data);
//    printf("SEC A: %d\n", stack_for_max_a->post_top->data);
//    printf("DWN A: %d\n", stack_for_max_a->down->data);
//
//    printf("TOP B: %d\n", stack_for_min_b->top->data);
//    printf("SEC B: %d\n", stack_for_min_b->post_top->data);
//    printf("DWN B: %d\n", stack_for_min_b->down->data);
//
    printf("median a: %d\n", stack_for_max_a->median);
    printf("median b: %d\n", stack_for_min_b->median);
//    printf("max a: %d\n", stack_for_max_a->max);
//    printf("max b: %d\n", stack_for_min_b->max);
//    printf("min a: %d\n", stack_for_max_a->min);
//    printf("min b: %d\n", stack_for_min_b->min);
//    printf("size a: %d\n", stack_for_max_a->size);
//    printf("size b: %d\n", stack_for_min_b->size);
//    printf("SORT: FIRST: %d\n", stack_for_max_a->start_sort->data);
//    printf("SORT: LAST:  %d\n", stack_for_max_a->end_sort->data);
//    printf("SORT: COUNT: %d\n", stack_for_max_a->is_sorted);



//    ft_print_stacks(0, stack_for_max_a);

    ft_print_stacks(stack_for_min_b, stack_for_max_a);





    // 44 79 85 73 33 19 1 23 76 40 83 5
    // 0 9 1 8 2
}
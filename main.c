#include "ft_printf.h"
#include "push_swap.h"

static int operations = 1;


t_dbll_lst *create_dbll_list()
{
    t_dbll_lst *list;

    if (!(list = (t_dbll_lst*)malloc(sizeof(t_dbll_lst))))
        return (NULL);
    *list = (t_dbll_lst){0,0,0,0,0,
                         1,0,0,0};
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
            return (0);
        if (!(node->data = malloc(data_size)))
            return (0); // ft_lstnew
        *node = (tt_node){0,0,0,0,0};
        node->data = ft_atoi(av[i]);

        if (ft_atoi(av[i]) == MAX_INT)
            node->position = ac - 1;

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

    //TODO change values depend of negative numbers

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

    // + TODO check is create_dbll_list return NULL
    // mark_stack = create_dbll_list();
    if (!(mark_stack = create_dbll_list()))
        return (0);
    else
    {
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
    }
}

void    *ps_push(t_dbll_lst *stack_from, t_dbll_lst *stack_to)
{
    tt_node *tmp;

    tmp = stack_from->top;

    if (stack_from->top->next)
    {
        stack_from->top = tmp->next;
        stack_from->post_top = stack_from->top->next;
    }

    if (stack_to->down == NULL)
    {
        stack_to->down = tmp;
        stack_to->top = tmp;
        stack_to->post_top = tmp;
    }
    stack_to->post_top = stack_to->top;
    stack_to->top = tmp;

    stack_to->top->next = stack_to->post_top;
    stack_to->post_top->prev = stack_to->top;

    stack_to->top->prev = NULL;
    stack_from->top->prev = NULL;
    stack_from->down->next = NULL;

    stack_from->size--;
    stack_to->size++;

    printf("p%c ", stack_to->name);

    operations += 1;

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
    third->prev = tmp;
//    printf("third: %d\n", third);

    stack->top = second;
    tmp->next = third;
//    stack->second = tmp;
    stack->top->next = tmp;
    stack->post_top = stack->top->next;
    stack->post_top->prev = stack->top;
    stack->top->prev = NULL;
    printf("s%c ", stack->name);

    operations += 1;




}

void *ps_revrotate(t_dbll_lst *stack)
{
    tt_node *tmp;

    // TODO
    if (stack->size == 0)
        return 0;

    tmp = stack->down;
    stack->down = stack->down->prev;
    stack->post_top = stack->top;
    tmp->next = stack->post_top;
    stack->post_top->prev = tmp;
    stack->top = tmp;
    stack->top->prev = NULL;
    stack->down->next = NULL;
    printf("rr%c ", stack->name);

    operations += 1;



}

void *ps_rotate(t_dbll_lst *stack)
{
    tt_node *tmp;

    // TODO
    if (stack->size <= 1)
        return 0;

    tmp = stack->top;
    stack->top = stack->top->next;
    stack->post_top = stack->top->next;
    tmp->prev = stack->down;
    stack->down->next = tmp;
    stack->down = tmp;
    stack->top->prev = NULL;
    stack->down->next = NULL;
    printf("r%c ", stack->name);

    operations += 1;

}

void    ft_print_stacks(t_dbll_lst *stack_1, t_dbll_lst *stack_2)
{
    tt_node *node;
    int i;

    i = 1;

//    if (!stack_1 || !stack_2)
//        return ;
    node = stack_1->top;

    printf("\nSTACK B:\n");
    if (stack_1->top->data != 0)
    {
        while (i++ <= stack_1->size)
        {
            printf("%d  ", node->data);
            node = node->next;
        }
        printf("\n");
    }
    else
        printf("\n");
    i = 1;


    node = stack_2->top;
//    printf("\ntop A: %d\n", node->data);
//    printf("\nsize A: %d\n", stack_2->size);

    printf("STACK A:\n");
    if (stack_2) {
        while (i++ <= stack_2->size) {
            printf("%d  ", node->data);
            node = node->next;
        }
    }
    printf("\n");
}



int     *check_sort(t_dbll_lst *stack, int is_rise)
{
    int i;
    tt_node *node_first;
    tt_node *node_second;

    i = 1;

//    stack->is_sorted = 1;
    node_first = stack->top;
    node_second = stack->post_top;

    while (i++ < stack->size)
    {
        if (!is_rise)
        {
            if (node_first->data < node_second->data)
                if (!is_rise)
                    return (0);
            node_first = node_first->next;
            node_second = node_second->next;
        }
        else
        {
            if (node_first->data > node_second->data)
                return (0);
            node_first = node_first->next;
            node_second = node_second->next;
        }
    }
     return (1);
}


int     check_over_value(t_dbll_lst *stack, int value)
{
    int result;
    tt_node *node;

    result = 0;

    node = stack->top;
    while (node)
    {
        if (node->data > value)
            result++;
        node = node->next;
    }
    if (result == stack->size)
        return (1);
    else if (result >= 1)
        return (-1);
    else
        return (0);
}



int find_max(t_dbll_lst *stack)
{
    int max;
    tt_node *node;

    node = stack->top;
    max = node->data;

    while (node >= stack->median)
    {
        if (node->data > max)
            max = node->data;
        node = node->next;
    }
    return (max);
}


int get_ptr_min(int *array, int len_array)
{
    int pointer;
    int i;
    int min;

    i = -1;
    min = MAX_INT;
    while (++i < len_array)
    {
        if (array[i] < min)
        {
            min = array[i];
            pointer = i;
//            i++;
        }
    }

    return (pointer);

}


void ft_mark_pos(t_dbll_lst *chain, int *array_data)
{
    tt_node *node;
    int *array_values;
    int pos;
    int i;
    int j;

    pos = 0;
    i = 0;
    array_values = array_data;

    while (++pos < chain->size + 1)
    {
        node = chain->top;
        j = get_ptr_min(array_values, chain->size);
        array_values[j] = MAX_INT;
        while (j-- > 0)
            node = node->next;
//        printf("CHECK VAL: %d\n", node->data);
        node->position = pos;
//        printf("CHECK POS: %d\n\n", node->position);
    }
}




//void ft_sort(t_dbll_lst *stack, t_dbll_lst *stack_addit)
//{
//
//    ps_push(stack_addit, stack);
//
//    if (stack->top->data == find_max(stack_addit))
//        ps_swap(stack);
//    else if
//
//
//    if (stack->top->data > stack->post_top->data)
//        ps_swap(stack);
//    else if (stack->)
//}



void ft_sort_stack_rise(t_dbll_lst *stack, t_dbll_lst *stack_addit)
{
    if (stack->top->data > stack->down->data)
        ps_rotate(stack);
    else if (stack->top->data > stack->post_top->data)
        ps_swap(stack);
    else if (stack->down->data < stack->top->data)
        ps_revrotate(stack);
    else
    {
        ps_push(stack, stack_addit);
        if (stack->top->data > stack->down->data)
            ps_rotate(stack);
        else if (stack_addit->top->data < stack_addit->post_top->data)
            ps_swap(stack_addit);
        else if (stack->top->data > stack->post_top->data)
            ps_swap(stack);
        else if (stack->top->data < stack_addit->top->data)
            ps_push(stack_addit, stack);
        else
            return ;
    }
}


void ft_sort_stack_low(t_dbll_lst *stack, t_dbll_lst *stack_addit)
{
    if (check_sort(stack, 0))
        return ;
//    if (stack->size <= 2)
//        return;


    if (stack->top->data < stack->down->data)
        ps_rotate(stack);
    if (stack->top->data < stack->post_top->data)
        ps_swap(stack);
    if (stack->down->data > stack->top->data)
        ps_revrotate(stack);
    else
    {
        ps_push(stack, stack_addit);

        if (stack->top->data < stack->down->data)
            ps_rotate(stack);
        if (stack_addit->top->data > stack_addit->post_top->data)
            ps_swap(stack_addit);
        if (stack->top->data < stack->post_top->data)
            ps_swap(stack);
        if (stack->top->data > stack_addit->top->data)
            ps_push(stack_addit, stack);
        else
            return ;

    }




//    else
//    {
//        while (1)
//        {
//            if (stack->top->data < stack->down->data)
//                ps_rotate(stack);
//            else if (stack->top->data < stack->post_top->data)
//                ps_swap(stack);
//            else if (stack->down->data > stack->top->data)
//                ps_revrotate(stack);
//            else
//            {
//                ps_push(stack, stack_addit);
//
//                if (stack->top->data < stack->down->data)
//                    ps_rotate(stack);
//                else if (stack_addit->top->data > stack_addit->post_top->data)
//                    ps_swap(stack_addit);
//                else if (stack->top->data < stack->post_top->data)
//                    ps_swap(stack);
//                else if (stack->top->data > stack_addit->top->data)
//                    ps_push(stack_addit, stack);
//                else
//                    return ;
//            }

    //        else
    //        {
    //            if (check_sort(stack, 0))
    //                return (0);

    //            ps_push(stack, stack_addit);

    //            if (stack->top->data < stack->down->data)
    //                ps_rotate(stack);
    //            if (stack_addit->top->data > stack_addit->post_top->data)
    //                ps_swap(stack_addit);
    //            if (stack->top->data < stack->post_top->data)
    //                ps_swap(stack);
    //            if (stack->top->data > stack_addit->top->data)
    //                ps_push(stack_addit, stack);

    //                printf("CHECK");
//        }
//    }
}


void split_chain(t_dbll_lst *stack_a, t_dbll_lst *stack_b)
{
    int i;
    int bound_top;
    int bound_down;

    i = stack_a->size;
    bound_top = (stack_a->max + stack_b->min) / 3 * 2;
    bound_down = (stack_a->max + stack_b->min) / 3;

    printf("NEW BOUNDS: %d, %d\n", bound_top, bound_down);

    while (i-- > 0)
    {
        if (stack_a->top->data > bound_top)
            ps_rotate(stack_a);
        else if (stack_a->top->data < bound_down)
        {
            ps_push(stack_a, stack_b);
            ps_rotate(stack_b);
        }
        else
            ps_push(stack_a, stack_b);
    }
}



void   split_chain_to_4_part(t_dbll_lst *stack_a, t_dbll_lst *stack_b)
{
    int i;

    i = stack_a->size;

    while (i-- > 0)
//    while (check_over_value(stack_a, stack_a->median) != 1)
    {
        if (stack_a->top->data > stack_a->min)
//            || stack_a->top->data > stack_a->down->data)
            ps_rotate(stack_a);
        else if (stack_a->top->data < stack_b->min)
        {
            ps_push(stack_a, stack_b);
            ps_rotate(stack_b);
        }
//        else if (stack_b->top->data < stack_b->post_top->data)
//            ps_swap(stack_b);

//        else if (stack_a->top->data > stack_b->median
//            && stack_a->top->data < stack_a->median)
//            ps_push(stack_a, stack_b);
        else
            ps_push(stack_a, stack_b);
    }

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

//
//void ft_sort_stack(t_dbll_lst *stack, t_dbll_lst *stack_addit)
//{
//    if (stack->top->data > stack->post_top->data)
//        ps_swap(stack);
//    if (stack->top->data > stack->down->data)
//        ps_rotate(stack);
//    if (stack->down->data < stack->top->data)
//        ps_revrotate(stack);
//
//    ps_push(stack, stack_addit);
//
//    if (stack_addit->top->data < stack_addit->post_top->data)
//        ps_swap(stack_addit);
//    else
//        return ;
//}


void ft_sort_new(t_dbll_lst *stack, t_dbll_lst *stack_addit)
{
    int new_median;

    new_median = (stack->max - stack->median) / 2;

    ps_push(stack_addit, stack);

    if (stack->top->data < new_median)
        ps_rotate(stack);
    else if (stack->top->data > stack->post_top->data)
        ps_swap(stack);
    else
    {
        ps_push(stack, stack_addit);
        if (stack->top->data > stack->down->data)
            ps_rotate(stack);
        else if (stack_addit->top->data < stack_addit->post_top->data)
            ps_swap(stack_addit);
        else if (stack->top->data > stack->post_top->data)
            ps_swap(stack);
        else if (stack->top->data < stack_addit->top->data)
            ps_push(stack_addit, stack);
        else
            return ;

    }

}

int ft_find_max_position(t_dbll_lst *stack)
{
    tt_node *node_1;
    tt_node *node_2;
    int position;

    node_1 = stack->down;
    node_2 = node_1->prev;
    position = node_1->position;

    while (node_1->prev)
    {
        if (node_1->position - node_2->position == 1)
            position = node_2->position;
        node_1 = node_2;
        node_2 = node_1->prev;
    }
//    printf("\nMAX_POSITION: %d\n", position);
    return (position);
}

void ft_sort_stack_a(t_dbll_lst *stack_a, t_dbll_lst *stack_b)
{
    int bound;
    int pos;
    tt_node *node;

    bound = (stack_a->max + stack_a->median) / 2;



    while (stack_a->down->data != stack_a->max)
//            || stack_a->top->position != ft_find_max_position(stack_a) - 1)
    {
        if (stack_a->top->data < bound)
            ps_push(stack_a, stack_b);
        else
            ps_rotate(stack_a);
    }
    pos = ft_find_max_position(stack_a);
    printf("\nPOS: %d\nBOUND: %d\n", pos, bound);

    while (stack_a->top->position != pos - 1)
    {
        if (stack_a->top->data < bound)
            ps_push(stack_a, stack_b);
        else
            ps_rotate(stack_a);
    }
    printf("TOP POSITION: %d\n", stack_a->top->position);

}


void ft_sort(t_dbll_lst *stack_target, t_dbll_lst *stack_sourse)
{
    int next_position;
    tt_node *node;
    int count;

    next_position = ft_find_max_position(stack_target) - 1;
    node = stack_sourse->top;
    count = 0;

    if (stack_target->top->data < stack_sourse->top->data)
        ps_push(stack_target, stack_sourse);

//    if (stack_sourse->top->data < stack_sourse->post_top->data)
//        ps_swap(stack_sourse);
//
//    if (stack_target->top->position - stack_target->post_top->position != -1)
//        printf("DIFF: %d\n", stack_target->top->position - stack_target->post_top->position);
//        ps_push(stack_target, stack_sourse);
//
//    while (node->position != next_position)
//    {
//        ps_rotate(stack_sourse);
//        if (stack_sourse->top->data < stack_sourse->post_top->data)
//            ps_swap(stack_sourse);
//        node = stack_sourse->top;
//    }

    while (node->position != next_position)
    {
        count++;
        node = node->next;
    }
    node = stack_sourse->top;
    if (count > stack_sourse->size / 2)
        while (stack_sourse->top->position != next_position)
            ps_revrotate(stack_sourse);
    else
        while (stack_sourse->top->position != next_position)
            ps_rotate(stack_sourse);




    if (stack_target->top->position - stack_sourse->top->position == 1)
        ps_push(stack_sourse, stack_target);






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
    int array_bounds[3];
    t_dbll_lst *stack_for_max_a;
    t_dbll_lst *stack_for_min_b;
    tt_node *node;  // TEMP

    i = 0;

    while (i < ac-1)
    {
        if (ft_atoi(av[i+1]) == 0)
            if (ft_strlen(av[i+1]) != 1 || !ft_strchr(av[i+1], '0'))
            {
                ft_putstr("Error\n");
                return (0);
            }
        array_data[i] = ft_atoi(av[i+1]);
//        printf("-%d- ", array_data[i]);
        i++;
    }
    array_data[i] = '\0';
    ft_printf("\n");

    i = 0;

    while (i < 3)
    {
        array_bounds[i] = ft_bound(array_data, ac-1, 3-i);
//        printf("ARRAY BOUNDS %d: -%d-\n", i, array_bounds[i]);
        i++;
    }

    stack_for_max_a = ft_mark_stack(array_data, ac - 1, 1);
    stack_for_min_b = ft_mark_stack(array_data, ac - 1, -1);
    stack_for_max_a->name = 'a';
    stack_for_min_b->name = 'b';
    stack_for_max_a = input_chain(ac, av, stack_for_max_a);
    ft_mark_pos(stack_for_max_a, array_data);

//    printf("CHECK GET POINTER: %d\n", get_ptr_min(array_data, 100));

//    printf("median A: %d\n", stack_for_max_a->median);
//    printf("top A: %d\n", stack_for_max_a->)
//
    if (stack_for_max_a->top->data > stack_for_max_a->median)
        ps_rotate(stack_for_max_a);
    else
        ps_push(stack_for_max_a, stack_for_min_b);


    i = 0;

//    if (stack_for_max_a->size > SIMPLE_MAX_SIZE)
//        split_chain_to_4_part(stack_for_max_a, stack_for_min_b);

    split_chain(stack_for_max_a, stack_for_min_b);

    while (!check_sort(stack_for_max_a, 1))
        ft_sort_stack_rise(stack_for_max_a, stack_for_min_b);
//
//
//    ft_find_max_position(stack_for_max_a);
//    i = 0;
//
//
    while (stack_for_min_b->size != 1)
        ft_sort(stack_for_max_a, stack_for_min_b);


//    ft_sort_stack_a(stack_for_max_a, stack_for_min_b);


    ft_print_stacks(stack_for_min_b, stack_for_max_a);


    printf("\nOPERATIONS: %d\n", operations);



    // 44 79 85 73 33 19 1 23 76 40 83 5
    // 0 9 1 8 2

    // 358 162 325 447 363 49 283 80 25 3 474 254 239 191 96 216 458 277 317 94 425 372 5 305 412 413 301 238 322 442 497 121 311 140 379 386 226 207 351 417 430 246 228 460 48 122 233 406 221 486 256 342 444 343 367 172 165 218 67 445 365 285 296 52 177 196 103 303 350 31 133 302 240 471 307 202 92 457 456 9 269 153 82 272 139 21 292 362 15 393 481 328 245 396 465 399 308 400 424 242 287 29 145 357 475 410 467 482 113 68 244 495 99 361 78 275 377 250 284 366 10 219 491 411 1 117 2 88 478 253 483 159 213 459 26 4 326 288 409 231 270 378 215 476 106 199 405 469 319 298 271 151 114 6 171 395 200 462 258 431 146 102 274 369 23 20 105 276 83 321 150 85 12 354 416 28 472 178 71 282 320 434 470 24 401 64 160 45 148 352 220 237 473 187 500 433 388 324 286 428 84 414 195 479 299 293 109 63 496 138 394 163 429 494 316 69 51 341 198 262 337 118 263 449 149 257 91 70 404 265 101 37 179 81 480 336 340 484 488 217 330 448 212 290 329 43 126 194 134 295 273 243 382 402 229 87 127 182 227 119 53 176 57 185 381 356 415 346 376 289 490 40 13 332 327 345 41 339 30 123 499 291 60 397 107 131 279 408 11 206 75 112 353 384 249 222 44 387 132 260 115 375 432 487 334 464 142 335 259 154 173 264 247 450 280 8 19 90 66 184 192 97 210 156 407 380 331 304 349 95 498 422 111 360 79 252 130 93 55 315 180 453 297 248 310 355 65 58 186 373 368 348 418 314 224 157 181 14 268 35 211 455 59 38 164 190 143 61 208 137 390 136 47 477 169 204 73 426 34 385 306 389 234 76 294 437 383 323 440 266 241 267 392 77 175 318 251 108 18 170 166 100 205 230 281 344 22 374 135 338 451 492 347 278 203 16 147 370 158 446 420 188 489 183 54 174 62 312 110 452 161 56 50 89 359 438 232 463 443 124 313 104 46 98 120 371 333 261 189 125 235 427 128 485 116 466 436 17 36 364 72 403 201 86 152 214 197 74 39 309 42 33 141 419 300 168 27 454 435 167 439 441 236 468 144 461 493 225 32 391 398 129 223 7 421 209 255 423 193 155


    // 44 79 85 73 33 19 1 23 76 40 83 39 100 51 58 12 41 67 72 77 9 92 97 91 11 96 34 57 43 95 26 13 24 62 32 69 52 47 54 20 89 94 70 66 74 37 15 22 63 38 93 84 98 55 80 42 50 82 75 78 61 7 81 35 6 87 8 71 18 99 14 45 68 53 5 90 4 21 2 48 27 16 64 65 31 28 3 86 30 25 59 56 60 17 36 10 29 88 46 49
}
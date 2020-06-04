//
// Created by Valeria on 02.06.2020.
//

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct          ss_list
{
    //signed long
    int data;
    size_t data_size;
    struct ss_lst *prev;
    struct ss_lst *next;
}                       tt_node;

typedef struct s_dbll_lst
{
    size_t size;
    int min;
    int max;
    int median;
    tt_node *top;
    tt_node *post_top;
    tt_node *pre_down;
    tt_node *down;
}               t_dbll_lst;

#endif //PUSH_SWAP_2_PUSH_SWAP_H

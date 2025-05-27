#ifndef BinariesTree_INCLUDED
#define MI_HEADER_INCLUDED

#include <stdlib.h>
#include <stdio.h>

#define BTREE_ELEM int
typedef struct _btn
{
    BTREE_ELEM data;
    struct _btn* left;
    struct _btn* right;
}btn;

btn* nbt_newnode(BTREE_ELEM value);
void nbt_deletenode(btn**node);
btn** btn_search(btn** root, BTREE_ELEM value);
int btn_isleaf(btn* node);
int btn_count_nodes(btn* root);

/*
BT* new_node_BT(t_elem_BT value);
t_elem_BT get_value(BT* t);
void destroy_BT(BT** node);
int cmp(t_elem_BT v1,t_elem_BT v2);
BT** find (BT** node, t_elem_BT data, int cmp(t_elem_BT, t_elem_BT));
BT* rmv(BT** node, t_elem_BT data, int cmp(t_elem_BT, t_elem_BT));
void add_value(BT** t, t_elem_BT new_value);
int is_abb_t(BT* root, int liminf, int limsup);
int is_abb(BT*root);
int btn_level_t(BT* root, t_elem_BT value, int level);
int btn_level(BT* root, t_elem_BT data);
int btn_max_level(BT* root, int level);
int btn_max_level_2(BT* root, int level);
int isAVL(BT* node);
*/
#endif
#ifndef BinariesTree_INCLUDED
#define MI_HEADER_INCLUDED

#include <stdlib.h>
#include <stdio.h>

#define t_elem_BT int
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
int is_AVL(BT* node);

#endif
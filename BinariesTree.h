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

btn* btn_newnode(BTREE_ELEM value);
void btn_deletenode(btn**node);
btn** btn_search_value(btn** root, BTREE_ELEM value);
btn** btn_search_node(btn** root, btn* value);
int btn_isleaf(btn* node);
int btn_count_nodes(btn* root);
void add_node_bt(btn**root,btn* new_node);
void add_value_bt(btn**root, BTREE_ELEM value);
int btn_profundidad(btn*root,BTREE_ELEM destiny, int count);
int btn_altura(btn* root);
int cmp_btn(BTREE_ELEM v1, BTREE_ELEM v2);
void bst_add_node(btn**root,btn* node,int cmp_btn(BTREE_ELEM,BTREE_ELEM));
int is_bst(btn* root, int inf_limit, int high_limit);
btn** bst_getmin_node(btn**root);
btn** bst_getmax_node(btn**root);
btn** bst_searchvalue_interative(btn**root,BTREE_ELEM value);
btn** bst_searchvalue_recursive(btn**root,BTREE_ELEM value);
int bst_check_value(btn*root,BTREE_ELEM value);

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
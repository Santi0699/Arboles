#include "BinariesTree.h"

typedef struct _BT
{
    t_elem_BT data;
    struct _BT* left;
    struct _BT* right;
}BT;

BT* new_node_BT(t_elem_BT value)
{
    BT* result= (BT*)malloc(sizeof(BT));

    if(result != NULL)
    {
        result->data=value;
        result->left=NULL;
        result->right=NULL;
    }

    return result;
}

t_elem_BT get_value(BT* t)
{
    return t->data;
}

void destroy_BT(BT** node)
{   
    if (node == NULL || *node == NULL) return;

    destroy_BT(&((*node)->left));
    destroy_BT(&((*node)->right));

    free(*node);  // libera el nodo actual
    *node = NULL; // evita dejar punteros colgando
}

int cmp(t_elem_BT v1,t_elem_BT v2)
{
    int r=0;
    if(v1==v2)
    {
        r=1;
    }
    return r;
}

BT** find (BT** node, t_elem_BT data, int cmp(t_elem_BT, t_elem_BT)) 
{
    while ((*node != NULL) && (cmp((*node)->data, data) != 0)) 
    {
        if (cmp(data, (*node)->data) < 0)
        {
         
              node = &(*node)->left;
        }else{
            node = &(*node)->right;
        }         
    }
    return node;
}

BT* rmv(BT** node, t_elem_BT data, int cmp(t_elem_BT, t_elem_BT)) 
{
    BT* res = NULL;
    BT** found = find(node, data, cmp);
    if (*found != NULL) 
    {
        res = *found;
        add (&(*found)->left, (*found)->right, cmp);
        *found = (*found)->left;
        res->left = NULL;
        res->right = NULL;                
    }
    return res;
}


void add_value(BT** t, t_elem_BT new_value)
{
    if(*t==NULL) 
    {
        *t=new_value;
        return;
    }

    if(get_value(new_value)<get_value(*t))
    {
        if((*t)->left==NULL)
        {
            (*t)->left=new_value;
        }else{
            add_value(&(*t)->left,new_value);
        }
    }else if(get_value(new_value)>value_get_value((*t)))
        {
            if((*t)->right==NULL)
            {
                (*t)->right=new_value;
            }else{
                add_value(&(*t)->right,new_value);
            }
        }
}

int is_abb_t(BT* root, int liminf, int limsup)
{   
    int r=1;
    if(root!=NULL)
    {
        if(root->data < limsup && root->data > limsup)
        {
            r=is_abb_t(root->left,liminf,root->data) && is_abb_t(root->left,root->data,limsup);
        }else{
            r=0;
        }
    }

    return r;
}

int is_abb(BT*root)
{
    return is_abb_t(root,-999,999);
}

int btn_level_t(BT* root, t_elem_BT value, int level)
{
    
    int r=0;

    if(root!=NULL)
    {
        if(root->data==value)
        {
            r=level;
        }else
            {
                r=btn_level_t(root->left,value,level+1);
                if(r==0)
                {
                    r=level_t(root->right,value,level+1);
                }
            }
    }
    
    return r;
}

int btn_level(BT* root, t_elem_BT data)
{
    return btn_level_t(root,data,0);
}

int btn_max_level(BT* root, int level)
{
    int r=0;

    if(root!=NULL)
    {   

        int r_left=btn_max_level(root->left,level+1);
        int r_right=btn_max_level(root->right,level+1);
        if(r_left<r_right)
        {
            r=r_left;
        }else{
            r=r_right;
        }
    }else{
        r=level-1;
    }
    
    return r;
}

int btn_max_level_2(BT* root, int level)
{
    int r=0;

    if(root!=NULL)
    {   

        int r_left=btn_max_level(root->left,level+1);
        int r_right=btn_max_level(root->right,level+1);
        if(r_left<r_right)
        {
            r=r_left;
        }else{
            r=r_right;
        }
    }
    
    if(root->left==NULL && root->right==NULL)
    {
       return level;
    }

    return r;
}

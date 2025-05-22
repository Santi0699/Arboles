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

int is_a_leaf(BT* root)
{
    int r=0;
    if(root != NULL)
    {
        if(root->left == NULL && root->right==NULL)
        {
            r=1;
        }
    }
    return r;
}

int count_nodes_t(BT* root)
{
    return (root!=NULL)? 1+count_nodes_t(root->left)+count_nodes_t(root->right):0;
}

void add_node_bt(BT**root,BT* new_node)
{
        if((*root)->left==NULL)
        {
            (*root)->left=new_node;
            return;
        }
        if((*root)->right==NULL)
        {
            (*root)->right=new_node;
            return;
        }

        int count_left=count_nodes_t((*root)->left);
        int count_right=count_nodes_t((*root)->right);
    
        if(count_left<=count_right)
        {
            add_node_bt(&(*root)->left,new_node);    
        }else{
            add_node_bt(&(*root)->right,new_node);
        }
}

void add_value_bt(BT**root,t_elem_BT value)
{
        BT* new_node=new_node_BT(value);
        if((*root)->left==NULL)
        {
            (*root)->left=new_node;
            return;
        }
        if((*root)->right==NULL)
        {
            (*root)->right=new_node;
            return;
        }

        
        int count_left=count_nodes_t((*root)->left);
        int count_right=count_nodes_t((*root)->right);
    
        if(count_left<=count_right)
        {
            add_value_bt(&(*root)->left,value);    
        }else{
            add_value_bt(&(*root)->right,value);
        }
}


int balanceFactor(BT *node)
{
    int result = 0;
    if (node != NULL) {
        result = height(node->left) - height(node->right); 
    }
    return result;
}


int isAVL(BT *node)
{
    if (node == NULL) return 1;
    int result = 0; 

    if (abs(balanceFactor(node))<2) {
        if (isAVL(node->left)){
            result = isAVL(node->right);
        } 
    }

    return result;    
}

int leftRotation (BT **node){
    if (node == NULL) return 0;
    if (*node == NULL) return 0;
    if ((*node)->right == NULL) return 0;
    
    BT *aux = (*node)->right;
    (*node)->right = aux->left;
    aux->left = *node; 
    *node = aux;
    
    return 1; 
}

int rightRotation (BT **node){
    if (node == NULL) return 0;
    if (*node == NULL) return 0;
    if ((*node)->left == NULL) return 0;    

    BT *aux = (*node)->left;
    (*node)->left = aux->right;
    aux->right = *node; 
    *node = aux;
    
    return 1; 
}

int balance (BT **node){
    if (node == NULL) return 0;
    if (*node == NULL) return 0; 

    int bf = balanceFactor(*node); 

    if (bf <= -2) {
        if (balanceFactor((*node)->right) >0) {
            rightRotation(&(*node)->right);
        }
        leftRotation(node); 

    } else if (bf >= 2) {
        if (balanceFactor((*node)->left) <0) {
            leftRotation(&(*node)->left);
        }
        rightRotation(node); 
    }

    if (abs(balanceFactor(*node)) > 1){
        balance (node); 
    }
    
    return 1;
}

int insertNode(BT **node, BT *new) {
    if (node == NULL) return 0;
    if (new == NULL) return 1;

    if ((*node) == NULL) {
        *node = new;
        return 1;
    } else {
        if ((*node)->data > new->data) {            
            return insertNode(&(*node)->left, new);

        } else if ((*node)->data < new->data) {            
            return insertNode(&(*node)->right, new);

        } else {
            return 0;
        }
    }
}

int insertAVL (BT **node, int value) {
    
    BT *new = create(value);
          if (!insertNode(node, new)) {            
              free(new); //Duplicado
          } else {
              balanceTree (node); 
          };
  
  }
  

BT *removeNode(BT **node) {
    if (!node) return NULL;
    if (!(*node)) return NULL;

    BT *aux = *node;

    insertNode(&(aux->right), (aux->left));
    *node = aux->right;
    aux->left = NULL;
    aux->right = NULL;

    return aux;
}

int removeAVL (BT **node, int value){ 

    BT *deleted = NULL;
    BT **toDel = NULL; 
          toDel = findPtr(value, node);         
          deleted = removeNode(toDel);
          if (deleted != NULL) {            
                balanceTree (node); 
            };
}
    

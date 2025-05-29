#include "BinariesTree.h"

//1.a Crear un nodo de un BT en base a un valor BTREE_ELEM
btn* btn_newnode(BTREE_ELEM value)
{
    btn* new = (btn*)malloc(sizeof(btn));

    if(new!=NULL)
    {
        new->data=value;
        new->left=NULL;
        new->right=NULL;
    }

    return new;

}
//b. Eliminar un nodo, si tiene hijos elimina sus hijos también.
void btn_deletenode(btn**node)
{
    if((*node)!=NULL)
    {
        (*node)->left=NULL;
        (*node)->right=NULL;
    }
    free(node);
}

/*c.Buscar un nodo con un determinado elemento y devolver su referencia. Se busca el nodo en
pre-order (debe recorrer todo el árbol cuando no hay un criterio de ordenamiento). Debe
devolver la referencia a la ubicación del puntero al nodo. Si no existe, devuelve NULL*/

/*Siempre que tenga que buscar algo y lo haga recursivo en arboles tengo que primero recorrer toda una rama,
si por ese lado no se encuentra voy por el otro lado. pero siempre verificando de ante mano si el valor es el buscado,
el ejercicio cambiaria si se me pide buscar si el elemento esta en una hoja, para eso lo tendria que hacer una funcion
que indentifique si el nodo es una hoja o no*/

btn** btn_search_value(btn** root, BTREE_ELEM value)
{   
    btn** result=NULL;

    if(*root!=NULL)
    {
        if((*root)->data==value)
        {
            result=&(*root);
        }else{
            result = btn_search_value(&(*root)->left, value);
            // Si no lo encontró, buscar en el subárbol derecho
            if (result == NULL)
            {
                result = btn_search_value(&(*root)->right, value);
            }
        }
        
    }

    return result;
}

btn** btn_search_node(btn** root, btn* value)
{   
    btn** result=NULL;

    if(*root!=NULL)
    {
        if((*root)==value)
        {
            result=&(*root);
        }else{
            result = btn_search_node(&(*root)->left, value);
            // Si no lo encontró, buscar en el subárbol derecho
            if (result == NULL)
            {
                result = btn_search_node(&(*root)->right, value);
            }
        }
        
    }

    return result;
}

/*d. Hacer una función que reciba un nodo y devuelva 1 si es hoja y 0 si no lo es. */
int btn_isleaf(btn* node)
{
    int res=0;
    if(node!=NULL)
    {
        if(node->left==NULL && node->right==NULL)
        {
            res=1;
        }
    }
    return res;
}

/*e. Contar la cantidad de nodos*/

int btn_count_nodes(btn* root)
{
    int result=0;
    if(root!=NULL)
    {
        result=1+btn_count_nodes(root->left)+btn_count_nodes(root->right);
    }
    
    return result;
}

/*Agrega un nodo en un árbol binario con el siguiente criterio:
Si el subárbol es nulo se agrega ahí,
Si no es NULL lo agrega en el hijo con menor cantidad de nodos,
Si sus hijos tienen la misma cantidad de nodos lo agrega a la izquierda.
*/

void add_node_bt(btn**root,btn* new_node)
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

        int count_left=btn_count_nodes((*root)->left);
        int count_right=btn_count_nodes((*root)->right);
    
        if(count_left<=count_right)
        {
            add_node_bt(&(*root)->left,new_node);    
        }else{
            add_node_bt(&(*root)->right,new_node);
        }
}

/*g. Agregar un dato a un árbol con el mismo criterio.*/
void add_value_bt(btn**root, BTREE_ELEM value)
{
    btn* new=btn_newnode(value);
    add_node_bt(root,new);
}

/*h. Devolver la profundidad de un nodo. La profundidad de un nodo es 1 más la profundidad de su padre. 
Considerar 0 (cero) la profundidad de la raíz.*/

int btn_profundidad(btn*root,BTREE_ELEM destiny, int count)
{
    if(root==NULL)return -1;

    if(root->data==destiny)
    {
        return count;
    }

    int left=btn_profundidad(root->left,destiny,count+1);
    if(left==-1)
    {
        return left;
    }

    return btn_profundidad(root->right, destiny, count+1);
}

/*i.Devolver la altura de un BTN. La altura es la distancia de la hoja más profunda. 
Cuando el nodo es NULL devuelve -1, la altura de las hojas es 0.*/

int btn_altura(btn* root)
{
    if(root==NULL)return -1;

    if(btn_isleaf(root))return 0;

    int izquierda=btn_altura(root->left);
    int derecha=btn_altura(root->right);
    return 1+((izquierda > derecha)? izquierda:derecha);
}

/*Armar una función para cada tipo de recorrido del árbol (Inorder, postorder, preorder), 
asumiendo que el elemento del árbol es un puntero a string. */

/*2.a Agrega un nodo (btn*) a un árbol binario de búsqueda (BST), de modo que no acepte valores repetidos. 
Utilizar una función cmp pasada como parámetro que permita comparar el valor de dos BTREE_ELEM. 
En el main agregar varios valores e imprimir el árbol.*/

int cmp_btn(BTREE_ELEM v1, BTREE_ELEM v2)
{
    int res=v1-v2;
    return res;
}

void bst_add_node(btn**root,btn* node,int cmp_btn(BTREE_ELEM,BTREE_ELEM))
{
    if(*root==NULL)
    {
        (*root)=node;
        return;
    } 
    if(cmp_btn((*root)->data,node->data)==0)return;
    if(cmp_btn((*root)->data,node->data)>0 && (*root)->left==NULL)
    {
        (*root)->left=node;
        return;
    }else if(cmp_btn((*root)->data,node->data)<0 && (*root)->right==NULL)
    {
        (*root)->right=node;
        return;
    }
    
    if(cmp_btn((*root)->data,node->data)>0)
    {
        bst_add_node(&(*root)->left,node,cmp_btn);
    }else if(cmp_btn((*root)->data,node->data)<0)
        {
            bst_add_node(&(*root)->right,node,cmp_btn);
        }

}

/*b. Verificar si un árbol binario (BT) es un árbol binario de búsqueda (BST). */
int is_bst(btn* root, int inf_limit, int high_limit)
{
    int result=1;
    if(root!=NULL && result==1)
    {
        if(root->data > inf_limit && root->data < high_limit)
        {
            result=is_bst(root->left,inf_limit,root->data)&&is_bst(root->right,root->data,high_limit);
        }else{
            result=0;
        }
        
    }
    return result;
}

/*c. Obtener el puntero que contiene el puntero al nodo con el valor mínimo de un BST. 
¿Es necesario enviar una función de comparación? ¿Por qué?*/
btn** bst_getmin_node(btn**root)
{
    if((*root)==NULL)return NULL;
    if((*root)->left==NULL)return root;

    return bst_getmin_node(&(*root)->left);
}

/*d. Obtener el puntero que contiene el puntero al nodo con el valor máximo de un BST.*/
btn** bst_getmax_node(btn**root)
{
    if((*root)==NULL)return NULL;
    if((*root)->right==NULL)return root;

    return bst_getmax_node(&(*root)->right);
}

/*e. Obtener el puntero del puntero al nodo con el valor solicitado de un BST. 
Debe utilizar una función de comparación pasada por parámetro. Resolver en forma iterativa y recursiva.*/

btn** bst_searchvalue_interative(btn**root,BTREE_ELEM value)
{
    btn** node= root;
    while(*node!=NULL && (*node)->data!=value)
    {
        if((*node)->left!=NULL && value < (*node)->data)
        {
            node=&(*node)->left;
        }else if((*node)->right!=NULL && value > (*node)->data)
        {
            node=&(*node)->right;
        }
    }

    return node;
}

btn** bst_searchvalue_recursive(btn**root,BTREE_ELEM value)
{
    if((*root)==NULL) return NULL;
    if((*root)->data==value)return root;
    btn** node= root;
    
    btn** result=NULL;
    if(value<(*node)->data)
    {
        result=bst_searchvalue_recursive(&(*root)->left,value);
    }else{
        result=bst_searchvalue_recursive(&(*root)->right,value);
    }

    return result;
}

/*f. Hacer una función que devuelva 1 si un valor se encuentra en el BST, o 0 en otro caso.*/

int bst_check_value(btn*root,BTREE_ELEM value)
{
    if(root==NULL) return -1;
    if(root->data==value)return 1;
    
    int result=0;
    if(value<root->data)
    {
        result=bst_searchvalue_recursive(root->left,value);
    }else{
        result=bst_searchvalue_recursive(root->right,value);
    }

    return result;
}

/*Funciones de rotar nodos*/
int height(btn *node){
    int result = -1; 
    if (node != NULL) {
        result = max(height(node->left), height(node->right)) +1; 
    }
    return result;    
}

int balanceFactor(btn *node){
    int result = 0;
    if (node != NULL) {
        result = height(node->left) - height(node->right); 
    }
    return result;
}

int isAVL(btn *node){
    if (node == NULL) return 1;
    int result = 0; 

    if (abs(balanceFactor(node))<2) {
        if (isAVL(node->left)){
            result = isAVL(node->right);
        } 
    }

    return result;    
}

void bst_left_rotation(btn**root)
{
    btn* aux= (*root);
    btn* aux2= (aux)->right;
    (*root)=aux2;
    aux->right=aux2->left;
    (*root)->left=aux;

}

void bst_right_rotation(btn**root)
{
    btn* aux= (*root);
    btn* aux2= (aux)->right;
    (*root)=aux2;
    aux->right=aux2->left;
    (*root)->left=aux;

}


/*g. Quitar un nodo de un BST, reemplazando el nodo por su rama Derecha y agregando la rama 
Izquierda a la rama derecha.*/
void bst_remove_node(btn** root, BTREE_ELEM value)
{
    btn** aux1=bst_searchvalue_recursive(root,value);

    btn* aux2= *aux1;
    btn* aux_L= aux2->left;
    btn* aux_R= aux2->right;

    if(aux_R==NULL)
    {
        *aux1=aux_L;
    }else{
       btn* min=aux_R;
       while(min->left!=NULL)
       {
            min=min->left;
       }
       min->left=aux_L;
       *aux1=aux_R;
    }
    aux2->left = NULL;
    aux2->right = NULL;

}


/*
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

int profundidad(BT* root,int count)
{
    int result=0;
    if(root!=NULL)
    {
        result=count;
        int temp=profundidad(root->left,count+1);
        temp=profundidad(root->right,count+1);
        result=temp;
    }

    return result;
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
    
void print_lvl(BT* root, int lvl)
{
    if (root==NULL) return;
    if(lvl<1)return;

    if(lvl==1)
    {
        printf("%d",root->data);
    }else
        {
            print_lvl(root->left,lvl-1);
            print_lvl(root->right,lvl-1);
        }
}

void create_list_out_of_range_2(BT* root, node** head, int low_range, int high_range)
{
    if (root==NULL)return;

    create_list_out_of_range_2(root->right,head,low_range,high_range);
    if(root->data > high_range)
    {
        add_list_first(&(*head),root->data);
    }else if(root->data < low_range)
        {
            add_list_first(&(*head),root->data);
        }
    create_list_out_of_range_2(root->left,head,low_range,high_range);


}

void BT_add_max(node** list, BT* root,int low_range)
{
    if(!root) return;
    if(root->data > low_range){
        BT_add_max(list,root->right,low_range);
        add_list(list, root->data);
        BT_add_max(list,root->left,low_range);
    }else{
        BT_add_max(list,root->left,low_range);
    }
}

void BT_add_min(node** list, BT* root,int high_range)
{
    if(!root) return;
    if(root->data < high_range){
        BT_add_max(list,root->left,high_range);
        add_list(list, root->data);
        BT_add_max(list,root->right,high_range);
    }else{
        BT_add_max(list,root->right,high_range);
    }
}

void create_list_out_of_range(BT* root, node** head, int low_range, int high_range)
{
    
}
*/
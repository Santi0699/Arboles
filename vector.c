#include "vector.h"

typedef struct _vector{
    
    t_elem_vector* a; //array de T_Elem
    int size; //tam actual
    int maxsize; //tam maximo
}vector;


vector* vector_init(int max)
{
    vector* v = (vector*)malloc(sizeof(vector));
    v->a=(t_elem_vector*)malloc(max*sizeof(t_elem_vector));
    v->size=0;
    v->maxsize=max;
    return v;
}


void vector_free(vector* v)
{
    free(v->a);
    free(v);
}

int vector_size(vector*v)
{
    if (v==NULL) return -1;

    return v->size;
}

int vector_max_size(vector*v)
{
    if (v==NULL) return -1;

    return v->maxsize;
}

int vector_isfull(vector* v)
{
    if (v==NULL) return -1;

    if(v->size==v->maxsize)
    {
        return 1;
    }
    return 0;
}

int vector_isempty(vector* v)
{
    if (v==NULL) return -1;

    if(v->size==0)
    {
        return 1;
    }
    return 0;
}


t_elem_vector vector_get(vector* v, int index)
{
    
//    if(v==NULL)return -1;
//    if(index >= v->maxsize)return -2;
//    if(index<0)return -3;
    return v->a[index];
}

void vector_set(vector* v, int index, t_elem_vector value) 
{
 //   if(v==NULL)return -1;
 //   if(index >= v->maxsize)return -2;
 //   if(index<0)return -3;

    v->a[index]=value;

//    return 0;

}

void vector_add(vector* v, t_elem_vector value)
{
    if(v==NULL)return ;

    if(!vector_isfull(v))
    {
        v->a[v->size] = (t_elem_vector)value;
        v->size++;
    }else{
        v->a = (t_elem_vector*)realloc(v->a,  sizeof(v->a) + (v->maxsize + 1) * sizeof(t_elem_vector));
        v->maxsize = v->maxsize + 1;
        v->a[v->size] = (t_elem_vector)value;
        v->size = v->size + 1;
    }



}

void vector_resize(vector** v)
{
    if(*v==NULL) return;

    //int i=vector_size(*v);

    if(vector_isfull(*v))
    {
        vector* temp = (vector*) realloc(*v, sizeof(vector) + ((*v)->maxsize + 1) * sizeof(int));
        *v=temp;
        (*v)->maxsize=(*v)->maxsize+1;
    

    }
}

t_elem_vector vector_remove(vector*v, int index)
{
    if(v==NULL)return -99999;
    t_elem_vector result=vector_get(v,index);
    for(int i = index; i < v->size - 1; i++)
    {
        v->a[i] = v->a[i + 1];
    }

    v->size--;
    return result;
}
/*
int vector_insert(vector* v, T_Elem value, int index)
{
    if(v==NULL)return -1;
    int dim=vector_size(v);
    if(vector_isfull(v))
    {
        vector_resize(&v);
        for(int j=dim; j>index; j--)
        {
         v->a[j]=v->a[j-1];
        }
    }else{
        for(int i = dim; i>index; i--)
        {
            v->a[i]=v->a[i-1];
        }
        vector_set(v,index,value);
    }



    return 1;

}

int vector_value_pos(vector* v, int index)
{
    if(v==NULL) return -1;
    int i=0;
    vector* aux=v;
    int flag=0;

    while(i!=v->size && flag==0)
    {
        if(aux->a[i]!=v->a[index])
        {
            flag=1;

        }
        i++;
    }

    if(flag)
    {
        return i-1;
    }
    return 0;
}



void vector_print(vector* v, void (*print)(T_Elem)) {
    for (int i = 0; i < v->size; i++) {
        print(v->a[i]); // Se imprime cada elemento usando la función pasada
    }
    printf("\n");
}
*/
void vector_print2(vector* v) {
    for (int i = 0; i < v->size; i++) {
        printf("|%d|", v->a[i]); // Se imprime cada elemento usando la función pasada
    }
    printf("\n");
}

void vector_add_random2(vector* v)
{
    if (v==NULL)return;

    while(!vector_isfull(v))
    {
        int value1=rand()%10;
        vector_add(v,value1);
    }

}

void vector_insert(vector* v, t_elem_vector value, int index)
{
    if (index < 0 || index > v->size) return ;           // Índice fuera de rango
    if (v->size >= v->maxsize) return ;                  // Vector lleno

    // Desplazar elementos hacia la derecha
    for (int i = v->size; i > index; i--) {
        v->a[i] = v->a[i - 1];
    }

    // Insertar el nuevo elemento
    v->a[index] = value;
    v->size++;

}

void vector_insert_order(vector* v, t_elem_vector value)
{  
    if(vector_isempty(v))
    {
       vector_insert(v,value,0); 
    }else{
        int i=0;
        int size=vector_size(v);
        while(i<size && value<vector_get(v,i))
        {
            i++;
        }
        vector_insert(v,value,i);
    }

}
/*
vector* vector_combine_order(vector* v1, vector* v2)
{
    int size1=vector_size(v1);
    int size2=vector_size(v2);
    vector* r=vector_init(size1+size2);
    if(!vector_isempty(v1) && !vector_isempty(v2))
    {
        for(int i=0; i<size1; i++)
        {
            vector_insert_order(r,fraction_new(fraction_num(vector_get(v1,i),fraction_den(vector_get(v1,i)))));
        }
        
        for(int j=0; j<size2; j++)
        {
            vector_insert_order(r,vector_get(v2,j));
        }

    }
    return r;
}
*/
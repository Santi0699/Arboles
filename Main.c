#include "BinariesTree.h"
#include "string.h"
#include "Listas.h"



int main()
{

    btn* nuevo_sbt=btn_newnode(10);
    bst_add_node(&(nuevo_sbt),btn_newnode(20),cmp_btn);
    bst_add_node(&(nuevo_sbt),btn_newnode(15),cmp_btn);
    bst_add_node(&(nuevo_sbt),btn_newnode(25),cmp_btn);
    bst_add_node(&(nuevo_sbt),btn_newnode(4),cmp_btn);
    bst_add_node(&(nuevo_sbt),btn_newnode(3),cmp_btn);
    bst_add_node(&(nuevo_sbt),btn_newnode(17),cmp_btn);
    
    btn* nuevo_sbt2=btn_newnode(12);
    bst_add_node(&(nuevo_sbt2),btn_newnode(20),cmp_btn);
    bst_add_node(&(nuevo_sbt2),btn_newnode(15),cmp_btn);
    bst_add_node(&(nuevo_sbt2),btn_newnode(30),cmp_btn);
    bst_add_node(&(nuevo_sbt2),btn_newnode(4),cmp_btn);
    bst_add_node(&(nuevo_sbt2),btn_newnode(8),cmp_btn);
    bst_add_node(&(nuevo_sbt2),btn_newnode(17),cmp_btn);

   /*
    add_node_bt(&nuevo_sbt,btn_newnode(-10));
    add_node_bt(&nuevo_sbt,btn_newnode(2));
    add_node_bt(&nuevo_sbt,btn_newnode(-30));
    add_node_bt(&nuevo_sbt,btn_newnode(29));
    add_node_bt(&nuevo_sbt,btn_newnode(12));
    add_node_bt(&nuevo_sbt,btn_newnode(19));
    add_node_bt(&nuevo_sbt,btn_newnode(-30));
    add_node_bt(&nuevo_sbt,btn_newnode(1));
    add_node_bt(&nuevo_sbt,btn_newnode(20));
    
    btn* sbt_new=NULL;
    bt_to_bst(&sbt_new,nuevo_sbt,cmp_btn);

    btn_print(nuevo_sbt, toStr);
    puts(" ");
    btn_print(sbt_new, toStr);
    */
    /*
    node* head=node_new(5);
    node_add_first2(&head,node_new(6));
    node_add_first2(&head,node_new(20));
    node_add_first2(&head,node_new(12));
    node_add_first2(&head,node_new(10));
    node_add_first2(&head,node_new(6));
    node_add_first2(&head,node_new(12));
    list_print(head,int_print);
    bst_list_delete_same_values(&head,cmp_btn);
    list_print(head,int_print);
    //bst_remove_node(&(nuevo_sbt),25);
    //btn_print(nuevo_sbt, toStr);
    */
   btn_print(nuevo_sbt, toStr);
   btn_print(nuevo_sbt2, toStr);
    btn* fusion= bst_fusion(&nuevo_sbt,&nuevo_sbt2,cmp_btn);

    //int sum=btn_sum_elem(nuevo_sbt);
    //printf("%d",sum);
    //int res=btn_compare_sum_childs(nuevo_sbt);
    //printf("\n%d",res);
    return 0;
}
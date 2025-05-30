#include "BinariesTree.h"
#include "string.h"



int main()
{

    btn* nuevo_sbt=btn_newnode(10);/*
    bst_add_node(&(nuevo_sbt),btn_newnode(20),cmp_btn);
    bst_add_node(&(nuevo_sbt),btn_newnode(15),cmp_btn);
    bst_add_node(&(nuevo_sbt),btn_newnode(25),cmp_btn);
    bst_add_node(&(nuevo_sbt),btn_newnode(4),cmp_btn);
    bst_add_node(&(nuevo_sbt),btn_newnode(3),cmp_btn);
    bst_add_node(&(nuevo_sbt),btn_newnode(17),cmp_btn);
    */
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
    //bst_remove_node(&(nuevo_sbt),25);
    //btn_print(nuevo_sbt, toStr);

    //int sum=btn_sum_elem(nuevo_sbt);
    //printf("%d",sum);
    //int res=btn_compare_sum_childs(nuevo_sbt);
    //printf("\n%d",res);
    return 0;
}
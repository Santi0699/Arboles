#include "BinariesTree.h"
#include "string.h"

int _btn_print(btn *tree, int is_left, int offset, int depth, char s[20][255], void toStr (btn*, char*)) {
    char b[200];
    int width = 5;

    if (!tree) return 0;
    toStr(tree, b);
    //sprintf(b, "%s", str);
    

    int left = _btn_print(tree->left, 1, offset, depth + 1, s, toStr);
    int right = _btn_print(tree->right, 0, offset + left + width, depth + 1, s, toStr);

    // for (int i = 0; i < width; i++) s[2 * depth][offset + left + i] = b[i];
    for (int i = 0; i < strlen(b); i++) s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {
        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width / 2 + i] = '-';

        s[2 * depth - 1][offset + left + width / 2] = '+';
        s[2 * depth - 1][offset + left + width + right + width / 2] = '+';

    } else if (depth && !is_left) {
        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width / 2 + i] = '-';

        s[2 * depth - 1][offset + left + width / 2] = '+';
        s[2 * depth - 1][offset - width / 2 - 1] = '+';
    }
    
    return left + width + right;
}

/**
 * Dibuja un árbol binario con caracteres
 * (Los datos de los nodos deben enteros entre 0 y 999).
 */
void btn_print(btn *tree, void toStr (btn*, char*)) {
    char s[20][255];
    for (int i = 0; i < 20; i++) sprintf(s[i], "%80s", " ");

    _btn_print(tree, 0, 0, 0, s, toStr);

    for (int i = 0; i < 20; i++) {
        int j = 0;
        while (s[i][j] != '\0' && s[i][j] == ' ') {
            j++;
        }
        if (s[i][j] != '\0') {
            printf("%s\n", s[i]);
        }
    }
}

void btn_intToStr(btn* node, char* str) {
    if (!node) return;    
    sprintf(str, "(%03d)", node->data);    
}

// compara 2 elementos del árbol cuando son enteros
int btn_cmp_int(BTREE_ELEM a, BTREE_ELEM b) {
    return a - b;
}

void toStr(btn* nodo, char* buffer)
{
    sprintf(buffer, "%3d", nodo->data);  // imprime el dato con ancho fijo
}

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
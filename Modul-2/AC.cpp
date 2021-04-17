#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct bstnode_t {
    int key;
    char name[105];
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode* __bst__createNode(int value, char names[105]) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    strcpy(newNode->name, names);
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value, char names[105]) {
    if (root == NULL) 
        return __bst__createNode(value, names);

    if (value < root->key)
        root->left = __bst__insert(root->left, value, names);
    else if (value >= root->key)
        root->right = __bst__insert(root->right, value, names);
    
    return root;
}

int cek = 0, first1 = 1, first2 = 1;

void __bst__inorder(BSTNode *root) {
    if (root) {
        __bst__inorder(root->left);
        if (root->key != cek) {
            if (first1 != 1) {
                printf("\n");
                first2 = 1;
            }
            else {
                first1 = 0;
            }
            printf("Descendant : %d | Name : %s", root->key, root->name);
            cek = root->key;
        }
        else {
            if (first2 == 1) {
                printf(" | Twins :");
                first2 = 0;
            }
            printf(" %s", root->name);
        }
        __bst__inorder(root->right);
    }
}

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

void bst_insert(BST *bst, int value, char names[105]) {
    bst->_root = __bst__insert(bst->_root, value, names);
    bst->_size++;
}

void bst_inorder(BST *bst) {
    __bst__inorder(bst->_root);
}
 
int main()
{
    BST set;
    bst_init(&set);

    char a[105];
    while(scanf("%s", a) != '\n') {
        int sum = 0;
        for (int i=0; i<strlen(a); i++) {
            sum += a[i];
        }
        bst_insert(&set, sum, a);
        char c = getchar();
        if (c == '\n') {
            break;
        }
    }
    bst_inorder(&set);
    printf("\n");
    return 0;
}
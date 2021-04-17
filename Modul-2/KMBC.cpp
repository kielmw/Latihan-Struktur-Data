/**
 * Implementasi Binary Search Tree (ADT: BST)
 * yakni BST yang tidak menyimpan key duplikat (unique key)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 29 Februrari 2019
 * Struktur Data 2020
 * 
 * Implementasi untuk Bahasa C
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * Node structure and
 * uniqueBST structure
 */

int cek;

int isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return 0;
 
    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return 0;
 
    return 1;
}

typedef struct bstnode_t {
    int key;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

/**
 * !!! WARNING UTILITY FUNCTION !!!
 * Recognized by prefix "__bst__"
 * ---------------------------------------------
 * Note that you better never access these functions, 
 * unless you need to modify or you know how these functions work.
 */

BSTNode* __bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL) 
        return __bst__createNode(value);

    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);
    
    return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

void __bst__inorder(BSTNode *root) {
    if (root) {
        __bst__inorder(root->left);
        if (cek == 1) {
            if (root->key % 2 == 0) {
                printf("%d\n", root->key);
            }
        }
        if (cek == 2) {
            if (root->key % 2 != 0) {
                printf("%d\n", root->key);
            }
        }
        if (cek == 3) {
            if (isPrime(root->key)) {
                printf("%d\n", root->key);
            }
        }
        if (cek == 4) {
            printf("%d\n", root->key);
        }
        __bst__inorder(root->right);
    }
}

void __bst__postorder(BSTNode *root) {
    if (root) {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        if (cek == 1) {
            if (root->key % 2 == 0) {
                printf("%d\n", root->key);
            }
        }
        if (cek == 2) {
            if (root->key % 2 != 0) {
                printf("%d\n", root->key);
            }
        }
        if (cek == 3) {
            if (isPrime(root->key)) {
                printf("%d\n", root->key);
            }
        }
        if (cek == 4) {
            printf("%d\n", root->key);
        }
    }
}

void __bst__preorder(BSTNode *root) {
    if (root) {
        if (cek == 1) {
            if (root->key % 2 == 0) {
                printf("%d\n", root->key);
            }
        }
        if (cek == 2) {
            if (root->key % 2 != 0) {
                printf("%d\n", root->key);
            }
        }
        if (cek == 3) {
            if (isPrime(root->key)) {
                printf("%d\n", root->key);
            }
        }
        if (cek == 4) {
            printf("%d\n", root->key);
        }
        __bst__preorder(root->left);
        __bst__preorder(root->right);
    }
}

/**
 * PRIMARY FUNCTION
 * ---------------------------
 * Accessible and safe to use.
 */

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

/**
 * Binary search tree traversal
 * - Inorder
 * - Postorder
 * - Preorder
 */

void bst_inorder(BST *bst) {
    __bst__inorder(bst->_root);
}

void bst_postorder(BST *bst) {
    __bst__postorder(bst->_root);
}

void bst_preorder(BST *bst) {
    __bst__preorder(bst->_root);
}
 
int main()
{
    BST set;
    bst_init(&set);

    while(1) {
        int a;
        scanf("%d", &a);
        if (a == -1) {
            break;
        }
        bst_insert(&set, a);
    }
    int n, cnt = 1;
    scanf("%d", &n);
    while(n--) {
        char c1[15], c2[15];
        scanf("%s %s", c1, c2);
        printf("Command : #%d\n", cnt++);
        if (c2[3] == 'a') {
            cek = 1;
        }
        else if (c2[3] == 'j') {
            cek = 2;
        }
        else if (c2[3] == 'm') {
            cek = 3;
        }
        else {
            cek = 4;
        }
        if (c1[1] == 'n') {
            bst_inorder(&set);
        }
        else if (c1[1] == 'o') {
            bst_postorder(&set);
        }
        else {
            bst_preorder(&set);
        }
    }
    
    return 0;
}
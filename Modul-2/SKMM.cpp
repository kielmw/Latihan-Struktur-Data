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

int parent, sesepuh, cek;

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

BSTNode* _cariAnak(BSTNode *root, int value) {
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

BSTNode* _cariIbu(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key) {
            parent = root->key;
            root = root->left;
        }
        else if (value > root->key) {
            parent = root->key;
            root = root->right;
        }
        else
            return root;
    }
    return root;
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

void cariAnak(BST *bst, int value) {
    BSTNode *temp = _cariAnak(bst->_root, value);
    if (temp->key == value) {
        if (temp->left == NULL && temp->right == NULL) {
            cek = 1;
            printf("diManakah Anak- aNakkuu :(\n");
            return;
        }
        if (temp->left == NULL) {
            printf("- ");
        }
        else {
            printf("%d ", temp->left->key);
        }
        if (temp->right == NULL) {
            printf("-\n");
        }
        else {
            printf("%d\n", temp->right->key);
        }
    }
}

void cariIbu(BST *bst, int value) {
    BSTNode *temp = _cariIbu(bst->_root, value);
    if (temp->key == value) {
        if (parent == 0) {
            printf("Aku adalaH sesepuH\n");
        }
        else {
            printf("%d\n", parent);
        }
    }
}
 
int main()
{
    BST set;
    bst_init(&set);

    int q;
    scanf("%d", &q);
    while(q--) {
        int n, k;
        char s[10];
        cek = 0;
        scanf("%d", &n);
        if (n == 1) {
            scanf("%d", &k);
            bst_insert(&set, k);
        }
        else {
            scanf("%s", s);
            scanf("%d", &k);
            if (s[0] == 'a') {
                cariAnak(&set, k);
            }
            else {
                parent = 0;
                cariIbu(&set, k);
            }
        }
        if (cek == 1) {
            break;
        }
    }
    return 0;
}
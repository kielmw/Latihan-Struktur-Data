#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int dt, ds, mp, first_dt, first_ds, first_mp, done;

typedef struct bstnode_t {
    int key;
    int shifter;
    int attack;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode* __bst__createNode(int value, int shift, int att) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->shifter = shift;
    newNode->attack = att;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value, int shift, int att) {
    if (root == NULL) 
        return __bst__createNode(value, shift, att);

    if (value < root->key)
        root->left = __bst__insert(root->left, value, shift, att);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value, shift, att);
    
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

void __bst__postorder(BSTNode *root) {
    if (root) {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        // printf("mp = %d\ndt = %d\nattack = %d\n", mp, dt, root->attack);
        if (root->key == 50000 && mp > 0) {
            printf("Eren Mikasa Happy Ending!\n");
            done = 1;
            return;
        }
        if (mp > 0) {
            if (ds > root->attack) {
                if (root->shifter == 1) {
                    printf("Eren makin OP lawan %d\n", root->key);
                    dt += root->key;
                }
                else {
                    printf("Biasa aja lawan %d\n", root->key);
                }
            }
            else {
                dt -= root->attack;
                if (dt <= 0) {
                    dt = first_dt;
                    mp--;
                }
                if (root->shifter == 1) {
                    printf("Eren kesulitan lawan %d\n", root->key);
                }
                else {
                    printf("Eren melemah lawan %d\n", root->key);
                }
            }
        }
        else {
            if (root->key == 50000) {
                return;
            }
            printf("Eren mati sebelum lawan %d\n", root->key);
        }
    }
}

void __bst__postordercek(BSTNode *root) {
    if (root) {
        __bst__postordercek(root->left);
        __bst__postordercek(root->right);
        if (root->key == 50000 && mp > 0) {
            done = 1;
            return;
        }
        if (mp > 0) {
            if (ds > root->attack) {
                if (root->shifter == 1) {
                    dt += root->key;
                }
            }
            else {
                dt -= root->attack;
                if (dt <= 0) {
                    dt = first_dt;
                    mp--;
                }
            }
        }
    }
}

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
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

void bst_insert(BST *bst, int value, int shift, int att) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value, shift, att);
        bst->_size++;
    }
}

void bst_postorder(BST *bst) {
    __bst__postorder(bst->_root);
}

void bst_postordercek(BST *bst) {
    __bst__postordercek(bst->_root);
}
 
int main()
{
    BST set;
    bst_init(&set);
    
    bst_insert(&set, 50000, 0, 999999);

    int n, t;
    scanf("%d %d", &n, &t);
    for (int i=0; i<n; i++) {
        int hp, sh, atk;
        scanf("%d %d %d", &hp, &sh, &atk);
        bst_insert(&set, hp, sh, atk);
    }
    while(t--) {
        scanf("%d %d %d", &dt, &ds, &mp);
        first_dt = dt;
        first_ds = ds;
        first_mp = mp;
        done = 0;
        bst_postordercek(&set);
        if (done == 1) {
            break;
        }
    }
    dt = first_dt;
    ds = first_ds;
    mp = first_mp;
    if (done == 0) {
        bst_postorder(&set);
        printf("Eren Mikasa Bad Ending!\n");
    }
    else {
        bst_postorder(&set);
    }
    return 0;
}
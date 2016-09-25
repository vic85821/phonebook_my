#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"

//use binary search tree to search
bst *findName(char lastname[], bst *root)
{
    while(root != NULL) {
        int temp = strcasecmp(lastname, root->data->lastName);
        if(temp == 0)
            return root;
        else
            return findName(lastname, temp < 0 ? root -> left : root -> right);
    }

    return NULL;
}

//origin append
entry *append(char lastName[], entry *e)
{
    /* allocate memory for the new entry and put lastName */
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;

    return e;
}

//build binary search
bst *build_bst(entry** pHead,int num)
{
    if(num == 0)
        return NULL;

    bst *root,*left;

    //recursive build left leaf
    left = build_bst(pHead, num>>1);


    // build root(center node)
    root = (bst *) malloc(sizeof(bst));
    root -> data = (entry *)malloc(sizeof(entry));
    strcpy((root->data)->lastName, (*pHead)->lastName);
    root->left = left;

    // build right left
    entry *tmp = *pHead;
    *pHead = (*pHead)->pNext;
    free(tmp);
    root->right = build_bst(pHead, num-(num>>1)-1);

    return root;
}




#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */

#define OPT 1
#define BST 1
typedef struct _PHONE_BOOK_DETAIL {
    union {
        char firstName[16];
        char email[16];
        char phone[10];
        char cell[10];
        char addr1[16];
        char addr2[16];
        char city[16];
        char state[2];
        char zip[5];
    };
} detail;

typedef struct _PHONE_BOOK_ENTRY {
    union {
        char lastName[MAX_LAST_NAME_SIZE];
        detail *detailDate;
    };
    struct _PHONE_BOOK_ENTRY *pNext;
} entry;

typedef struct _PHONE_BOOK_BST {
    struct _PHONE_BOOK_ENTRY *data;
    struct _PHONE_BOOK_BST *left;
    struct _PHONE_BOOK_BST *right;
} bst;

bst *findName(char lastname[], bst *root);
entry *append(char lastName[], entry *e);
bst *build_bst(entry** pHead,int num);

#endif

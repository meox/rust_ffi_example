#ifndef __TODOLIST__
#define __TODOLIST__

#include <stdlib.h>


/* DATA */

typedef struct _TODONODE {
    int position;
    char desc[128];
    struct _TODONODE* next;
} TODO_NODE;


typedef unsigned long int TODO_HANDLE;


/* FUNCTION */

int create_todolist(const char* list_name, TODO_NODE** list);
int add_element(const char* desc, TODO_NODE* list);
int show_list(TODO_NODE* list);

#endif

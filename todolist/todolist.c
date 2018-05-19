#include "todolist.h"
#include <string.h>
#include <stdio.h>


int create_todolist(const char* list_name, TODO_NODE** list)
{
    TODO_NODE* node = (TODO_NODE*)malloc(sizeof(TODO_NODE));
    if (node == NULL)
        return -1;
    
    strcpy(node->desc, list_name);
    node->next = NULL;
    node->position = 0;
    *list = node;
    return 0;
}


int add_element(const char* desc, TODO_NODE* list)
{
    if (list == NULL)
        return -1;
    
    while(list->next != NULL)
        list = list->next;
    
    list->next = (TODO_NODE*)malloc(sizeof(TODO_NODE));
    list->next->next = NULL;
    list->next->position = list->position + 1;
    strcpy(list->next->desc, desc);

    return 0;
}


int show_list(TODO_NODE* list)
{
    if (list == NULL)
        return -1;
    
    printf("##### %s #####\n", list->desc);
    list = list->next;
    while (list != NULL)
    {
        printf("[%d] %s\n", list->position, list->desc);
        list = list->next;
    }
    return 0;
}


double mult(double x, double y)
{
    return x * y;
}


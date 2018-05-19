#include <iostream>

extern "C" {
#include "todolist.h"
}

int main()
{
    TODO_NODE* list;
    create_todolist("MyList", &list);
    
    add_element("rust binding", list);
    add_element("more test with pointer", list);
    add_element("add more utility function", list);
    
    show_list(list);
}

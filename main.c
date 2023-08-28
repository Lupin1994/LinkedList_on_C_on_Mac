#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h"

int main()
{
    TLinkedListItem *new_list = linked_list_create();
    linked_list_add(new_list, 1);
    linked_list_add(new_list, 2);
    linked_list_add(new_list, 3);
    linked_list_add(new_list, 4);
    linked_list_add(new_list, 5);
    linked_list_print(new_list);
    new_list = linked_list_remove_by_index(new_list, 0);
    linked_list_print(new_list);
}

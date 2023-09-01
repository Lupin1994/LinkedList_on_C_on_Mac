#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h"

int main()
{
    TLinkedListItem *new_list = linked_list_create();
    int item, _count_element = 1;
    char _stop_char;
    do
    {
        printf("\nWrite element number - %d : ", _count_element);
        scanf("%d", &item);
        linked_list_add(new_list, item);
        _count_element++;
        getchar();
        printf("Next (y/n)? ");
        _stop_char = getchar();
    } while (_stop_char == 'y');
    // linked_list_add(new_list, 1);
    // linked_list_add(new_list, 2);
    // linked_list_add(new_list, 3);
    // linked_list_add(new_list, 4);
    // linked_list_add(new_list, 5);
    linked_list_print(new_list);
    // new_list = linked_list_remove_by_index(new_list, 0);
    // linked_list_print(new_list);


    // printf("Choose your way of filtration: \n");
    // printf(" 1-numbers more 5\t 2-only even numbers\n");
    // printf("Write your number: ");
    // int choose_number;
    // scanf("%d",&choose_number);

    
    // switch (choose_number)
    // {
    //     case 1:
    //         new_list = linked_list_with_filtering_elements(new_list, predicate_filter_more_5);
    //         break;
    //     case 2:
    //         new_list = linked_list_with_filtering_elements(new_list, predicate_filter_even_number);
    //         break;
    // }
    // linked_list_print(new_list);

    // new_list = map(new_list, Map_transform_element);
    // linked_list_print(new_list);
    // int element;
    // printf("Write element who you want add : ");
    // scanf("%d", &element);
    // int count = list_search_element(new_list, element, predicate_search_equal_element);
    // printf("%d",count);
    //printf("%s%d","Count elements in linked list: " ,linked_list_count_elements(new_list));
    linked_list_add_element_by_index(new_list , 2 , 5);
    linked_list_print(new_list);
    // new_list = linked_list_reverse(new_list);
    // linked_list_print(new_list);
//     new_list = linked_list_remove_all(new_list);
//     linked_list_print(new_list);
}

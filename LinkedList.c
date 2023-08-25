#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h"

void linked_list_print(TLinkedListItem *head){
    TLinkedListItem *list_writer;
    list_writer = head;
    printf("[");
    do
    {
        printf("%d ", list_writer->value);
        list_writer = list_writer->next_item;
    } while (list_writer != NULL);
    printf("]\n");
}

TLinkedListItem* linked_list_create(){
    TLinkedListItem *head = (TLinkedListItem*) malloc(sizeof(TLinkedListItem));
    head->value = NULL;
    head->next_item = NULL;
    return head;
}

void linked_list_add(TLinkedListItem * head, int value){
    if (head->value == NULL)
    {
        head->value = value;
        head->next_item = NULL;
        return;
    }

    TLinkedListItem *new_item = (TLinkedListItem*) malloc(sizeof(TLinkedListItem));
    new_item->value = value;
    new_item->next_item = NULL;

    TLinkedListItem *current_item = head;
    while (current_item->next_item != NULL)
    {
        current_item = current_item->next_item;
    }
    current_item->next_item = new_item;
}
TLinkedListItem* linked_list_remove_by_index(TLinkedListItem* head, int index){
    TLinkedListItem *temp_item = head, *current_item = NULL;
    int count = 0;
    if (head == NULL)
    {
        return NULL;
    }
    
    if (count == index)
    {
        return head->next_item;
    }
    
    while (count != index)
    {
        current_item = temp_item;
        temp_item = temp_item->next_item;
        count++;
    }
    current_item->next_item = temp_item->next_item;
    free(temp_item);
    return head;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h"

void linked_list_print(TLinkedListItem *head){
    if (head == NULL)
    {
        printf("Null !");
        return;
    }
    
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
TLinkedListItem* linked_list_with_filtering_elements(TLinkedListItem *head, bool (*predicate)(int)){

    TLinkedListItem *linked_list_output = linked_list_create();
    TLinkedListItem *current_item = head;

    while (current_item != NULL)
    {
        if (predicate(current_item->value) == true)
        {
            linked_list_add(linked_list_output, current_item->value);
        }
        current_item = current_item->next_item;
    }
    return linked_list_output;
    
}

TLinkedListItem* linked_list_remove_by_index(TLinkedListItem* head, int index){
    if (head == NULL)
    {
        return NULL;
    }
    
    if (index == 0)
    {
        TLinkedListItem *second_item = head->next_item;
        free(head);
        return second_item;
    }

    TLinkedListItem *before_remove_item = head;
    
    int count = 0;
    while (count <= index-1)
    {
        if (before_remove_item->next_item == NULL)
        {
            return head;
        }

        before_remove_item = before_remove_item->next_item;
        count++;
    }
    

    TLinkedListItem *remove_item = before_remove_item->next_item;
    before_remove_item->next_item = before_remove_item->next_item->next_item;
    free(remove_item);

    return head;    
} 

TLinkedListItem* linked_list_add_element_by_index(TLinkedListItem *head, int index , int value){

    if (index == 0)
    {
        TLinkedListItem *new_head = linked_list_create();
        new_head->value = value;
        new_head->next_item = head;
        return new_head;
    }

    int count = 1;

    TLinkedListItem *current_item = head->next_item;
    while (count < index - 1)
    { 
        current_item = current_item->next_item;
        if (current_item == NULL)
        {
            printf("Index out of range! ");
            return head; 
        }
        count++;  
    }
    TLinkedListItem *before_index_item = current_item;

    TLinkedListItem *new_node = linked_list_create();
    new_node->value = value;
    new_node->next_item = before_index_item->next_item;

    before_index_item->next_item = new_node;

    return head;
}


int linked_list_count_elements(TLinkedListItem *head){
    int count = 0;

    while (head != NULL)
    {
        count++;
        head = head->next_item;
    }
    return count;
    
}

int linked_list_search_element(TLinkedListItem *head, int element, bool (*predicate)(int, int)){
    int count = 0;
    TLinkedListItem *current_item = head;
    while (current_item != NULL)
    {
        if (predicate(element, current_item->value) == true)
        {
            count++;
        }
        
        current_item = current_item->next_item;
    }
    return count;
    
}

TLinkedListItem* map(TLinkedListItem *head, int (function(int))){
    TLinkedListItem *list_output = linked_list_create();
    TLinkedListItem *current_item = head;
    while (current_item != NULL)
    {
        linked_list_add(list_output, function(current_item->value));
        current_item = current_item->next_item;
    }
    
    return list_output;
}

TLinkedListItem* linked_list_reverse (TLinkedListItem *head){
    TLinkedListItem *reverse_linked_list = NULL;

    while (head)
    {
        TLinkedListItem *next = head->next_item;
        head->next_item = reverse_linked_list;
        reverse_linked_list = head;
        head = next;
    }
    return reverse_linked_list;
}

TLinkedListItem* linked_list_remove_all(TLinkedListItem *head){

    TLinkedListItem *remove_element = linked_list_create();
    TLinkedListItem *current_item = head;

    do
    {
        remove_element = current_item;
        current_item = current_item->next_item;
        free(remove_element);
    } while (current_item != NULL); 

    return NULL;
}
typedef struct LinkedListItem TLinkedListItem;

struct LinkedListItem
{
    int value;
    TLinkedListItem *next_item;
};

void linked_list_print(TLinkedListItem *head);
TLinkedListItem* linked_list_create();
void linked_list_add(TLinkedListItem * head, int value);
TLinkedListItem* linked_list_remove_by_index(TLinkedListItem* head, int index);

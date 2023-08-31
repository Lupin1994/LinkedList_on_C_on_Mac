typedef struct LinkedListItem TLinkedListItem;

struct LinkedListItem
{
    int value;
    TLinkedListItem *next_item;
};

bool predicate_filter_more_5(int element);
bool predicate_filter_even_number(int element);
bool predicate_search_equal_element(int search_element, int element_in_list);
int Map_transform_element(int element);

void linked_list_print(TLinkedListItem *head);
TLinkedListItem* linked_list_create();
void linked_list_add(TLinkedListItem * head, int value);
TLinkedListItem* linked_list_remove_by_index(TLinkedListItem* head, int index);
TLinkedListItem* linked_list_with_filtering_elements(TLinkedListItem *head, bool (*predicate)(int));
TLinkedListItem* map(TLinkedListItem *head, int (function(int)));
int linked_list_search_element(TLinkedListItem *head, int element, bool (*predicate)(int, int));
void linked_list_add_element_by_index(TLinkedListItem *head, int index, int value);
int linked_list_count_elements(TLinkedListItem *head);
TLinkedListItem* linked_list_reverse (TLinkedListItem *head);
void linked_list_remove_all(TLinkedListItem *head);
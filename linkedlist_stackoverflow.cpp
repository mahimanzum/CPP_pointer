#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct node_t {
    int value;
    node_t *next;
};

node_t* create_list() {
    int test_values[] = { 28, 1, 8, 70, 56 };
    node_t *new_node, *head = NULL;
    int i;

    for (i = 0; i < 5; i++) {
        new_node = (node_t*)malloc(sizeof(struct node_t));
        assert(new_node);
        new_node->value = test_values[i];
        new_node->next = head;
        head = new_node;
    }

    return head;
}

void print_list(const node_t *head) {
    for (; head; head = head->next)
        printf("%d ", head->value);
    printf("\n");
}

void destroy_list(node_t **head) {
    node_t *next;

    while (*head) {
        next = (*head)->next;
        free(*head);
        *head = next;
    }
}
node_t *dlt( int val,node_t **head){
    node_t** pp = head;
    node_t * del;
    //cout<<"line 32";
    while((*pp)->value != val){
            pp = &((*pp)->next);
    }
    //cout<<"line 35";
    //*pp= (*pp)->next;

    del = *pp;
    *pp = del->next;
    return *pp;
}
void remove_from_list(int val, node_t **head) {
    node_t *del, **p = head;

    while (*p && (**p).value != val)
        p = &(*p)->next;  // alternatively: p = &(**p).next

    if (p) {  // non-empty list and value was found
        del = *p;
        *p = del->next;
        del->next = NULL;  // not necessary in this case
        free(del);
    }
}

int main(int argc, char **argv) {
    node_t *head;

    head = create_list();
    print_list(head);

    dlt(56, &head);
    dlt(70, &head);
    //remove_from_list(56, &head);
    print_list(head);

    destroy_list(&head);
    assert (head == NULL);

    return EXIT_SUCCESS;
}

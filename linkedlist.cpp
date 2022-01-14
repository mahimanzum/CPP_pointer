#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
struct node{
    int val;
    node *next;
};
void print_list(const node *head) {
    for (; head; head = head->next)
        printf("%d ", head->val);
    printf("\n");
}
void print(node * head){
    node *cur = head;
    while(cur != NULL){
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");
}
node * insrt(node *head,int val){
    node *n;
    n = (node*)malloc(sizeof(struct node));
    n->val = val;
    n->next=NULL;

    if(head==NULL){
            head = n;
            return head;
    }
    node *cur = head;
    while(cur->next!=NULL) cur = cur->next;
    cur->next = n;
    return head;
}
void remove_from_list(int val, node **head) {
    node *del, **p = head;

    while (*p && (**p).val != val)
        p = &(*p)->next;  // alternatively: p = &(**p).next

    if (p) {  // non-empty list and value was found
        del = *p;
        *p = del->next;
        del->next = NULL;  // not necessary in this case
        free(del);
    }
}
node *dlt(node **head, int val){
    node** pp = head;
    node * del;
    //cout<<"line 32";
    while((*pp)->val != val){
            pp = &((*pp)->next);
    }
    //cout<<"line 35";
    *pp= (*pp)->next;

    //del = *pp;
    //*pp = del->next;
    return *pp;
}
int main(){
    node *head=NULL;
    for(int i = 10; i >=0; i--){
        head = insrt(head, i);
        //print(head);
    }
    //remove_from_list(10, &head);
    //cout<<"inside delete";
    print_list(head);
    dlt(&head, 10);
    //cout<<"outside delete";
    print_list(head);
    //printf("%d", head->val);
    return 0;
}

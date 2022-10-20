#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void add_to_list(struct node** local, int data)
{
    struct node *tmp;
    tmp = malloc(sizeof(struct node));
    tmp->data = data;
    tmp->next = *local;
    *local = tmp;
}

void callback_print(int data, void *userdata){
    printf("%d\n",data);
}

void callback_sum(int data, void *userdata)
{
    *(int*)userdata += data;
}

void iter_plus_action(struct node* list, void (*callback)(int, void*), void* userdata)
{
    while (list)
    {
        callback(list->data, userdata);
        list = list-> next;
    }
}

int main(){
    int i;
    int sum = 0;
    struct node *first = NULL;

    for(i=0; i<5; i++)
    {
        add_to_list(&first, i);
    }
    
    iter_plus_action(first, callback_print, NULL);
    printf("-----------\n");

    iter_plus_action(first, callback_sum, &sum);
    printf("summ: %d\n",sum);
    return 0;
}
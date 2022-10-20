#include <stdio.h>
#include <stdlib.h>

struct item
{
    int data;
    struct item *next;
};

struct item *arr_to_list(const int *arr, int len)
{
    int i;
    struct item *tmp, *first;
    first = NULL;
    for (i = len - 1; i >= 0; --i)
    {
        tmp = malloc(sizeof(struct item));
        tmp->data = arr[i];
        tmp->next = first;
        first = tmp;
    }
    return first;
}

void list_print(struct item *list)
{
    while (list)
    {
        printf("%d\n", list->data);
        list = list-> next;
    }
    
}

void del_neg(struct item **pcur)
{
    while(*pcur){
        if((*pcur)->data < 0)
        {
            struct item *tmp = *pcur;
            *pcur = (*pcur)->next;
            free(tmp);
        }
        else
        {
            pcur = &(*pcur)->next;
        }
    }
}

int arr[] = {-1, -25, 100, -123, -12, 0, 12};

int main(){
    int len = sizeof(arr)/sizeof(int);
    struct item *my_list_first;
    my_list_first =  arr_to_list(arr, len);
    list_print(my_list_first);
    printf("-----------------\n");
    del_neg(&my_list_first);
    list_print(my_list_first);
    return 0;
}
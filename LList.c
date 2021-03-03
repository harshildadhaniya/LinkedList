#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct intlist_t{
    int head;
    struct intlist_t* tail;
} intlist;

intlist* cons(int h, intlist* t){
    intlist* res;
    res = malloc(sizeof(intlist));

    res->head = h;
    res->tail = t;

    return res;
}

void free_list(intlist* t){

    intlist* temp;
    while (t != NULL){
        temp = t;
        t = t->tail;
        free(temp);
    } 
}

void print_list(intlist* t){

    intlist* temp = t;
    printf("[ ");
    while (temp != NULL){
        printf("%d ", temp->head);
        temp = temp->tail;
    }
    printf("]\n");
}

/* Calculate the length of the list using a loop */
int list_length_loop(intlist* t){

    int length = 0;
    intlist* temp = t;

    if(t == NULL){
        return length;
    }

    while(temp != NULL){
        length++;
        temp = temp->tail;
    }

    return length;
}

/* Calculate the length of the loop recursively */
int list_length_rec(intlist* t){

    if(t == NULL){
        return 0;
    }
    else{
        return 1 + list_length_rec(t->tail);
    }
    
}

/* The mem function checks if an element is present within the list or not. (Loop) */

int mem_loop(int v, intlist* t){

    int res = 0;

    while (t != NULL){

        if(t->head == v){
            res = 1;
        }

        t = t->tail;
    }

    return res;
}

/* The mem function checks if an element is present within the list or not. (Recursive) */

int mem_rec_aux(int v, intlist* t){

    if (t->head == v){
        return 1;
    }

    mem_rec_aux(v, t->tail);
}

int mem_rec(int v, intlist* t){

    int option = mem_rec_aux(v, t);

    if (option == 1){
        return 1;
    }
    else{
        return 0;
    }

}

int main(){
    intlist* L1 = cons(5, cons(6, cons(9, cons(200, cons(30, NULL)))));

    print_list(L1);

    int len1 = list_length_loop(L1);
    int len2 = list_length_rec(L1);

    printf("The length of the list using loop is: %d\n", len1);
    printf("The length of the list recursively is: %d\n", len2);

    int element;
    printf("Enter the element to be found within the list: ");
    scanf("%d", &element);

    int result1 = mem_loop(element, L1);

    if(result1 == 1){
        printf("The element is in the list (Loop).\n");
    }
    else{
        printf("The element is not in the list (Loop).\n");
    }

    int result2 = mem_rec(element, L1);

    if(result2 == 1){
        printf("The element is in the list (Recursively).\n");
    }
    else{
        printf("The element is not in the list (Recursively).\n");
    }

    free_list(L1);
    
    return 0;
}
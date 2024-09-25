#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

void printForwardTraverse(struct Node *node){
    int count=0;
    int maxCount=100;

    while(count<maxCount&&node!=NULL){
        printf("count:%-5i(%i)\n",count,node->data);
        node=node->next;
        count+=1;
    }
}

int main(int argc, char * argv[])
{
    //Create nodes
    struct Node *head = NULL;
    struct Node *a = NULL;
    struct Node *b = NULL;
    struct Node *c = NULL;
    struct Node *d = NULL;
    struct Node *e = NULL;

    //Allocate Memory
    a = malloc(sizeof(struct Node));
    b = malloc(sizeof(struct Node));
    c = malloc(sizeof(struct Node));
    d = malloc(sizeof(struct Node));
    e = malloc(sizeof(struct Node));

    //Assign Values
    a->data = 1;
    b->data = 2;
    c->data = 3;
    d->data = 4;
    e->data = 5;

    //Create Connections
    a->prev = NULL;
    a->next = b;

    b->prev = a;
    b->next = c;

    c->prev = b;
    c->next = d;

    d->prev = c;
    d->next = e;

    e->prev = d;
    e->next = NULL;

    //Traverse
    head=a;

    printForwardTraverse(head);

    //Free Memory
    free(a);
    free(b);
    free(c);
    free(d);
    free(e);

    return 0;
}
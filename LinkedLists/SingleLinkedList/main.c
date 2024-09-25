#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *next;
};

//Print Forward Traversal Through List
void printLinkedListFromNode(struct Node *node)
{
    int count =0;
    int maxCount = 30;

    while(node!=NULL&&count<maxCount){
        printf("(%i)\n",node->data);
        node=node->next;

        count+=1;
    }
}

struct Node* checkCycle(struct Node *head)
{
    if(head==NULL){
        return NULL;
    }

    struct Node *slow = head;
    struct Node *fast = head;

    while(fast!=NULL&&slow!=NULL){
        
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }

        slow=slow->next;
        
        if(slow==fast){
            printf("%i , %i\n",slow->data,fast->data);
            printf("found loop\n");
            return slow;
        }
    }
    
    printf("no loop\n");
    return NULL;
}

struct Node* checkCycleStart(struct Node *head){
    struct Node* cycleFoundNode = checkCycle(head);
    if(cycleFoundNode!=NULL)
    {
        struct Node *slow = head;
        struct Node *fast = cycleFoundNode;

        //Check if head is point of intersection and start of loop
        if(slow==fast){
            return slow;
        }

        //Iterate until head and poi meet
        while(fast!=slow){
            slow=slow->next;
            fast=fast->next;

            if(slow==fast){
                return slow;
            }
        }
    }

    printf("%i escaping\n",cycleFoundNode->data);
    return NULL;
}

int main(int argc, char * argv[])
{
    //Define Nodes
    struct Node *head = NULL;
    struct Node *a = NULL;
    struct Node *b = NULL;
    struct Node *c = NULL;
    struct Node *d = NULL;
    struct Node *e = NULL;
    struct Node *f = NULL;
    
    //Allocate Memory to Nodes
    a = malloc(sizeof(struct Node));
    b = malloc(sizeof(struct Node));
    c = malloc(sizeof(struct Node));
    d = malloc(sizeof(struct Node));
    e = malloc(sizeof(struct Node));
    f = malloc(sizeof(struct Node));

    //Assign Values
    a->data=1;
    b->data=2;
    c->data=3;
    d->data=4;
    e->data=5;
    f->data=6;
    //Create Connections
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=f;
    f->next=NULL;

    //Loop testing
    f->next=b;

    //Init Head
    head=a;

    printLinkedListFromNode(head);

    struct Node *cycleFoundNode = checkCycle(head);
    
    if(cycleFoundNode!=NULL)
    {
        printf("cycle with val (%i) is present\n",cycleFoundNode->data);
    }

    //Check for the starting of the cycle
    struct Node* cycleStartNode = checkCycleStart(head);

    if(cycleStartNode!=NULL){
        printf("cycle starts at (%i)\n",cycleStartNode->data);
    }

    // Free allocated memory
    free(a);
    free(b);
    free(c);
    free(d);
    free(e);
    free(f);

    return 0;
}
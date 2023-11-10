// WAP to detect deadlock using Resource Allocation Graph (RAG). Assumption : Single instance resources. 
#include <stdio.h>
#include<stdlib.h>
struct node { 
    int number; 
    struct node *next;
}; 
int n = 0;   //It counts the no. of nodes(process + resource) in the rag.
struct node *start = NULL, *tesla = NULL, *finish = NULL;

struct node* first_process(){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp -> number = 1;
    temp -> next = NULL;
    start = temp;
    n++;
    return temp;
}
void process_requests(struct node *process, int resource) {
    struct node *temp = malloc(sizeof(struct node));
    temp -> number = resource;
    temp -> next = NULL;
    process -> next = temp;
    tesla = temp;
    n++;
    return;
}
void reso_allocatn(struct node *resource, int process, int i, int end) {
    int m = 0;    // m denotes whether the cycle ends in the 1st process node or any other process node.
    if(i == 0){   //i denotes whether the resource is allocated to a new process (i = 0) or whether the allocation causes a cycle or not (i = 1). 
        struct node *temp = malloc(sizeof(struct node));
        temp -> number = process;
        if(temp -> number == end){
            finish = temp;
            m++;
        }
        temp -> next = NULL;
        resource -> next = temp;
        tesla = temp;
        n++;
        return;
    }
    else if(i == 1){
        n++;
        resource -> next = (m == 0)?start:finish;
    }
}
void check_loop(){
    int alt = 0;
    struct node *temp = start;
    while(temp != NULL){
        n--;
        if(n == -1)
            break;
        if(alt == 0){
            printf("P%d -> ", temp -> number);
            alt = 1;
        }
        else{
            printf("R%d -> ", temp -> number);
            alt = 0;
        }
        temp = temp -> next;
    }
    if(n == 0)
        printf("= No Cycle, No deadlock\n");
    else
        printf("= Cycle exists, Deadlock present\n");
}
int main(){
    tesla = first_process();
    // process_requests(tesla, 1);      //these 4 calls are for cycle test-case.
    // reso_allocatn(tesla, 2, 0, 1);
    // process_requests(tesla, 2);
    // reso_allocatn(tesla, 1, 1, 1);    //4th argument of reso_allocatn() when happens to be equal with any value of the 2nd argument denotes cycle O/W not a cycle.
    process_requests(tesla, 1);
    reso_allocatn(tesla, 2, 0, 100);
    process_requests(tesla, 2);         //4th arg = 100 denotes a no-cycle.
    reso_allocatn(tesla, 3, 0, 100);     //these 4 calls are for no-cycle test-case.
    check_loop();
    return 0;
}

// O/P for 1st 4 calls
// P1 -> R1 -> P2 -> R2 -> P1 -> = Cycle exists, Deadlock present

// O/P for 2nd 4 calls
// P1 -> R1 -> P2 -> R2 -> P3 -> = No Cycle, No deadlock
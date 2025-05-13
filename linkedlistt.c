#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int no;
    char name[40];
    int age;
    struct student *next;    
};
typedef struct student node;

node * createList(){
    int n,k;
    node *head,*p;
    printf("How many students in the list ?");
    scanf("%d",&n);
    for(k=0;k<n;k++){
        if(k==0){
            head = (node*)malloc(sizeof(node));
            p = head;
        }
        else {
            p->next = (node*)malloc(sizeof(node));
            p = p->next;
        }
        printf("Enter %d. student number: ",k+1);scanf("%d",&p->no);
        printf("Enter %d. student name: ",k+1);scanf("%s",p->name);
        printf("Enter %d. student age: ",k+1);scanf("%d",&p->age);
    }
    p->next = NULL;
    return head;
}

void traverseList(node * head){
    int counter = 1;
    node * p;
    p = head;
    while(p!=NULL){
        printf("%d- %d %s %d \n",counter,p->no,p->name,p->age);
        p = p->next;
        counter++;
    }
}

node * addNode(node * head){
    int stdNo;
    node *p,*q;
    node *newNode = (node*)malloc(sizeof(node));
    printf("Enter new student number: ");scanf("%d",&newNode->no);
    printf("Enter new student name: ");scanf("%s",newNode->name);
    printf("Enter new student age: ");scanf("%d",&newNode->age);

    printf("Enter std number that new record will be added before: \n");
    printf("Press 0 to add to the end of list \n");
    scanf("%d",&stdNo);

    p = head;
    if(p->no == stdNo){
        newNode ->next = p;
        head = newNode;
        p = head;
    }
    else{
        while(p->next != NULL && p->no != stdNo){
            q = p;
            p = p->next;
        }
        if(p->no == stdNo){
            q ->next = newNode;
            newNode ->next = p;
        }
        else if(p->next == NULL){
            p->next = newNode;
            newNode->next = NULL;
        }
        
    }
}

node *deleteNode(node *head){
    int stdNode;
    node *p,*q
}


int main(){
    node * head;
    head = createList();
    traverseList(head);

    return 0;
}
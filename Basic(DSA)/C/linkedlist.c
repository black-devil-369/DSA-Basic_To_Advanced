#include<stdio.h>
#include<stdlib.h>
struct node
{
    /* data */
    int data;
    struct node* next;
};

struct node *createNode(int data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Memory Allocation Faild\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
    
}

void insertAtstart(struct node **root,int data){
    struct node *n =createNode(data);
    if(root == NULL){
        *root = n;
    }
    else{
        n->next = *root;
        *root = n;
    }
}

void printList(struct node *root){
    struct node *temp;
    temp = root;
    while (temp!= NULL)
    {
        /* code */
        printf(" %d  ",temp->data);
        temp = temp->next;
        printf("\n");
    }
    
}
void freedMemory(struct node *head){
    while(head!=NULL){
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
}
int main(){
    struct node *head = NULL;
    insertAtstart(&head,8);
    insertAtstart(&head,9);
    insertAtstart(&head,10);
    printList(head);
    freedMemory(head);
    return 0;

}
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
struct Arrays{
    int capacity;
    int lastindex;
    int *ptr;
};
void createarray(struct Arrays *s,int cap){
    s->capacity = cap;
    s->lastindex = -1;
    s->ptr = (int*)malloc(s->capacity * sizeof(int));
}
void append(struct Arrays *a,int data){
    if(a->lastindex == a->capacity-1){
        printf("Arrays is Full");
    }
    a->lastindex++;
    a->ptr[a->lastindex] = data;
}
void printArray(struct Arrays *a){
    int i ;
    for(i = 0;i<=a->lastindex;i++){
        printf("%d ",a->ptr[i]);
    }
    printf("\n");
}
int count(struct Arrays *a){
    return a->lastindex;
}
bool isEmpty(struct Arrays *a){
    return a->lastindex == -1;
}
bool isFull(struct Arrays *a){
    return a->lastindex == a->capacity-1;
}
int capacitys(struct Arrays *a){
    return a->capacity;
}
void del(struct Arrays *a , int index){
    if(isEmpty(a)){
        printf("Arrays is Empty");
    }
    if(index < 0 || index>a->capacity){
        printf("Invalid index");
    }
    else{
        for(int i =0;i<=a->lastindex;i++){
            a->ptr[i] = a->ptr[i+1];
        }
        a->lastindex--;
    }
}
void freeArray(struct Arrays *a){
    free(a->ptr);
    a->capacity = 0;
    a->lastindex = -1;
    a->ptr = NULL;
}
int main(){
    struct Arrays s;
    createarray(&s,4);
    append(&s,52);
    append(&s,70);
    append(&s,90);
    printArray(&s);
    del(&s,2);
    printf("\n");
    printArray(&s);
    freeArray(&s);
    return 0;
}
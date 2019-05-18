#include<stdio.h>
struct node{
    int info;
    struct node *link;
};
struct node *start = NULL;
struct node* createnode(){
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    return n;
};
void insertnode(){
    struct node *temp,*t;
    temp = createnode();
    printf("Enter a number ");
    scanf("%d",&temp->info);
    temp->link = NULL;
    if(start == NULL)
        start = temp;
    else{
        t = start;
        while(t->link!=NULL)
            t = t->link;
        t->link = temp;
    }
}
void deletenode(){
    struct node *r;
    if(start == NULL)
        printf("List is empty.\n");
    else{
        r = start;
        start = start->link;
        free(r);
    }
}
void viewlist(){
    struct node *t;
    if(start == NULL)
        printf("List is empty.\n");
    else{
        t = start;
        while(t!=NULL){
            printf("%d ",t->info);
            t = t->link;
        }
    }
}
int menu(){
    int ch;
    printf("\n1) Add value in a list\n");
    printf("2) Delete first value\n");
    printf("3) View List\n");
    printf("4) Exit\n");
    printf("\nEnter a choice ");
    scanf("%d",&ch);
    return ch;
}
void main(){
    while(1){
        switch(menu()){
        case 1:
            insertnode();
            break;
        case 2:
            deletenode();
            break;
        case 3:
            viewlist();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
}

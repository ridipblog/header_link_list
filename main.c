#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node * next;
};
struct Node * create_hl(struct Node * start)
{
    struct Node *ptr,*new_node;
    int data;
    printf("\nEnter -1 to end ");
    printf("\nEnter Data ");
    scanf("%d",&data);
    while(data!=-1)
    {
        new_node=(struct Node *)malloc(sizeof(struct Node));
        new_node->data=data;
        new_node->next=NULL;
        if(start==NULL)
        {
            start=(struct Node *)malloc(sizeof(struct Node));
            start->next=new_node;
        }
        else
        {
            ptr=start;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=new_node;
        }
        printf("\nEnter Data ");
        scanf("%d",&data);
    }
    return start;
};
void display(struct Node * start)
{
    struct Node * ptr;
    ptr=start->next;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    struct Node * start=NULL;
    int option;
    while(1)
    {
        printf("\n1 for create header list");
        printf("\n2 for display ");
        scanf("%d",&option);
        if(option==1)
        {
            start=create_hl(start);
        }
        else if(option==2)
        {
            display(start);
        }
        else
        {
            break;
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
struct stack
{
    int top;

        int data[SIZE];
};
typedef struct stack STACK ;
void push(STACK *s,int item)
{
    if(s->top==SIZE - 1)
        printf("\n stack overflow");
    else
    {
        s->top=s-> top + 1;
        s->data[s->top]=item;
    }
}
void pop (STACK*s)
{
    if(s->top==-1)
        printf("\n Stack is underflow");
    else
    {
        printf("\n Element poped is %d",s->data[s->top]);
        s->top=s->top-1;
    }
}
void display(STACK s)
{
    int i;
    if(s.top==-1)
        printf("\n Stack Empty");
    else
    {
        printf("\n Stack content are \n");
        for(i=s.top;i>=0;i--)
            printf("%d\n",s.data[i]);
    }
}
int main()
{
    int ch,item;
    STACK S;
    S.top=-1;
    for(;;)
    {
        printf("\n 1.Push");
        printf("\n 2. POP");
        printf("\n 3.Display");
        printf("\n 4.Exit");
        printf("\n Read Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1 :
            printf("\n Read element to be pushed");
            scanf("\%d",&item);
            push(&S,item);
            break;
        case 2 :
            pop(&S);
            break;
        case 3 :
            display(S);
            break;
        default : exit(0);
        }
    }
    return 0;
}

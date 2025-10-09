#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 20
struct stack{
int top;
char data[SIZE];
};
typedef struct stack STACK;
void push(STACK *S,char item)
{
    S->data[++(S->top)] = item;
}
char pop(STACK*S)
{
    return S->data[(S->top)--];
}
int preced(char symbol)
{
    switch(symbol)
    {
    case'+':
    case'-':return 1;
    case'*':
    case'/':return 3;
    case'^':return 5;
    }
}
void infixtopostfix(STACK*S,char infix[20])
{
    int i,j=0;
    char symbol,postfix[20],temp;
    for (i=0;infix[i]!=0;i++)
    {
        symbol = infix[i];
        if(isalnum(symbol))
            postfix[j++]=symbol;
        else
        {
            switch(symbol)
            {
                case'(':push(S,symbol);
                break;
                case')':temp=pop(S);
                while(temp!='(')
                {
                    postfix[j++]=temp;
                    temp=pop(S);
                }
                break;
                case '+':
                case '-':
                case '^':
                case '*':
                case '/':if(S->top==-1||S->data[S->top]=='(')
                                         push(S,symbol);
                        else
                            {
                                while(preced(S->data[S->top])>=preced(symbol)&&S->top!=-1&&S->data[S->top]!='(')
                                      {
                                          postfix[j++]=pop(S);
                                      }
                                      push (S,symbol);
                             }
                             break;
            }
    }
}
while (S->top!=-1)
    postfix[j++]=pop(S);
postfix[j] = '\0';
printf("\n Postix expression is %s",postfix);
}
int main()
{
    char infix[20];
    STACK S;
    S.top=-1;
    printf("\n Read infix expression \n");
    scanf("%s",infix);
    infixtopostfix(&S,infix);
    return 0;
}

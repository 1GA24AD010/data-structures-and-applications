#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define SIZE 10
struct stack
{
    int top;
    float data[SIZE];
};
typedef struct stack STACK;
void push(STACK *S,float item)
{
    S->data[++(S->top)]=item;
}
float pop(STACK *S)
{
    return S->data[(S->top)--];
}
float compute(float opr1,char symbol,float opr2)
{
    switch(symbol)
    {
        case '+':return opr1 + opr2;
        case '-':return opr1 - opr2;
        case '*':return opr1 * opr2;
        case '/':return opr1 / opr2;
        case '^':return pow(opr1,opr2);
    }
}
float evaluatepostfix(STACK *S,char postfix[SIZE])
{
    int i;
    float opr1,opr2,res;
    char symbol;
    for(i=0;postfix[i]!='\0';i++)
    {
        symbol=postfix[i];
        if(isdigit(symbol))
            push(S,symbol-'0');
        else
        {
            opr2=pop(S);
            opr1=pop(S);
            res=compute(opr1,symbol,opr2);
            push(S,res);
        }
    }
         return pop(S);
}
int main()
{
    char postfix[SIZE];
    STACK S;
    float res;
    S.top=-1;
    printf("\n Read postfix expression\n");
    scanf("%s",postfix);
    res=evaluatepostfix(&S,postfix);
    printf("\n The final result is %f\n",res);
    return 0;
}


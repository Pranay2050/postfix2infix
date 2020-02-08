#include <stdio.h>

int stack[50];
int top=-1;
int decimal=0;

int isDigit(char ch)
{
    if(ch>='0' && ch<='9')
        return 1;

    else
        return 0;
}

int pop()
{
    return(stack[top--]);
}

int push(int value)
{
  if(decimal==1)
    {
    int num;
    num=pop();
    stack[++top]=value+10*num;
    }
  else if(decimal==0)
    {
    stack[++top]=value;
    decimal=1;
    }
}


int main()
{
    char postfix[50],ch;
    char infix[50];
    int parse = 0;
    int i=0,op1,op2;
    printf("Enter the Postfix Expression: ");
    fgets(postfix,100,stdin);
    printf("Result : ");

    while( (ch=postfix[i++]) != '\n')
    {
    if(isDigit(ch))
        push(ch-'0');
    else if(ch==' ')
        decimal=0;
    else
        {
        decimal=0;
        op2=pop();
        op1=pop();
        if(parse == 0)
        {
            printf("%d %c %d",op1,ch,op2);
            parse++;
        }
        else
            printf("%c %d",ch,op2);
        switch(ch)
            {
            case '+':push(op1+op2);     break;
            case '-':push(op1-op2);     break;
            case '*':push(op1*op2);     break;
            case '/':push(op1/op2);     break;

            default:
                 printf("Input invalid ... give proper input\n");
                 break;
            }
        }
    }
    printf(" = %d\n",stack[top]);
}


/*

OUTPUT
Enter the Postfix Expression: 10 15 + 20 *
Result : 10 + 15* 20 = 500

*/

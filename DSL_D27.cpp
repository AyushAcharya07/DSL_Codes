// DSL C27
/*
Implement C++ program for expression conversion as infix to postfix and its evaluation 
using stack based on given conditions: 
1. Operands and operator, both must be single character.
2. Input Postfix expression must be in a desired format.
3. Only '+', '-', '*' and '/ ' operators are expected.

*/

# include <iostream>
# include <string.h>
using namespace std;

class stack
{
    public:
    int top,nn;
    char exp[50];
    char result[50];
    char postfix[50];

    
    stack()
    {
        top=-1;
    }

    int isempty()
    {
        if (top==-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int isfull()
    {
        if (top==50-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void pushexp(char symbol)
    {
        if (isfull()==1)
        {
            cout<<"Stack Overflow"<<endl;
        }
        else
        {
            top++;
            exp[top]=symbol;
        }
    }

    char popexp()
    {
        if (isempty()==1)
        {
            cout<<"Stack Underflow"<<endl;
        }
        else
        {
            return(exp[top--]);
        }
    }


    void read()
    {
        cout<<"Enter an infix expression : "<<endl;
        cin>>exp;
    }


    void conversion()
    {
        int prev,p;
        char entry;
        p=0;

        for (int i=0;exp[i]!='\0';i++)
        {
            switch (exp[i])
            {
            case '(':
                    pushexp(exp[i]);
                    break;
            case ')':
                    while((entry=popexp())!='(')
                    result[p++]=entry;
                    break;

            case '+':
            case '-':
            case '*':
            case '/':
                if(isempty()==0)
                {  
                    prev=prior(exp[i]);
                    entry=popexp();
                    while(prev<=prior(entry))
                    {  
                        result[p++]=entry;
                        if(isempty()==0)
                        entry=popexp();
                        else
                            break;
                    }
                    if(prev>prior(entry))
                    pushexp(entry);
                }
                pushexp(exp[i]);
                break;
            default:
                result[p++]=exp[i];
                break;
            }
        }

            while(isempty()==0)                //while stack is not empty
            result[p++]=popexp();
            result[p]='\0';
            cout<<"\nThe postfix expression is: "<<result<<endl;
    }
   
    int prior(char symbol)
    {  
        switch(symbol)
        { 
            case '/': return(4);          // Precedence of / is 4
            case '*': return(3);          // Precedence of * is 3
            case '+': return(2);          // Precedence of + is 2
            case '-': return(1);          // Precedence of - is 1
            case '(': return(0);          // Precedence of ( is 0
            default: return(-1);
        }
    }
    
    void evaluation()
    {
        
        string ch;
        int a,b,c,d;
        int n1,n2,n3,ans;
        int value_a,value_b,value_c,value_d;
        int i;
        i=0;
        cout<<"Enter the values of a,b,c and d : "<<endl;
        cin>>value_a>>value_b>>value_c>>value_d;
    
            
        while(postfix[i])
        {
            if (postfix[i]==' ' || postfix[i]=='\t')
            {
                i++;
                continue;
            }

            if (isdigit(postfix[i]))
            {
                nn=postfix[i]-'0';
                pushexp(nn);
            }

            if (isalpha(postfix[i]))
            {
                
            }

            else
            {
                n1=popexp();
                n2=popexp();
                switch(postfix[i])
                {
                    case '+':
                        n3=n2+n1;
                        break;

                    case '-':
                        n3=n2-n1;
                        break;

                    case '*':
                        n3=n2*n1;
                        break;

                    case '/':
                        n3=n2/n1;
                        break;

                    default:
                        cout<<"No expression"<<endl;
                        break;
                }
                pushexp(n3);
            }
            i++;
        }
        cout<<n3;
    }
        
     
};

int main()
{
    stack s;
    int ch,ans;
    do
    {
        cout<<"**********MENU**********"<<endl;
        cout<<"1.Convert the infix code into postfix code\n2.Evaluate postfix expression\n3.Exit"<<endl;
        cout<<"Enter your choice : "<<endl;
        cin>>ch;

        switch(ch)
        {
            case 1:
                s.read();
                s.conversion();
                break;

            case 2:
                s.evaluation();
                break;

            default:
                cout<<"You have opted to exit"<<endl;
                break;
        }
        cout<<"Do you want to exit?"<<endl;
        cout<<"1.Continue\n2.Exit"<<endl;
        cin>>ans;
    }while (ans==1);

    if (ans<=2)
    {
        cout<<"You have successfully exited!!"<<endl;
    }


    return 0;
}

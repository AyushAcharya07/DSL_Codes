// DSL D26

/*In any language program mostly syntax error occurs due to unbalancing delimiter such as 
(),{},[]. Write C++ program using stack to check whether given expression is well 
parenthesized or not.
*/

# include <iostream>
using namespace std;

# define size 100

class expression
{
    public:
    int top;
    char exp[size];

    expression()
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
        if (top==size-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void pushexp(char x)
    {
        if (isfull()==1)
        {
            cout<<"Stack Overflow"<<endl;
        }
        else
        {
            top++;
            exp[top]=x;
        }
    }

    int popexp()
    {
        char s;
        if (isempty()==1)
        {
            cout<<"Stack Underflow"<<endl;
        }
        else
        {
            s=exp[top];
            top--;
            return s;
        }
    }
};

int main()
{
    expression e;
    char exp[size],ch;
    int i=0, flag=0;

    cout<<"This is a Paranthesis Checking Program!!"<<endl;
    cout<<"Please enter an expression to check whether it is well parenthesized or not : "<<endl;
    cin>>exp;


   if ((exp[0]==')') || (exp[0]==']') || (exp[0]=='}') )
   {
        cout<<"OOPS!!You have entered a wrong expression!!!\nPlease try again!!"<<endl;
        return 0;
   }

   else
   {
        while (exp[i]!= '\0')
        {
            if ((exp[i]=='(') || exp[i]=='[' ||exp[i]=='{' )
            {
                e.pushexp(exp[i]);
            }
            else if ( exp[i]==')' || exp[i]==']' ||exp[i]=='}' )
            {
            	ch=e.popexp();
            	if ((exp[i]==')'&& ch!='(') ||(exp[i]==']'&& ch!='[')||(exp[i]=='}'&& ch!='{'))
            	{
            		flag=1;
            		break;
            	}
            }
            i++;
        }
   }

   if (e.isempty() || flag==0)
   {
        cout<<"The expression entered is well parenthesized!!\nYou can proceed with the expression now!!"<<endl;
   }

   else
   {
        cout<<"Sorry!!You have entered a wrong parenthesized expression!!\nSo you cannot proceed with the expression!\nPlease try again"<<endl;
   }
   return 0;
   
}
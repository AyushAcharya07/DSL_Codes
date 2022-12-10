//DSL C22
/*
Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set 
B of students like butterscotch ice-cream. Write C++ program to store two sets using 
linked list. compute and display
a) Set of students who like both vanilla and butterscotch
b) Set of students who like either vanilla or butterscotch or not both
c) Number of students who like neither vanilla nor butterscotch

*/

# include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;
    node()
    {
        next=NULL;
    }
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

int createdata(node *head,int val)
{
    node *temp=new node;
    temp=head;
    int index=0;
    while (temp!=NULL)
    {
        if (temp->data==val)
        {
            return index;
        }
        index++;
        temp=temp->next;
    }
    return -1;
}

void adddata(node *&head, int val)
{
    if (createdata(head,val)==-1)
    {
        node *temp=new node();
        temp=head;
        node *newnode=new node(val);
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void display(node *head)
{
    node *temp=new node;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void give_input(node *&head, string flavour)
{
    int n, rollno;
    cout<<"Enter the no. of students who like "<<flavour<<" ice-cream : "<<endl;
    cin>>n;
    cout<<"Enter the roll nos. of the students : "<<endl;
    cin>>rollno;
    head=new node(rollno);
    for (int i=1;i<n;i++)
    {
        cin>>rollno;
        adddata(head,rollno);
    }
}

void either_or(node *set1, node *set2)          //for students like either vanilla or butterscotch but not both
{
    node *temp=new node;
    temp=set1;
    while (temp!=NULL)
    {
        if (createdata(set2, temp->data)==-1)
        {
            cout<<temp->data<<" ";
        }
        temp=temp->next;
    }
    node *temp2=new node;
    temp2=set2;
    while (temp2 != NULL)
    {
        if (createdata(set1, temp2->data)==-1)
        {
            cout<<temp2->data<<" ";
        }
        temp2=temp2->next;
    }
    cout<<endl;
}

void like_both(node *set1, node *set2)      //intersection (who like both vanilla and butterscotch)
{
    node *temp=new node;
    temp=set1;
    while (temp!=NULL)
    {
        if (createdata(set2,temp->data)!=-1)
        {
            cout<<temp->data<<" ";
        }
        temp=temp->next;
    }
    cout<<endl;
}

int neithernor(node *set1, node *set2, int total)       //for students who like neither of them
{
    int count=0;
    cout<<"Enter total : "<<endl;
    cin>>total;
    for (int i=1;i<=total;i++)
    {
        if ((createdata(set1,i)!=-1) & (createdata(set2,i)!=-1))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    node *vanilla;      //for students who like vanilla
    node *butter;       //for students who like butterscotch
    int ch,total;
    char ans;

    cout<<"Enter the total no. of students in the class : "<<endl;
    cin>>total;

    give_input(vanilla,"VANILLA");      //getting input for vanilla students
    give_input(butter,"BUTTERSCOTCH");  //getting input for butterscotch students

    do
    {
        cout<<"***************MENU***************"<<endl;
        cout<<"1.Display Data\n2.Set of students who like both Vanilla and Butterscotch icecream\n3.Set of students who either like Vanilla or Butterscotch icecream, but not both\n4.Set of students who neither like Vanilla nor Butterscotch"<<endl;
        cout<<"Enter your choice : "<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout << "Students who like Vaniila icecream are : "<<endl;
                display(vanilla);
                cout << "Students who like Butterscotch icecream are : "<<endl;
                display(butter);
                break;

            case 2:
                cout << "Students who like both Vanilla and Butterscotch icecream are : " << endl;
                like_both(vanilla, butter);
                break;

            case 3:
                cout<<"Students who like either Vanilla or Butterscotch but not both are : "<<endl;
                either_or(vanilla,butter);
                break;

            case 4:
                cout<<"Students who like neither Vanilla nor Butterscotch icecream are : "<<neithernor(vanilla,butter,total)<<endl;
                break;

            default:
                cout<<"Sorry! Wrong choice entered!!"<<endl;
                break;

        }cout<<"Do you want to continue?"<<endl;
        cout<<"Press y for yes\nPress n for no"<<endl;
        cin>>ans;
    }while (ans=='y');
   
    if (ans=='n')
    {
        cout<<"You have successfully exited!!!"<<endl;
    }

    return 0;

}
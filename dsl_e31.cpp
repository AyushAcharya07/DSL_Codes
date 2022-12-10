// DSL E31
/*
A double-ended queue (deque) is a linear list in which additions and deletions may be 
made at either end. Obtain a data representation mapping a deque into a one dimensional array. Write C++ program to simulate deque with functions to add and 
delete elements from either end of the deque.
*/

# include <iostream>
using namespace std;

# define size 10

class dequeue
{
    int D[size];
    int front,rear;
    public:
    dequeue()
    {
        front=-1;
        rear=-1;
    }

    void enqueue_front()
    {
        if (front==-1)
        {
            front=rear=0;
            cout<<"Enter the value to add at front : "<<endl;
            cin>>D[front];
        }
        else
        {
            cout<<"Cannot add to the front"<<endl;
        }
    }

    void enqueue_rear()
    {
        if (rear==size-1)
        {
            cout<<"Queue is full"<<endl;
        }
        else
        {
            if (rear==-1)
            {
                front=rear=0;
            }
            else
            {
                rear=rear+1;
                cout<<"Enter value to add at rear end : "<<endl;
                cin>>D[rear];
            }
        }
    }

    void dequeue_front()
    {
        int value;
        if (front==-1)
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            value=D[front];
            if (front==rear)
            {
                front=rear=-1;
            }
            else
            {
                front=front+1;
                cout<<"The value "<<value<<" deleted from front"<<endl;
            }
        }


    }

    void dequeue_rear()
    {
        int value;
        if (rear==-1)
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            value=D[rear];
            if (front==rear)
            {
                front=rear=-1;
            }
            else
            {
                rear=rear-1;
                cout<<"The value "<<value<<" deleted from rear"<<endl;
            }
        }
    }

    void display()
    {
        if (front==-1)
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            int i=front;
            cout<<"The dequeue is : ";
            while (i<=rear)
            {
                cout<<" "<<D[i];
                i=i+1;
            }
            
        }
    }

    
};

int main()
{
    dequeue d;
    int ch,ans;
    do
    {
        cout<<"**********MENU**********"<<endl;
        cout<<"\tDEQUEUE OPERATIONS"<<endl;
        cout<<"1.Enqueue_front\n2.Enqueue_back\n3.Dequeue_front\n4.Dequeue_rear\n5.Display"<<endl;
        cin>>ch;

        switch(ch)
        {
            case 1:
                d.enqueue_front();
                break;

            case 2:
                d.enqueue_rear();
                break;

            case 3:
                d.dequeue_front();
                break;

            case 4:
                d.dequeue_rear();
                break;

            case 5:
                d.display();
                break;

            default:
                cout<<"You have enetred wrong choice"<<endl;
                break;
        }
        cout<<"\nDo you want to continue?"<<endl;
        cout<<"1.Yes\n2.No"<<endl;
        cin>>ans;
    }while (ans==1);
    
    if (ans<=2)
    {
        cout<<"You have successfully exited !!!"<<endl;
    }
    return 0;
}
/* 
DSL E29

Write C++ program for simulating job queue. Write function to add job and delete a job from 
the queue.

*/

# include <iostream>
using namespace std;

class Queue
{
	int A[20];
	int front_start,rear_end;
	
	public:
	Queue()
	{
		front_start=-1;
		rear_end=-1;
	}
	
	int isempty()
	{
		if (front_start==-1)
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
		if (rear_end>=20)
		{
			return 1;
		}

		else
		{
			return 0;
		}
	}

	void enqueue(int a)
	{
		if (isfull()==1)
		{
			cout<<"The queue is completely filled!\nYou can't append more!"<<endl;
		}
	
		else
		{
			if (front_start==-1)
			{
				front_start++;
			}
			rear_end++;
			A[rear_end]=a;
		}
	}

	void dequeue()
	{
		int x;
		if (isempty())
		{
			cout<<"The queue is empty!\nYou cannot delete anything!"<<endl;
		}

		else
		{
			x=A[front_start];
			front_start++;
			cout<<"The job"<<x<<"is successfully deleted from the queue"<<endl;
		}
	}

	void display()
	{
		int i;
		cout<<"The queue is : "<<endl;
		for (i=front_start;i<=rear_end;i++)
		{
			cout<<A[i]<<" ";
		}
		cout<<endl;
	}

};

int main()
{
	int ch,n,x,e,i;
	Queue q;
	
	do
	{
		cout<<"***************MENU***************"<<endl;
		cout<<"1.Add job in queue\n2.Delete job in queue\n3.Display the queue"<<endl;
		cout<<"Enter your choice :"<<endl;
		cin>>ch;

		switch(ch)
		{
			case 1:
				cout<<"Job added successfully!"<<endl;
				cout<<"Enter the total no. of jobs needed in the queue : "<<endl;
				cin>>n;
				cout<<"Enter the job enteries in the queue : "<<endl;
				
				for (i=0;i<n;i++)
				{
					cin>>e;
					q.enqueue(e);
				}	
				q.display();
				break;

			case 2:
				q.dequeue();
				cout<<"Job deleted successfully!"<<endl;
				q.display();
				break;
			case 3:
				q.display();
				break;
			default:
				cout<<"Wrong choice entered!"<<endl;
				break;
		}
		cout<<"Do you want to continue ?"<<endl;
		cout<<"1.Yes\n2.No"<<endl;
		cin>>x;
	}while(x==1);

	return 0;
}

/*

DSL E32

Pizza parlor accepting maximum M orders. Orders are served in first come first served 
basis. Order once placed cannot be cancelled. Write C++ program to simulate the system 
using circular queue using array.

*/

# include <iostream>
using namespace std;
# define size 5


class Pizza
{           
	int order[size];
	int front,rear;

	public:
	Pizza()
	{
		front=-1;
		rear=-1;
	}

	int order_full()
	{
		if(front==(rear+1)%size)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	int order_empty()
	{
		if (front==-1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	void take_order(int type_order)
	{
		if (order_full())
		{
			cout<<"Oops! All of the orders are full!\nPlease try later"<<endl;
		}
		else
		{
			if (front==-1)
			{
				front=rear=0;
			}
			else
			{
				rear=(rear+1)%size;
			}
			
			order[rear]=type_order;
		}
	}

	void bill_payment(int p)
	{
		int item;
		char ans;
		
		if (order_empty())
		{
			cout<<"No bill found!\nTry again"<<endl;
		}
		else
		{
			cout<<"\nOrdered items are : ";
			
			for (int i=0;i<p;i++)
			{
				item=order[front];
				if (front==rear)
				{
					front=rear=-1;
				}
				else
				{
					front=(front+1)%size;
				}
				cout<<"\t"<<item;
			}
			
			cout<<"\nTotal bill generated as : "<<p*100;
			cout<<"\nPlease pay the bill at Counter No. 05\nThank you & Visit again!!"<<endl;
		}
	}


	void pend_orders()
	{
		int temp;
		
		if (order_empty())
		{
			cout<<"\nThere are no pending orders!"<<endl;
		}
		else
		{
			temp=front;
			cout<<"Pending orders found !\nOrders are : "<<endl;

			while (temp!=rear)
			{
				cout<<"\t"<<order[temp];
				temp=(temp+1)%size;
			}
			cout<<"\t"<<order[temp];
		}
	}


};

int main()
{
	Pizza p;
	int ch,k,n;
	char ans;
	
	do
	{
		cout<<"\n***************Welcome to Italiano Pizzeria***************"<<endl;
		cout<<"1.Accept Orders\n2.Make payment\n3.Check for pending orders"<<endl;
		cout<<"Enter your choice :"<<endl;
		cin>>ch;
	
		switch(ch)
		{
			case 1:
				cout<<"Kindly enter the pizza you want to order from the menu card :"<<endl;
				cout<<"*******MENU CARD*******"<<endl;
				cout<<"1.Ultimate Veggie Pizza\n2.Cheese Spread Pizza\n3.Spicy Cheese Pizza"<<endl;
				cin>>k;
				p.take_order(k);
				break;
			case 2:
				cout<<"\nEnter the no. of pizzas ordered :"<<endl;
				cin>>n;
				p.bill_payment(n);
				break;
			case 3:
				p.pend_orders();
				break;
			default:
				cout<<"Wrong choice entered! Please Try again!!"<<endl;
				break;
			

		}

		cout<<"Do you want to continue?"<<endl;
		cout<<"1.Press y for yes/n2.Press n to exit"<<endl;
		cin>>ans;
	}while(ans=='y');
	
	return 0;


}



Output:-

***************Welcome to Italiano Pizzeria***************
1.Accept Orders
2.Make payment
3.Check for pending orders
Enter your choice :
1
Kindly enter the pizza you want to order from the menu card :
*******MENU CARD*******
1.Ultimate Veggie Pizza
2.Cheese Spread Pizza
3.Spicy Cheese Pizza
1
Do you want to continue?
1.Press y for yes/n2.Press n to exit
y

***************Welcome to Italiano Pizzeria***************
1.Accept Orders
2.Make payment
3.Check for pending orders
Enter your choice :
1
Kindly enter the pizza you want to order from the menu card :
*******MENU CARD*******
1.Ultimate Veggie Pizza
2.Cheese Spread Pizza
3.Spicy Cheese Pizza
2
Do you want to continue?
1.Press y for yes/n2.Press n to exit
y

***************Welcome to Italiano Pizzeria***************
1.Accept Orders
2.Make payment
3.Check for pending orders
Enter your choice :
2

Enter the no. of pizzas ordered :
2

Ordered items are :     1       2
Total bill generated as : 200
Please pay the bill at Counter No. 05
Thank you & Visit again!!
Do you want to continue?
1.Press y for yes/n2.Press n to exit
y

***************Welcome to Italiano Pizzeria***************
1.Accept Orders
2.Make payment
3.Check for pending orders
Enter your choice :
3

There are no pending orders!
Do you want to continue?
1.Press y for yes/n2.Press n to exit
n


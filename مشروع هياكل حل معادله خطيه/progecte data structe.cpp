#include<iostream>
#include<stdlib.h>
#include <conio.h>
using namespace std;
void screen ();
void print(struct node* head);
void polyAdd(struct node* head1,struct node* head2);
void polyMult(struct node* head1,struct node* head2);
void polyMin(node* head1, node* head2);
void removeDuplicates(node* start);
void delete_zero( struct node *head3);
node*sea(node*head,int ex );
node*insert_first(node*head,node*p);
struct node*insert(struct node*head,float co ,int ex );
struct node*create(struct node*head);
struct node
{
	float coeff;
	int expo;
	struct node*link;
};


                  
int main()
{
   int p;
    node* head1=NULL;
    node* head2=NULL;
  cout<<"Enter the the first polynomial \n";
  head1=create(head1);
  cout<<" if you need to Add press 1 \n min press  2 \n multi press 3 \n ";
  cin>>p;
  cout<<"Enter the the seconed polynomial \n";
  head2=create(head2);
   cout<<"\n";
  print(head1);
  if(p==1)
   cout<<"   +  \n ";
 else if(p==2)
   cout<<"    - \n ";
 else if(p==3)
   cout<<"    * \n ";
  print(head2);
  cout<<"------------------- \n";
   	if(p==1) 
   	{
	  polyAdd(head1,head2);
	  cout<<"we add ";}
 else if(p==2)
 {
   polyMin(head1,head2);
 }
   
 else if(p==3)
 {
   polyMult(head1,head2);
 }

   return 0;	
	
		
}
void print(struct node* head){
	if(head==NULL)
	  cout<<"No polynomial. ";
	else
	{
		struct node*temp=head;
		while(temp !=NULL)
		{
			cout<<"("<<temp->coeff<<"x^"<<temp->expo<<")";
			temp=temp->link;
			if(temp!=NULL)
			  cout<<"+";
			else 
			  cout<<"\n";
			
			    
		}
    }   
}
void polyAdd(struct node* head1,struct node* head2)
{
// head1 point to the first node in poly1
// head2 point to the seconde node in poly2
  	 node* ptr1=head1;//made ptr1 = head1
     node* ptr2=head2;
	 node* head3=NULL;//head3 point to the firest node in the resultant
	 
	 
	while(ptr1!=NULL && ptr2!=NULL)
	{
		if(ptr1->expo==ptr2->expo)// if is equal added them
		{
		 head3=insert(head3,ptr1->coeff+ptr2->coeff,ptr1->expo);
		 ptr1= ptr1->link;// made ptr 1 and 2 to the link node 
		 ptr2=ptr2->link;
	
		}
		else if(ptr1->expo > ptr2->expo)// if expo greater than expo 
		{
			head3=insert(head3,ptr1->coeff,ptr1->expo);//insert the node pointer by ptr1 in the resultant
			ptr1=ptr1->link;// and make ptr1 point to the link node
		}
		else if(ptr1->expo < ptr2->expo)//if expo lesess than expo 
		{
			head3=insert(head3,ptr2->coeff,ptr2->expo);//insert the node pointer by ptr2 in the resultant
			ptr2=ptr2->link;// and make ptr2 point to the link node
		}
		else 
		{
			static int i = 1;
			cout << "The result of adding :  "<< ptr1->coeff << "X^" << ptr1->expo << "  +  " << ptr2->coeff<<"X^"
			<<ptr2->expo <<" is :  "<<ptr1->coeff + ptr2->coeff  <<"X^"<<ptr1->expo <<endl; 
			i++;
			head3=insert(head3 ,ptr1->coeff+ptr2->coeff,ptr1->expo);
			ptr1 =ptr1->link;
			ptr2 =ptr2->link;
		} 
	}
	while(ptr1!=NULL)// repeat until ptr equal null
	{
		head3=insert(head3,ptr1->coeff,ptr1->expo);//insert the remaning node 
		ptr1=ptr1->link;
	}
	while(ptr2!=NULL)
	{
		head3=insert(head3,ptr2->coeff,ptr2->expo);
		ptr2=ptr2->link;
	}
    removeDuplicates(head3);
    delete_zero(head3);
	print(head3);

	
	}
	
	void polyMult(struct node* head1,struct node* head2)
	{
		
	 node* ptr1=head1;
     node* ptr2=head2;
	 node* head3=NULL;
	if(head1==NULL||head2==NULL)
	{
	cout<<"No polynomial \n";
		return;
		}	
	while(ptr1!=NULL)
	{ 
    	while(ptr2!=NULL)
	   { 
	      static int i = 1;
			cout << "The result of multipulation :  "<< ptr1->coeff << "X^" << ptr1->expo << "  *  " << ptr2->coeff<<"X^"
			<<ptr2->expo <<" is :  "<<ptr1->coeff * ptr2->coeff  <<"X^"<<ptr1->expo + ptr2->expo <<endl; 
			i++;
	      head3=insert(head3,ptr1->coeff*ptr2->coeff,ptr1->expo+ptr2->expo);
		  ptr2=ptr2->link;
    	}	
    
	ptr1=ptr1->link;
	ptr2=head2;// update ptr2 to head   
	 }
	 removeDuplicates(head3);
	 delete_zero(head3);
	 print(head3);
	
	}
	
void polyMin( node* head1, node* head2)
{
struct node* ptr1=head1;
     node* ptr2=head2;
	 node* head3=NULL;
	while(ptr1!=NULL && ptr2!=NULL)
	{
		if(ptr1->expo==ptr2->expo)
		{
		 head3=insert(head3,ptr1->coeff-ptr2->coeff,ptr1->expo);
		 ptr1= ptr1->link;
		 ptr2=ptr2->link;	
		}
		else if(ptr1->expo > ptr2->expo)
		{
			head3=insert(head3,ptr1->coeff,ptr1->expo);
			ptr1=ptr1->link;
		}
		else if(ptr1->expo < ptr2->expo)
		{
			head3=insert(head3,ptr2->coeff,ptr2->expo);
			ptr2=ptr2->link;
		}
		else 
		{
			static int i = 1;
			cout << "The result of subtraction:  "<< ptr1->coeff << "X^" << ptr1->expo << "  -  " << ptr2->coeff<<"X^"
			<<ptr2->expo <<" is :  "<<ptr1->coeff - ptr2->coeff  <<"X^"<<ptr1->expo <<endl; 
			i++;
			head3=insert(head3 ,ptr1->coeff - ptr2->coeff,ptr1->expo);
			ptr1 =ptr1->link;
			ptr2 =ptr2->link;
		} 
	}
	while(ptr1!=NULL)
	{
		head3=insert(head3,ptr1->coeff,ptr1->expo);
		ptr1=ptr1->link;
	}
	while(ptr2!=NULL)
	{
		head3=insert(head3,ptr2->coeff,ptr2->expo);
		ptr2=ptr2->link;
	}
	cout<<"Min polynomial is : ";
    removeDuplicates(head3);
    delete_zero(head3);
	print(head3);

}
// Function to add coefficients of
// two elements having same powerer
void removeDuplicates(node* start)
{
    node *ptr1, *ptr2, *dup;
    ptr1 = start;
 
    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->link != NULL) {
        ptr2 = ptr1;
 
        // Compare the picked element
        // with rest of the elements
        while (ptr2->link != NULL) {
 
            // If powerer of two elements are same
            if (ptr1->expo == ptr2->link->expo) {
 
                // Add their coefficients and put it in 1st element
                ptr1->coeff = ptr1->coeff + ptr2->link->coeff;
                dup = ptr2->link;
                ptr2->link = ptr2->link->link;
 
                // remove the 2nd element
                delete (dup);
            }
            else
                ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
        
    }}
void delete_zero( struct node *head3)
{
	struct node *ptr=head3;
	struct node *temp;
	while (ptr->link != NULL)
	{
		if (ptr->link->coeff == 0)
		{
			temp =ptr->link;
			ptr->link = temp->link;
			temp->link = NULL;
			free (temp);
		}
		ptr = ptr->link;
	}
} 
void screen ()
{
	cout <<"Press any key of the following : \n";
	cout <<" 1 - To enter the first polynomial .\n";
	cout <<" 2 - To enter the second polynomial .\n";
	cout <<" 3 - To do operations of the polynoimal .\n";
	cout <<" 4 - To exit .\n";
}
node*sea(node*head,int ex )
{
	node*t;
	t=head;
	while(t->link!=NULL&&t->link->expo>=ex)
	t=t->link;
	return t;
}
struct node*insert(struct node*head,float co ,int ex )
{
    node*t;
    node*temp;
    node*newp =new struct node; //malloc(sizeof());
    newp->coeff=co;
    newp->expo=ex;
    newp->link=NULL;
    
	if(head==NULL||ex>head->expo)//compare the ex of new node with the expo of the first node  
	{
	   newp->link=head;// made head link(new node)  equal to seconed node
	   head=newp;//the first node wil be equal to head 
	}
	else
	{ 
        t=sea(head,ex);
	    temp=head;
	    while(temp->link !=NULL && temp->link->expo>ex)
	    temp=temp->link;
	    newp->link=temp->link;
		temp->link=newp;   
		
	}
 	return head;
}
	struct node*create(struct node*head)
{
    int n;//store the number of items
	int i;
	int coeff;
	int expo;
	cout<<"Enter the number of term: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter the coeff for term" <<i+1<<":";
		cin>>coeff;
		cout<<"Enter the expo for term" <<i+1<<":";
		cin>>expo;
		head=insert(head,coeff,expo);
		
	}
    return head;	
} 

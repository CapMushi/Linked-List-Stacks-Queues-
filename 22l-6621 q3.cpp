#include <iostream>
using namespace std;
#include <stack>
#include <queue>

template <class t>
class node{
	public:
		t data;
		node<t>*next;
		
	node(t data):data(data){}	
	node()
	{
		next=NULL;
	}
		
};

template <class t>
class linkedlist{
	public:
	node<t>*head=NULL;
	
	
		bool isEmpty(){
			if (head==NULL) 
			 return true;
			return false;	
		}
		int length()
		{
			if(!isEmpty())
			{
				node<t>*temp=head;int l=0;
				while(temp->next!=NULL) //we are directly using temp as we want to reach last element
				{
					temp=temp->next;
					l++;
				}
				return l;	
			}
			return -1;	
		}
		
		t nodedata(int index)
		{
			node<t>*temp=head;int i=0;
			while (i<index && temp->next!=NULL)
			{
				temp=temp->next;
				i++;
			}
			return temp->data;	
		}
		
		void insertionfront(t data)
		{
			node<t>*nn=new node<t>(data);
			if (isEmpty())
			{
				head=nn;
				nn->next=NULL;	
			}
			else
			{
				node<t>*temp=head;
				head=nn;
				nn->next=temp;
			}
			cout<<"Node added at start"<<endl;
				
		}
		void insertionback(t data)
		{
			node<t>*nn=new node<t>(data);
			if (isEmpty())
				head=nn;
			else
			{
				node<t>*temp=head;
				while (temp->next!=NULL)
				{
					temp=temp->next;	
				}
				temp->next=nn;	//old empty now point to the address of new
			}
			nn->next=NULL;
			cout<<"Node added at back"<<endl;
				
		}
		void insertionatindex(t data,int idx)
		{
			if (isEmpty()||idx==0)
			 insertionfront(data);
			 
			else if(idx==length()+1)
			 insertionback(data);
			 
			else if(idx>0 && idx<=length()) //eg if length is 3 and user enters 3 now 3rd node moved to 4th and new node
			{                                 // added at 3 index
			    node<t>*nn=new node<t>(data);
			    node<t>*temp=head;
			    int i=0;
				while(i<idx-1)
				{
					temp=temp->next; //in secondlast we will have address of required will return -1 ith of required
					i++; //if idx=1 l=2 and i=1 then will not work 0th node returned 
						
				}
				nn->next=(temp->next);//important
				temp->next=nn;
				cout<<"Node added in middle"<<endl;
			}
			else
			 cout<<"Entered index is out of bounds"<<endl;
			 	
		}
		void deletionfront()
		{
			if(!isEmpty())
			{
				node<t>*temp=head;
			    temp=temp->next;
			    delete head;
			    head=temp;	
			    cout<<"Front node deleted"<<endl;
			}
			else  
			 cout<<"Linked List is Empty"<<endl;	
		}
		void deletionback()
		{
			if(!isEmpty())
			{
				if(length()==0)
				{
					delete head;
					head=NULL;
				}
				else
				{
					int l=0;
					node<t>*temp=head;
				    while(temp->next->next!=nullptr)
				    {
				    	temp=temp->next;
				    	l++;
					}
					delete temp->next;
					temp->next=NULL;
					cout<<"Last Node deleted"<<endl;	
				}	
			}
			else  
			 cout<<"Linked List is Empty"<<endl;
			
		}
		void deletionbyindex(int idx)
		{
			if(!isEmpty())
			{
				if(idx==0)//deletion start
			     deletionfront();
	            else if(idx==length())
			     deletionback();
				else if(idx>0 && idx<length())
				{
					node<t>*temp1=head;int i=0;
					while (i<idx-1)//works for 1 less than required
					{
						temp1=temp1->next;
						i++;
					}
					node<t>*temp2=temp1->next->next;
					delete temp1->next;
					temp1->next=temp2;
					cout<<"Node deleted in the middle"<<endl;	
				}		
			}
			else
			 cout<<"Linked List is Empty"<<endl;	
		}
		
		void display()
		{
			if(!isEmpty())
			{
				node<t>*temp=head;int c=1;
			    while(temp!=NULL)
			    {
					stack<queue<int>> stackcopy=temp->data;
					while (!(stackcopy.empty()))
					{
						queue<int> queuecopy=stackcopy.top();
						while(!(queuecopy.empty()))
						{
							cout<<queuecopy.front()<<"  ";
							queuecopy.pop();
						}
						cout<<endl;
						stackcopy.pop();
					}
					c++;
					temp=temp->next;
					cout<<"||"<<endl;
					cout<<"\\\/"<<endl;	
			    }
				cout<<"NULL"<<endl;	
			}
			else  
			 cout<<"Linked List is Empty"<<endl;
			cout<<"length is: "<<length()+1<<endl;//length basically shows index from 0 but only here counting from 1
		}
		

		
		~linkedlist()
		{
			node<t>*temp=head;int n=1;
			while(temp!=NULL) //or loop deletion front
			{
				temp=temp->next;
				delete head;
				head=temp;
				cout<<"Node "<<n<<" deleted"<<endl;
				n++;
			}
		}
		
		void insertionatindexstack(int idx)
		{
			int sizeq,element;
			queue<int> queuecopy;
			node<t>*temp=head;
			for(int i=1;i<idx;i++)
			{
				temp=temp->next;
			}
			cout<<"Enter elements you want to enter for queue: "<<endl;
			cin>>sizeq;
			
			for(int i=0;i<sizeq;i++)
			{
				cout<<"Enter value for queue at "<<i+1<<endl;
				cin>>element;
				queuecopy.push(element);	
			}
			if (sizeq>0)
			{
				(temp->data).push(queuecopy);
				cout<<"Queue added at specific index: "<<endl;
			}
			else
			 cout<<"Invalid size for queue "<<endl;	
		}
		
		void insertionatindexqueue(int idxs,int idxq)
		{
			bool qexist=false;
			int sizeq,element;
			stack<queue<int>> stackrev;
			stack<queue<int>> orgstack;
			node<t>*temp=head;
			for(int i=1;i<idxs;i++)
			{
				temp=temp->next;
			}
			int i=1;
			while(!((temp->data).empty()))
			{
				if(i==idxq)
				{
					cout<<"Enter elements you want to enter for queue: "<<endl;
					cin>>sizeq;
					qexist=true;
					for(int i=0;i<sizeq;i++)
					{
						cout<<"Enter value for queue at "<<i+1<<endl;
						cin>>element;
						((temp->data).top()).push(element);
					}
					
				}
				stackrev.push((temp->data).top());
				(temp->data).pop();
				i++;
			}
			
			while(!(stackrev.empty()))
			{
				orgstack.push(stackrev.top());
				stackrev.pop();
			}
			temp->data=orgstack;
			if(!qexist)
			 cout<<"Entered queue number does not exist."<<endl;
			else
			 cout<<"Queue Updated"<<endl;
		}
		
		void deletionfromstack(int idx)
		{
			int popqn;
			if(!isEmpty())
			{
				
				node<t>*temp=head;
				for(int i=1;i<idx;i++)
				{
					temp=temp->next;
				}
				cout<<"How many queues you want to delete from the specified stack"<<endl;
				cin>>popqn;
				for(int i=0;i<popqn && !((temp->data).empty());i++)
				{
					(temp->data).pop();
				}
				if(popqn>0)
				{
					cout<<"Queues deleted from a specified stack."<<endl;
					if((temp->data).empty())
					{
						deletionbyindex(idx-1);
					}
				}
				else
				 cout<<"Invalid number for queues deletion entered."<<endl;			
			}
			else
			 cout<<"Linked List is Empty"<<endl;	
		}
		
		void deletionfromqueue(int idxs,int idxq)
		{
			bool qexist=false,qempty=false;
			int popqn;
			stack<queue<int>> stackrev;
			stack<queue<int>> orgstack;
			node<t>*temp=head;
			for(int i=1;i<idxs;i++)
			{
				temp=temp->next;
			}
			int i=1;
			while(!((temp->data).empty()))
			{
				if(i==idxq)
				{
					cout<<"Enter how many elements you want to pop from specific queue. "<<endl;
					cin>>popqn;
					qexist=true;
					for(int i=0;i<popqn && !(((temp->data).top()).empty());i++)
					{
						((temp->data).top()).pop();
					}
					if((((temp->data).top()).empty()))
					 qempty=true;
					
				}
				if(!qempty)
				 stackrev.push((temp->data).top());
				(temp->data).pop();
				i++;
			}
			
			while(!(stackrev.empty()))
			{
				orgstack.push(stackrev.top());
				stackrev.pop();
			}
			
			temp->data=orgstack;
			if((temp->data).empty())
			{
				deletionbyindex(idxs-1);
			}
			if(!qexist)
			 cout<<"Entered queue number does not exist."<<endl;
			else
			 cout<<"Queue Updated"<<endl;
		}
		
		void sortallqueues()
		{
			stack<queue<int>> stackrev;//as we have to traverse through stack with popping
			
			node<t>*temp=head;
			if(!isEmpty())
			{
				while(temp!=NULL)
				{
					while(!((temp->data).empty()))//clearing stack of queues
					{
						//start
						queue<int> q1;
						queue<int> q2;
						queue<int> q3;
						for (int i = 0; !(((temp->data).top()).empty()); i++)
						{
							if (i == 0)
							{
								q1.push(((temp->data).top()).front());
								((temp->data).top()).pop();
							}
							else
							{
								if (!(((temp->data).top()).empty()) && ((temp->data).top()).front() <= q1.front())
								{
									while (!q1.empty())
									{
										q2.push(q1.front());
										q1.pop();
									}
									q1.push(((temp->data).top()).front());
									((temp->data).top()).pop();
									while (!q2.empty())
									{
										q1.push(q2.front());
										q2.pop();
									}
								}
								else
								{
									while (!q1.empty() && ((temp->data).top()).front() > q1.front())
									{
										q2.push(q1.front());
										q1.pop();
									}
									while (!q1.empty())
									{
										q3.push(q1.front());
										q1.pop();
									}
									while (!q2.empty())
									{
										q1.push(q2.front());
										q2.pop();
									}
									q1.push(((temp->data).top()).front());
									((temp->data).top()).pop();
									while (!q3.empty())
									{
										q1.push(q3.front());
										q3.pop();
									}
								}
							}
						}
						while (!q1.empty())
						{
							((temp->data).top()).push(q1.front());
							q1.pop();
						}
					    // queue sorted
					    stackrev.push((temp->data).top());
					    (temp->data).pop();
				
			     	}
			     	while (!stackrev.empty()) {
				        (temp->data).push(stackrev.top());//opp of reversing
				        stackrev.pop();
				    }
		     	    temp=temp->next;
			   }
			   cout<<"All queues sorted"<<endl;
			}
			else
			 cout<<"Linked List is Empty"<<endl;
		}
		
		void sortallstacks()
		{
			node<t>*temp=head;
			if(!isEmpty())
			{
				while(temp!=NULL)
				{
					
					stack <queue<int>> s1;
					
				    while (!((temp->data).empty()))
					{
			
				        int tempval = ((temp->data).top()).front();
				        queue<int> q1=((temp->data).top());
				        (temp->data).pop();
				
				        while (!s1.empty() && (s1.top()).front() > tempval)
						{
				            (temp->data).push(s1.top());
				            s1.pop();
				        }
				        s1.push(q1);
				    }
				    while (!s1.empty())
				    {
				        (temp->data).push(s1.top());
				        s1.pop();
				    }
				    temp=temp->next;
				}
				cout<<"All stacks sorted"<<endl;
				
			}
			else
			 cout<<"Linked List is Empty"<<endl;
		}
		
		
		void sortnodes()
		{
			if(!isEmpty())
			{
				node<t>*temp;stack <queue<int>> stor;int ind=0;bool swap=true;
				while(swap==true)
				{
					temp=head;//important as after every pass have to start from 0th
					swap=false;//if this unchanged not a single swap took place
					while(temp->next!=NULL)
					{
						if((((temp->data).top()).front())>(((temp->next->data).top()).front()))
						{
							swap=true;
							stor=temp->data;
							temp->data=temp->next->data;
							temp->next->data=stor;								
							ind++;
						}	
						temp=temp->next;	
					}
				}
				if (ind!=0)
				 cout<<"Linked List sorted"<<endl;	
				else
				 cout<<"Linked List is ALREADY sorted"<<endl;	
			}
			else
			 cout<<"Linked list is Empty so cannot be sorted"<<endl;	 
		}
};


int main()
{
	linkedlist<stack<queue<int>>> myList; // Change the type (int) as needed
	int option;

    while (true) {
        cout << "Stack Menu:" << endl;
        cout << "1. Create a new stack and add it to the linked list" << endl;
        cout << "2. Insert in a stack at a specific node" << endl;
        cout << "3. Insert in a specific queue of a stack(node)" << endl;
        cout << "4. Delete a Node" << endl;
        cout << "5. Delete from a specific stack" << endl;
        cout << "6. Delete from a queue" << endl;
        cout << "7. Sort All Queues" << endl;
        cout << "8. Sort All Stacks" << endl;
        cout << "9. Sort Nodes" << endl;
        cout << "10. Sort Linked List" << endl;
        cout << "11. Display the linked list of stacks" << endl;
        cout << "12. Quit" << endl;
        cout << "Enter your choice (1/2/3/4/5/6/7): ";
        cin >> option;

        switch (option) {
            case 1: {
                stack<queue<int>> newStack;
                int element,sizes,sizeq;
                cout << "Enter no elements for the new stack you want to enter: "<<endl;
                cin>>sizes;
                for(int i=0;i<sizes;i++) {
                	cout<<"Enter no of elements of queue you want to enter: "<<endl;
                    cin >> sizeq;
                    queue<int> newQueue;
                    for(int j=0;j<sizeq;j++)
                    {
                    	cout<<"Enter element at: "<<i+1<<endl;
						cin>>element; 
                    	newQueue.push(element);
					}
                    newStack.push(newQueue);
                    
                }
                if(sizes>0)
                {
                	myList.insertionback(newStack);
                    cout << "New stack added to the linked list." << endl;
				}
				else
				 cout << "No stack added invalid size" << endl;
                break;
            }
            
             case 2: {
              
               int n;
               cout<< "Enter node number at which you want to insert in stack:" << endl;
               cin>>n;
               if(n>0 && n<=(myList.length()+1))
               {
               	
               	 myList.insertionatindexstack(n);
               	
			   }
               else
               {
               	 cout<<"Entered node number does not exist in linked list"<<endl;
			   }
                break;
            }
            
            case 3: {
              
               int n,qn;
               cout<< "Enter stack number at which you want to insert" << endl;
               cin>>n;
               if(n>0 && n<=(myList.length()+1))
               {
	               cout<< "Enter queue number at which you want to insert" << endl;
	               cin>>qn;
               	
               	    myList.insertionatindexqueue(n,qn);
               	
			   }
               else
               {
               	 cout<<"Entered node number does not exist in linked list"<<endl;
			   }
                break;
            }
            case 4: {
              
                myList.deletionback();
                break;
            }
            
            case 5: {
              
               int n;
               cout<< "Enter node number at which you want to delete from stack:" << endl;
               cin>>n;
               if(n>0 && n<=(myList.length()+1))
               {
               	
               	 myList.deletionfromstack(n);
               	
			   }
               else
               {
               	 cout<<"Entered node number does not exist in linked list"<<endl;
			   }
                break;
            }
            
             case 6: {
              
               int n,qn;
               cout<< "Enter stack number at which you want to delete from" << endl;
               cin>>n;
               if(n>0 && n<=(myList.length()+1))
               {
	               cout<< "Enter queue number at which you want to delete from" << endl;
	               cin>>qn;
               	
               	    myList.deletionfromqueue(n,qn);  	
			   }
               else
               {
               	 cout<<"Entered node number does not exist in linked list"<<endl;
			   }
                break;
            }
            
             case 7: {
                myList.sortallqueues();
                break;
            }
            
             case 8: {
                myList.sortallstacks();
                break;
            }
            
             case 9: {
                myList.sortnodes();
                break;
            }
            
            case 10: {
                myList.sortallqueues();
                myList.sortallstacks();
                myList.sortnodes();
                break;
            }
            
             case 11: {
                myList.display();
                break;
            }

            case 12: {
                cout << "Exiting the program." << endl;
                return 0;
            }

            default: {
                cout << "Invalid choice. Please enter a valid option (1/2/3/4)." << endl;
            }
        }
    }

   
    system("pause");
    return 0;
}

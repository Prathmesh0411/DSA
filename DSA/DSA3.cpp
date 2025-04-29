#include<iostream>
#include<string.h>

using namespace std;

struct node
{
	string label;
	int ch_count;
	struct node *child[10];
}*root;

class GT
{
public:
	void create_tree();
	void display(node *r1);
	GT()
	{root=NULL;}
};

void GT::create_tree()
{
	int tbooks,tchapters,i,j,k;
	root=new node;
	cout<<"\nEnter name of the book:";
	cin.get();
	getline(cin,root->label);
	cout<<"\nEnter the number of chapters in book:";
	cin>>tchapters;
	root->ch_count=tchapters;
	for(i=0;i<tchapters;i++)
		{
		root->child[i]=new node;
		cout<<"\nEnter the name of chapters "<<i+1<<" :";
		cin.get();
		getline(cin,root->child[i]->label);
		cout<<"\nEnter the number of sections in chapter=>"<<root->child[i]->label<<":";
		cin>>root->child[i]->ch_count;
		for(j=0;j<root->child[i]->ch_count;j++)
			{
			root->child[i]->child[j]=new node;
			cout<<"\nEnter the name of section "<<j+1<<" :";
			cin.get();
			getline(cin,root->child[i]->child[j]->label);
			}
		}
}

void GT::display(node *r1)
{
int i,j,k,tchapters;
if(r1!=NULL)
	{
	cout<<"\n-----BOOK HIERARCHY-----";
	cout<<"\nBook Title:"<<r1->label;
	tchapters=r1->ch_count;
	for(i=0;i<tchapters;i++)
		{
		cout<<"\nChapters "<<i+1;
		cout<<"  :"<<r1->child[i]->label;
		cout<<"\nSections : ";
		for(j=0;j<r1->child[i]->ch_count;j++)
			{
			cout<<"\n"<<r1->child[i]->child[j]->label;
			}
		}
	}
cout<<endl;
}

int main()
{
int choice;
GT gt;
int ch=1;
	while(ch==1)
	{
	cout<<"\n------------------"<<endl;
	cout<<"\nBook Tree Creation"<<endl;
	cout<<"\n------------------"<<endl;
	cout<<"\n1.Create"<<endl;
	cout<<"\n2.Display"<<endl;
	cout<<"\n3.Quit"<<endl;
	cout<<"\nEnter your choice:";
	cin>>choice;
	switch(choice)
		{
		case 1:
			gt.create_tree();
			break;
		case 2:
			gt.display(root);
			break;
		case 3:
			cout<<"\nThanks for using this program."<<endl;
			ch=0;
			break;
		default:
			cout<<"!!Wrong Choice!!"<<endl;
			break;
		}
	}
return 0;
}

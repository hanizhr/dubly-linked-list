#include<iostream>
using namespace std;

class node {
public:
	int data;
	node* next;
	node* prev;
	node(int x=0) { next = NULL; prev = NULL; data = x; }
};

class linkedList {
public:
	friend void meno();
	node *head;
	linkedList() { head = NULL; }
	bool inseartFront(int x);              //ok
	bool inseartBack(int x);                //ok
	bool insertRegular(int x);            //ok
	node* search(int x);                  //ok                
	bool delet(int x);                  //ok
	void print();                        //ok
	bool deletAllX(int x);             //ok
	node* copy( node*a);                    //ok  //creat another linked list and return head of it
	bool recCompear(node*a,node* b);          //ok
	node* merge(node* a,node*b);
	void recPritn(node* a);              //ok
	bool recSearch(node* a, int x);         //ok
};

node* linkedList::merge(node* a, node*b) {
	linkedList c;
	c.head = NULL;
	while (a->next) {
		if(!c.search(a->data))
			c.insertRegular(a->data);
		a = a->next;
	}
	if (!c.search(a->data))
		c.insertRegular(a->data);
	while (b->next) {
		if (!c.search(b->data))
			c.insertRegular(b->data);
		b= b->next;
	}
	if (!c.search(b->data))
		c.insertRegular(b->data);
	return c.head;
}

//problem: for prev pointer
node* linkedList::copy(node* head)
{
	if (head == NULL) {
		return NULL;
	}
	else {
		node* newNode = new node(head->data);
		newNode->next = copy(head->next);
		return newNode;
	}
}

bool linkedList::recCompear(node* a, node* b) {
	if (a->next == NULL && b->next == NULL) {
		if(a->data==b->data)
			return true;
		return false;
	}
	//if (a->next || b->next)
	//	return false;
	if (a->data == b->data)
		recCompear(a->next, b->next);
	//return false;
}

bool linkedList::insertRegular(int x) {
	node* new_node = new node(x);
	//indert to first node , linked list is empty
	if (head == NULL) {
		//new_node->next = new_node->prev = NULL;
		//new_node->data = x;
		head = new_node;
		return true;
	}
	//insert befor head
	if (x < head->data) {
		//inseartFront(x);
		head->prev = new_node;
		new_node->next = head;
		new_node->prev = NULL;
		head = new_node;
		return true;
	}
	//insert after another node , in the middel of linked list
	node* ptr = head;
	while (x > ptr->data && ptr->next != NULL) {
		ptr = ptr->next;
	}
	if (ptr->next == NULL) {
		ptr->next = new_node;
		new_node->prev = ptr;
		new_node->next = NULL;
		return true;
	}
	else
	{
		new_node->next = ptr;
		new_node->prev = ptr->prev;
		ptr->prev = new_node;
		return true;
	}
	//new_node->data = x;
	return false;
}

bool linkedList::inseartFront(int x) {
	node *new_node = new node(x);
	if (head == NULL) {
		new_node->next = new_node->prev = NULL;
		head = new_node;
		return true;
	}
	new_node->next = head;
	head->prev = new_node;
	head = new_node;
	return true;
}

bool linkedList::inseartBack(int x) {
	node* new_node = new node(x);
	if (head == NULL) {
		new_node->next = new_node->prev = NULL;
		head = new_node;
		return true;
	}
	node* temp = head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new_node;
	new_node->prev = temp;
	new_node->next = NULL;
	return true;
}

node* linkedList::search(int x) {
	if (head == NULL || head->data == x) {
		return head;
	}
	node* temp = head;
	while (temp->data != x && temp->next!=NULL) {
		temp = temp->next;
	}
	if (temp->data == x)
		return temp;
	return NULL;
}

bool linkedList::recSearch(node* a, int x) {
	if (a->data == x)
		return true;
	if (a->next == NULL)
		return false;
	recSearch(a->next, x);
}

bool linkedList::delet(int x) {
	node* temp = head;
	if (temp->data == x) {
		temp->next->prev = NULL;
		head = temp->next;
		return true;
	}
	while (temp->next != NULL) {
		if (temp->data == x)
			break;
		temp = temp->next;
	}
	if (temp->data == x) {
		if(temp->next !=NULL)
			temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		return true;
	}
	
	return false;
}

bool linkedList::deletAllX(int x) {
	node* temp = head;
	if (temp->data == x) {
		temp->next->prev = NULL;
		head = temp->next;
	}
	while (temp->next != NULL) {
		if (temp->data == x)
		{
			if (temp->data == x) {
				if (temp->next != NULL)
					temp->next->prev = temp->prev;
				if (temp->prev == NULL)
				{
					temp->next->prev = NULL;
					head = temp->next;
				}
				else
					temp->prev->next = temp->next;
			}
		}
		temp = temp->next;
	}
	if (temp->data == x) {
		temp->prev->next = NULL;
	}
	

	return true;
}

void linkedList::print() {
	node* temp = head;
	while (temp->next!=NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout <<temp->data<< endl;
}

void linkedList::recPritn(node* a) {
	if (a == NULL) 
		return;
	recPritn(a->next);
	cout << a->data << " ";
}

void cls() {
	for (int i = 0; i < 100; i++) {
		cout << endl;
	}
}
//meno:
void meno() {
	cout << "----------------------------------------------------------------------------" << endl;
	cout << "Inter a Number:" << endl;
	int x=0,y=0;
	linkedList ll;
	while (x!=14) {
		cout << "----------------------------------------------------------------------------" << endl;
		cout << "1.insert at first" << endl;
		cout << "2.insert at end" << endl;
		cout << "3.regular insert" << endl;
		cout << "4.search" << endl;
		cout << "5.delet one x" << endl;
		cout << "6.delet all x" << endl;
		cout << "7.print" << endl;
		cout << "8.copy" << endl;
		cout << "9.compear" << endl;
		cout << "10.recursive print" << endl;
		cout << "11.recursive search" << endl;
		cout << "12.merge" << endl;
		cout << "13.clean screen" << endl;
		cout << "14.Exit" << endl;

		cin >> x;
		switch (x)
		{
		case 1:
		{
			cout << "inter your number:" << endl;
			cin >> y;
			ll.inseartFront(y);
			cls();
			break;
		}
		case 2:
		{
			cout << "inter your number:" << endl;
			cin >> y;
			ll.inseartBack(y);
			cls();
			break;
		}
		case 3:
		{
			cout << "inter your number:" << endl;
			cin >> y;
			ll.insertRegular(y);
			cls();
			break;
		}
		case 4:
		{
			cout << "inter your number:" << endl;
			cin >> y;
			cls();
			cout << ll.search(y) << endl;
			break;
		}
		case 5:
		{
			cout << "inter your number:" << endl;
			cin >> y;
			cls();
			cout << ll.delet(y) << endl;
			break;
		}
		case 6:
		{
			cout << "inter your number:" << endl;
			cin >> y;
			cls();
			cout << ll.deletAllX(y) << endl;
			break;
		}
		case 7:
		{
			cls();
			ll.print();
			cout << endl;
			break;
		}
		case 8:
		{
			linkedList l2;
			l2.head = ll.copy(ll.head);
			cls();
			cout << "copy is succesfuly:" << endl;
			l2.print();
			cout << endl;
			break;
		}
		case 9:
		{
			linkedList l3;
			cls();
			cout << "creat a linked list with insert at front to compear whit current linked list" << endl;
			cout << "how many node do you have:" << endl;
			int n;
			cin >> n;
			int xx;
			for (int i = 0; i < n; i++) {
				cout << "inter your node data:" << endl;
				cin >> xx;
				l3.inseartFront(xx);
			}
			if (ll.recCompear(ll.head, l3.head) == 1)
				cout << "true"<<endl;
			else
				cout << "false"<<endl;
			break;
		}
		case 10:
		{
			cls();
			ll.recPritn(ll.head);
			cout << endl;
			break;
		}
		case 11:
		{
			cls();
			cout << "inter your number:" << endl;
			cin >> y;
			cout << ll.recSearch(ll.head, y) << endl;
			break;
		}
		case 12:
		{
			linkedList l4;
			cls();
			cout << "creat a linked list whit regular insert to compear whit current linked list" << endl;
			cout << "how many node do you have:" << endl;
			int nn;
			cin >> nn;
			int xxx;
			for (int i = 0; i < nn; i++) {
				cout << "inter your node data:" << endl;
				cin >> xxx;
				l4.insertRegular(xxx);
			}
			linkedList l5;
			l5.head = ll.merge(ll.head, l4.head);
			l5.print();
			break;
		}
		case 13:
		{
			cls();
			break;
		}
		case 14:
		{
			break;
		}
		default:
			break;
		}
	}
}

int main() {
	/*meno();*/

	linkedList list;

	list.inseartBack(3);
	list.inseartBack(4);
	list.inseartBack(5);

	std::cout << list.recSearch(list.head, 6);
	return 0;
}
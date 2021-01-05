#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

class Quadrilateral
{
private:
	double length1, length2, width1, width2;
	static int count;
public:
	Quadrilateral();
	Quadrilateral(const double& len1, const double& len2, const double& wid1, const double& wid2);
	Quadrilateral(const Quadrilateral&);
	~Quadrilateral();

	double getLength1() const;
	double getLength2() const;
	double getWidth1() const;
	double getWidth2() const;

	virtual string getType() const;
	static int getCount();

	void setLength1(const double& len1);
	void setLength2(const double& len2);
	void setWidth1(const double& wid1);
	void setWidth2(const double& wid2);

	double getArea() const;
	double getPerimeter() const;

	virtual void printInfo(ostream&) const;
	bool operator == (const Quadrilateral& q) const;
	friend ostream& operator << (ostream& out, const Quadrilateral& q);
};
int Quadrilateral::count = 0;
typedef Quadrilateral* QuadPtr;

class Trapezoid : public Quadrilateral 
{
	// trapezoid has length1(a), len2(b), and height(h)

public:

	Trapezoid();
	Trapezoid(const double& len1, const double& len2, const double& wid);
	Trapezoid(const Trapezoid&);

	double getLength1() const { return Quadrilateral::getLength1(); }
	double getLength2() const { return Quadrilateral::getLength2(); }
	double getWidth() const {return this->getWidth1();}
	double getWidth1() const { return Quadrilateral::getWidth1(); }
	double getWidth2() const { return Quadrilateral::getWidth2(); }

	virtual string getType() const;

	void setLength1(const double& len1) { Quadrilateral::setLength1(len1); }
	void setLength2(const double& len2) { Quadrilateral::setLength2(len2); }
	void setWidth(const double& wid) 
	{
		Quadrilateral::setWidth1(wid);
		Quadrilateral::setWidth2(wid);
	}
	void setWidth1(const double& wid1) { this->setWidth(wid1); }
	void setWidth2(const double& wid2) { this->setWidth(wid2); }

	double getArea() const { return Quadrilateral::getArea(); }
	double getPerimeter() const { return Quadrilateral::getPerimeter(); }


	virtual void printInfo(ostream&) const;
	bool operator == (const Trapezoid& q) const;
};

class Rectangle : public Trapezoid 
{
public:
	//Constructors
	Rectangle();
	Rectangle(const double& len, const double& wid);
	Rectangle(const Rectangle&);

	//Getters
	double getLength() const { return Trapezoid::getLength1(); }
	double getWidth() const { return Trapezoid::getWidth(); }
	double getLength1() const { return this->getLength(); }
	double getLength2() const { return this->getLength(); }
	double getWidth1() const { return Trapezoid::getWidth(); }
	double getWidth2() const { return Trapezoid::getWidth(); }

	virtual string getType() const;

	//Setters
	void setLength(const double& len) 
	{
		Trapezoid::setLength1(len);
		Trapezoid::setLength2(len);
	}
	void setWidth(const double& wid) 
	{
		Trapezoid::setWidth1(wid);
		Trapezoid::setWidth2(wid);
	}

	void setLength1(const double& len1) { this->setLength(len1); }
	void setLength2(const double& len2) { this->setLength(len2); }
	void setWidth1(const double& wid1) { this->setWidth(wid1); }
	void setWidth2(const double& wid2) { this->setWidth(wid2); }

	//Other member functions
	double getArea() const { return Quadrilateral::getArea(); }
	double getPerimeter() const { return Quadrilateral::getPerimeter(); }

	virtual void printInfo(ostream&) const;
	bool operator == (const Rectangle&) const;
};

class Square : public Rectangle 
{
public:
	Square();
	Square(const double& side);
	Square(const Square&);

	//Getters
	double getSide() const {return this->getLength1();}
	double getLength1() const { return Rectangle::getLength1(); }
	double getLength2() const { return Rectangle::getLength2(); }
	double getWidth1() const { return Rectangle::getWidth1(); }
	double getWidth2() const { return Rectangle::getWidth2(); }

	virtual string getType() const;

	//Setters
	void setLength(const double& len) { this->setSide(len); }
	void setWidth(const double& wid) { this->setSide(wid); }
	void setSide(const double& side) {
		Rectangle::setLength(side);
		Rectangle::setWidth(side);
	}
	void setLength1(const double& len1) { this->setSide(len1); }
	void setLength2(const double& len2) { this->setSide(len2); }
	void setWidth1(const double& wid1) { this->setSide(wid1); }
	void setWidth2(const double& wid2) { this->setSide(wid2); }

	//area and perimeter:
	double getArea() const { return Quadrilateral::getArea(); }
	double getPerimeter() const { return Quadrilateral::getPerimeter(); }

	virtual void printInfo(ostream& out) const;
	bool operator == (const Square& s) const;
};

Quadrilateral::Quadrilateral()       //default constructor
{
	length1 = 1;
	length2 = 2;
	width1 = 3;
	width2 = 4;
	count++;
}
Quadrilateral::Quadrilateral(const double& len1, const double& len2, const double& wid1, const double& wid2)    //non default constructor
{
	setLength1(len1);
	setLength2(len2);
	setWidth1(wid1);
	setWidth2(wid2);
	count++;
}
Quadrilateral::Quadrilateral(const Quadrilateral& x)  //copy constructor
{
	this->setLength1(x.getLength1());
	this->setLength2(x.getLength2());
	this->setWidth1(x.getWidth1());
	this->setWidth2(x.getWidth2());
	count++;
}
Quadrilateral::~Quadrilateral() { count--; }      //destructor
double Quadrilateral::getLength1() const {
	return length1;
}
double Quadrilateral::getLength2() const {
	return length2;
}
double Quadrilateral::getWidth1() const {
	return width1;
}
double Quadrilateral::getWidth2() const {
	return width2;
}
string Quadrilateral::getType() const
{
	return "Quadrilateral";
}
int Quadrilateral::getCount()
{
	return count;
}
void Quadrilateral::setLength1(const double& len1) {
	length1 = len1;
}
void Quadrilateral::setLength2(const double& len2) {
	length2 = len2;
}
void Quadrilateral::setWidth1(const double& wid1) {
	width1 = wid1;
}
void Quadrilateral::setWidth2(const double& wid2) {
	width2 = wid2;
}
double Quadrilateral::getArea() const
{
	double h = sqrt(pow(width1, 2) - pow(0.5 * abs(length1 - length2), 2));
	return 0.5 * (length1 + length2) * h;
}
double Quadrilateral::getPerimeter() const
{
	return length1 + length2 + width1 + width2;
}
void Quadrilateral::printInfo(ostream& out) const
{
	out << setw(12) << getType() + ": ";
	out << "len1 = " << setprecision(2) << getLength1() << ", ";
	out << "len2 = " << setprecision(2) << getLength2() << ", ";
	out << "Wid1 = " << setprecision(2) << getWidth1() << ", ";
	out << "Wid2 = " << setprecision(2) << getWidth2() << ", ";
	out << "Area = " << setprecision(2) << getArea() << ", ";
	out << "Per. = " << setprecision(2) << getPerimeter();
}
bool Quadrilateral::operator == (const Quadrilateral& q) const    //equivalent operator
{
	if (this->getType() != q.getType())
		return false;
	double d1 = abs(this->length1 - q.length1);
	double d2 = abs(this->length2 - q.length2);
	double d3 = abs(this->width1 - q.width1);
	double d4 = abs(this->width2 - q.width2);
	if (d1 < 1.0e-6 && d2 < 1.0e-6 && d3 < 1.0e-6 && d4 < 1.0e-6)
		return true;
	else
		return false;
}
ostream& operator << (ostream& out, const Quadrilateral& q)  //ostream operator
{
	out.setf(ios::fixed | ios::left); //Left aligned fixed decimal places
	q.printInfo(out);
	out.unsetf(ios::fixed | ios::left); //Removing formatting
	out.precision(0); //Resetting the decimal places
	return out;
}


Trapezoid::Trapezoid() : Quadrilateral(1, 3, 2, 2)     //default constructor
{}
Trapezoid::Trapezoid(const double& len1, const double& len2, const double& wid) : Quadrilateral(len1, len2, wid, wid)  //non-default constructor
{
	double x = abs(getLength1() - getLength2()) / 2;
	while (getWidth() <= x)
		setWidth(2 * getWidth());
}
Trapezoid::Trapezoid(const Trapezoid& x) : Trapezoid(x.getLength1(),x.getLength2(),x.getWidth())  //copy constructor
{}
string Trapezoid::getType() const     
{
	return "Trapezoid";
}
void Trapezoid::printInfo(ostream& out) const
{
	out << setw(12) << getType() + ": ";
	out << "len1 = " << setprecision(2) << getLength1() << ", ";
	out << "len2 = " << setprecision(2) << getLength2() << ", ";
	out << "Wid = " << setprecision(2) << getWidth() << ", ";
	out << "Area = " << setprecision(2) << getArea() << ", ";
	out << "Per. = " << setprecision(2) << getPerimeter();
}
bool Trapezoid::operator == (const Trapezoid& t) const
{
	Quadrilateral q1(*this);
	Quadrilateral q2(t);
	if (q1 == q2)
		return true;
	else
		return false;
}


Rectangle::Rectangle() : Trapezoid(1, 1, 2)     //default constrcutor
{}
Rectangle::Rectangle(const double& len, const double& wid) : Trapezoid(len, len, wid)  //non-default constuctor
{}
Rectangle::Rectangle(const Rectangle& r): Trapezoid(r.getLength(), r.getLength(), r.getWidth())   //copy constuctor
{}
string Rectangle::getType() const
{
	return "Rectangle";
}
void Rectangle::printInfo(ostream& out) const
{
	out << setw(12) << getType() + ": ";
	out << "len = " << setprecision(2) << getLength() << ", ";
	out << "Wid = " << setprecision(2) << getWidth() << ", ";
	out << "Area = " << setprecision(2) << getArea() << ", ";
	out << "Per. = " << setprecision(2) << getPerimeter();
}
bool Rectangle::operator == (const Rectangle& q) const
{
	Trapezoid t1(*this);
	Trapezoid t2(q);
	if (t1 == t2)
		return true;
	else
		return false;
}

Square::Square() : Rectangle(1, 1)     //default constuctor
{}
Square::Square(const double& side) : Rectangle(side, side)   //non-default constructor
{}
Square::Square(const Square& s): Rectangle(s.getSide(),s.getSide())   //copy constructor
{}
string Square::getType() const
{
	return "Square";
}
void Square::printInfo(ostream& out) const
{
	out << setw(12) << getType() + ": ";
	out << "side = " << setprecision(2) << getSide() << ", ";
	out << "Area = " << setprecision(2) << getArea() << ", ";
	out << "Per. = " << setprecision(2) << getPerimeter();
}
bool Square::operator == (const Square& s) const
{
	Rectangle r1(*this);
	Rectangle r2(s);
	if (r1 == r2)
		return true;
	else
		return false;
}

class Node
{
	typedef Node* NodePtr;
private:
	QuadPtr data;
	NodePtr link;
public:
	Node();
	Node(const QuadPtr&);
	Node(const Node&);
	~Node();
	QuadPtr getData() const;
	NodePtr getLink() const;
	void setData(const QuadPtr&);
	void setLink(const NodePtr&);
	friend ostream& operator<< (ostream&, const Node&);
};
typedef Node* NodePtr;

Node::Node() : data(nullptr), link(nullptr) { }
Node::Node(const Node& n) : data(n.data), link(n.link) { }
Node::Node(const QuadPtr& d) : data(d), link(nullptr) { }
Node::~Node() { delete data; }
QuadPtr Node::getData() const { return data; }
NodePtr Node::getLink() const { return link; }
void Node::setData(const QuadPtr& d) { data = d; }
void Node::setLink(const NodePtr& p) { link = p; }
ostream& operator<< (ostream& out, const Node& n)
{
	out << *(n.data);
	return out;
}


class LinkedList
{
private:
	NodePtr head;
public:
	LinkedList();
	LinkedList(const LinkedList&);
	~LinkedList();
	LinkedList& operator= (const LinkedList&);
	int getSize() const; //Return the number of nodes in the linked list
	void head_insert(const QuadPtr&);
	NodePtr search_node(const QuadPtr&) const;
	void insert_after(const NodePtr&, const QuadPtr&) const;
	void remove_node(const NodePtr&);
	void remove_node(const QuadPtr&);
	void remove_all(const QuadPtr&);
	void tail_insert(const QuadPtr&);
	void insert_before(const NodePtr&, const QuadPtr&);
	void insert_increasing(const QuadPtr&);
	void insert_grouped(const QuadPtr&);
	void insert_grouped_increasing(const QuadPtr&);
	friend ostream& operator<< (ostream&, const LinkedList&); //This is already implemented for you
};

LinkedList::LinkedList()
{
	head = nullptr;
}
LinkedList::LinkedList(const LinkedList& ll)   
{
	if (ll.head == nullptr)
		return;

	NodePtr temp = ll.head->getLink();
	
	this->head = new Node;
	this->head->setData(ll.head->getData());
	this->head->setLink(nullptr);
	
	NodePtr paste_here = head;
	
	while(temp != nullptr) {

		NodePtr next = new Node;		
		next->setData(temp->getData());
		next->setLink(nullptr);

		paste_here->setLink(next);
		paste_here = paste_here->getLink();

		temp = temp->getLink();
	}	
}
LinkedList::~LinkedList()
{
	NodePtr temp;
	while (head != nullptr)
	{
		temp = head;
		head = head->getLink();
		delete temp;
	}
}
LinkedList& LinkedList::operator= (const LinkedList& ll)
{
	LinkedList L = LinkedList(ll);
	return L;
}
int  LinkedList::getSize() const
{
	NodePtr temp = head;
	int count = 0;
	while (temp != nullptr)
	{
		count++;
		temp = temp->getLink();
	}
	return count;
}
void LinkedList::head_insert(const QuadPtr& value)
{
	NodePtr n = new Node(value);
	n->setLink(head);
	head = n;
}
NodePtr LinkedList::search_node(const QuadPtr& value) const
{
	NodePtr temp = head;
	while (temp != nullptr)
	{
		if (temp->getData() == value)
			return temp;
		else
			temp = temp->getLink();
	}
	return nullptr;
}
void LinkedList::insert_after(const NodePtr& n, const QuadPtr& value) const
{
	if (n == nullptr)
		return;
	else
	{
		NodePtr temp = new Node(value);
		temp->setLink(n->getLink());
		n->setLink(temp);
	}
}
void LinkedList::remove_node(const NodePtr& n)
{
	if (head == nullptr || n == nullptr)//empty linked list or nullptr n
		return;
	else if (head == n)
	{
		head = head->getLink();
		delete n;
		return;
	}
	else
	{
		NodePtr b = head;
		while (b != nullptr)
		{
			if (b->getLink() == n) //found the node before n
			{
				b->setLink(n->getLink());
				delete n;
				return;
			}
			b = b->getLink();
		}
	}
}
void LinkedList::remove_node(const QuadPtr& value)
{
	NodePtr n = search_node(value);
	remove_node(n);
}
void LinkedList::remove_all(const QuadPtr& value)
{
	NodePtr n;
	while (true)
	{
		n = search_node(value);
		if (n == nullptr)
			break;
		remove_node(n);
	}
}
void LinkedList::tail_insert(const QuadPtr& value)
{
	if (head == nullptr)
		head_insert(value);
	else
	{
		//Find the last node in the linked list
		NodePtr b = head; //Here b is guaranteed to be not nullptr
		while (b->getLink() != nullptr)
			b = b->getLink();
		//Now insert after b
		insert_after(b, value);
	}
}
void LinkedList::insert_before(const NodePtr& n, const QuadPtr& value)
{
	//If the linked list is empty then insert only if n is nullptr too
	if (head == nullptr)
	{
		if (n == nullptr)
			head_insert(value);
		else
			cout << "Insertion failed. Bad node argument." << endl;
	}
	//If n is nullptr then tail_insert
	else if (n == nullptr)
		tail_insert(value);
	//If head is equal to n then head_insert
	else if (head == n)
		head_insert(value);
	//Find the node just before n and insert after it
	else
	{
		NodePtr b = head;
		while (b != nullptr)
		{
			if (b->getLink() == n)
				break;
			b = b->getLink();
		}
		if (b == nullptr)
			cout << "Insertion failed. Bad node argument." << endl;
		else
			insert_after(b, value);
	}
}
void LinkedList::insert_increasing(const QuadPtr& value)
{
	if (head == nullptr || head->getData()->getPerimeter() >= value->getPerimeter())
	{
		head_insert(value);
		return;
	}
	else
	{
		NodePtr temp = head;
		while (temp->getLink() != nullptr && temp->getData()->getPerimeter() < value->getPerimeter())
		{
			temp = temp->getLink();
		}
		if (temp->getLink() == nullptr)
			insert_after(temp, value);
		else
			insert_before(temp, value);
	}
}
void LinkedList::insert_grouped(const QuadPtr& value)
{
	if (head == nullptr || value->getType() == "Square")
	{
		head_insert(value);
	}
	else if (value->getType() == "Trapezoid")
	{
		tail_insert(value);
	}
	else
	{
		NodePtr temp = head;
		while (temp->getLink() != nullptr && temp->getLink()->getData()->getType() == "Square")
		{
			temp = temp->getLink();
		}
		if (temp->getData()->getType() == "Trapezoid")
			head_insert(value);
		else
			insert_after(temp, value);		
	}
}
void LinkedList::insert_grouped_increasing(const QuadPtr& value)
{

	if (head == nullptr)
	{
		head_insert(value);
	}
	else {
		NodePtr temp = head;
		bool flag=false;
		while(temp->getLink() != nullptr) 
		{
			while(temp->getLink() != nullptr && temp->getData()->getType() == value->getType()) {
				flag = true;
				if(temp->getData()->getPerimeter() >= value->getPerimeter()) {
					break;
				}
				temp = temp->getLink();
			}
			if(flag == true)
				break;
			
			temp=temp->getLink();
		}
		insert_before(temp, value);
	}
}

ostream& operator<< (ostream& out, const LinkedList& LL)  //output stream operator for linked list
{
	NodePtr temp = LL.head;
	while (temp != nullptr)
	{
		out << *temp << endl;
		temp = temp->getLink();
	}
	return out;
}
QuadPtr getRandomQuadrilateral()
{
	int r = rand() % 3;
	switch (r)
	{
	case 0:
		return new Trapezoid(rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1);
	case 1:
		return new Rectangle(rand() % 5 + 1, rand() % 5 + 1);
	default:
		return new Square(rand() % 5 + 1);
	}
}

int main()
{
	//Let us use the same seed in order to generate the same random numbers on all the lab computers
	//that use the same version of MSVC++. This way the output of this program on computers with the
	//same Visual Studio 2010 compiler will be identical to the output provided below so long as your
	//implementations are correct.
	unsigned int seed = 0;
	srand(seed); //Normally srand(time(0)) should be used for rigorous testing
	const int SIZE = rand() % 6 + 25;
	//Declare a linkedlist container to store pointers to Shape objects
	LinkedList LL;
	//Print the number of objects at the beginning
	cout << "At the beginning there are " << Quadrilateral::getCount() << " objects constructed." << endl;
	cout << "And there are " << LL.getSize() << " elements in the linkedlist container." << endl << endl;
	///////////////////////////////////// TASK 1 ///////////////////////////////////////////////////////
	//Insert SIZE random objects into the linked list container using head_insert member function
	cout << endl << "Inserting " << SIZE << " objects with insert_increasing member function" << endl;
	cout << "***********************************************************" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		QuadPtr p = getRandomQuadrilateral();
		cout << "Inserting " << endl << *p << endl;
		LL.insert_increasing(p);
	}
	//Print the number of objects constructed so far and the number of elements of the linked list container
	cout << endl << "Now there are " << Quadrilateral::getCount() << " objects constructed." << endl;
	cout << "And there are " << LL.getSize() << " elements in the linkedlist container." << endl << endl;
	//Print the elements of the linked list container
	cout << "The elements of the linkedlist container are" << endl;
	cout << LL << endl;
	//Now delete all the elements of the linked list container and also clear the linked list container
	cout << endl << "Emptying the linkedlist container." << endl;
	LL.~LinkedList();
	//Print the number of objects we still have in our application and in the linked list container
	cout << "Now there are " << Quadrilateral::getCount() << " objects constructed." << endl;
	cout << "And there are " << LL.getSize() << " elements in the linkedlist container." << endl << endl;
	///////////////////////////////////// TASK 2 ///////////////////////////////////////////////////////
	//Insert SIZE random objects into the linked list container using insert_grouped function
	cout << "Inserting " << SIZE << " objects with insert_grouped function" << endl;
	cout << "*************************************************" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		QuadPtr p = getRandomQuadrilateral();
		cout << "Inserting " << endl << *p << endl;
		LL.insert_grouped(p);
	}
	//Print the number of objects constructed so far and the number of elements of the linked list container
	cout << endl << "Now there are " << Quadrilateral::getCount() << " objects constructed." << endl;
	cout << "And there are " << LL.getSize() << " elements in the linkedlist container." << endl << endl;
	//Print the elements of the linked list container
	cout << "The elements of the linkedlist container are" << endl;
	cout << LL << endl;
	//Now delete all the elements of the linked list container and also clear the linked list container
	cout << endl << "Emptying the linkedlist container." << endl;
	LL.~LinkedList();
	//Print the number of objects we still have in our application and in the linked list container
	cout << "Now there are " << Quadrilateral::getCount() << " objects constructed." << endl;
	cout << "And there are " << LL.getSize() << " elements in the linkedlist container." << endl << endl;
	///////////////////////////////////// TASK 3 ///////////////////////////////////////////////////////
	//Insert SIZE random objects into the container using insert_grouped_sorted function
	cout << "Inserting " << SIZE << " objects with insert_grouped_increasing function" << endl;
	cout << "************************************************************" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		QuadPtr p = getRandomQuadrilateral();
		cout << "Inserting " << endl << *p << endl;
		LL.insert_grouped_increasing(p);
	}
	//Print the number of objects constructed so far and the number of elements of the linked list container
	cout << endl << "Now there are " << Quadrilateral::getCount() << " objects constructed." << endl;
	cout << "And there are " << LL.getSize() << " elements in the linkedlist container." << endl << endl;
	//Print the elements of the linked list container
	cout << "The elements of the linkedlist container are" << endl;
	cout << LL << endl;
	//Now delete all the elements of the linked list container and also clear the linked list container
	cout << endl << "Emptying the linkedlist container." << endl;
	LL.~LinkedList();
	//Print the number of objects we still have in our application and in the linked list container
	cout << "Now there are " << Quadrilateral::getCount() << " objects constructed." << endl;
	cout << "And there are " << LL.getSize() << " elements in the linkedlist container." << endl << endl;
	system("Pause");
	return 0;
}

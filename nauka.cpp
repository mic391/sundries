#include <iostream>
#include <string>

using namespace std;

class Ksztalt 
{
public:
	virtual ~Ksztalt()
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	
	virtual void rysuj() = 0;
};

class Kolo  : public Ksztalt
{
public:
	void rysuj()
	{
		cout << "Rysuje Kolo" << endl;
	}
	
	~Kolo()
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}	
};

class Kwadrat : public Ksztalt
{
public:
	void rysuj()
	{
		cout << "Rysuje Kwadrat" << endl;
	}
	
	~Kwadrat()
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}	
};

void rysowaczka(Ksztalt& a)
{
	a.rysuj();
}

int main()
{
	Ksztalt* a = new Kwadrat;
	a->rysuj();
	delete a;
		
	Kolo b;
	rysowaczka(b);
}

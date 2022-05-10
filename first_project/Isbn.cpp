# include "Isbn.h"



Isbn::Isbn(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
	///@param a is EAN_prefix
	/// @param b is reg_group
	/// @param c is publication
	/// @param d is chek digit
	
	if (a > 999 || a < 100)
	{
		throw std::invalid_argument("EAN prefix should be a 3 digit number\n");
	}
	if (b > 99999)
	{
		throw std::invalid_argument("reg_group  should be at most 5 digit number\n");
	}
	if (c > 9999999)
	{
		throw std::invalid_argument("publication  should be at most 7 digit number\n");
	}
	if (d > 9)
	{
		throw std::invalid_argument("check digit  should be anumber between 0 and 9 \n");
	}
	this->EAN_prefix = a;
	this->reg_group = b;
	this->publication = c;
	this->check_digit = d;

}


Isbn::Isbn(const Isbn& other)
{
	this->EAN_prefix = other.EAN_prefix;
	this->reg_group = other.reg_group;
	this->publication = other.publication;
	this->check_digit = other.check_digit;
}

//! checks if two isbn are equal
bool Isbn :: operator== (const Isbn& other)
{
	return (this->EAN_prefix == other.EAN_prefix && this->reg_group == other.reg_group && this->publication == other.publication && this->check_digit == other.check_digit);
}



Isbn& Isbn ::operator = (const Isbn& other)
{
	if (this != &other)
	{
		this->EAN_prefix = other.EAN_prefix;
		this->reg_group = other.reg_group;
		this->publication = other.publication;
		this->check_digit = other.check_digit;

	}
	return *this;
}
//! input operator throws an exception if the Isbn is not valid 
std::istream& operator >> (std::istream& in, Isbn& n)
{
	
	try {
		
		"Every Isbn contains four numbers :\n";
		unsigned int a, b, c, d;
		std::cout << "Please enter the first number(it should be a 3 digit number)\n ";
		in >> a;
		std::cout<<"Please enter the second number(it should be a 5 digit number at most) \n ";
		in >> b;
		std::cout << "Please enter the third number(it should be a 7 digit number at most) \n ";
		in >> c;
		std::cout << "Please enter the third number(it should be bettween 0 and 9) \n ";
		in >> d;
		Isbn i(a, b, c, d);
		n = i;
		return in;
	}
	catch (const std::exception& e)
	{
		throw e;
	}
}
//! converts the number to a string 
String Isbn::to_string()
{
	String a;
	unsigned int b = this->EAN_prefix;
	unsigned int c = this->reg_group;
	unsigned int d = this->publication;
	unsigned int e = this->check_digit;
	while (b != 0)
	{
		a.push_back('0' + b % 10);
		b /= 10;
	}
	while (c != 0)
	{
		a.push_back('0' + c % 10);
		c /= 10;
	}
	while (d != 0)
	{
		a.push_back('0' + d % 10);
		d/= 10;
	}
	while (e != 0)
	{
		a.push_back('0' + e % 10);
		e /= 10;
	}
	String str;
	int ind = a.size() - 1;
	for (int i = ind; i >= 0; --i)
	{
		str.push_back(a[i]);
	}
	return str;
}
std::ostream& operator <<(std::ostream& out,const  Isbn& i)
{
	out << i.EAN_prefix<<"-"<< i.reg_group <<"-"<< i.publication<<"-"<<i.check_digit<<"\n";
	return out;
}

bool Isbn ::operator< (const  Isbn& other)
{
	if (this->EAN_prefix < other.EAN_prefix) return true;
	else if (this->reg_group < other.reg_group) return true;
	else if (this->publication < other.publication) return true;
	else if (this->check_digit < other.check_digit);
	else
	{
		return false;
	}
}
bool Isbn ::operator> (const   Isbn& other)
{
	if (this->EAN_prefix > other.EAN_prefix) return true;
	else if (this->reg_group > other.reg_group) return true;
	else if (this->publication > other.publication) return true;
	else if (this->check_digit > other.check_digit);
	else
	{
		return false;
	}
}
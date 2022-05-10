#pragma once
# include "String.h"
# include <iostream>
struct Isbn
{
	Isbn()= default;
	Isbn(unsigned int, unsigned int, unsigned int, unsigned int);
	Isbn(const Isbn&);

	friend std::istream& operator >> (std::istream&, Isbn&);
	Isbn& operator = (const Isbn& other);
	bool operator ==( const Isbn& other);
	String to_string();
	bool operator < ( const Isbn&);
	bool operator > (const Isbn&);
	friend std::ostream& operator <<(std::ostream&, const Isbn&);

private :
	
	unsigned int EAN_prefix{0};
	unsigned int reg_group{ 0 };
	unsigned int publication{ 0 };
	unsigned int check_digit{ 0 };
};


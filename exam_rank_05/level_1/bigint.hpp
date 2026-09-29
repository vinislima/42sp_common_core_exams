#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>

class bigint {
private:
	std::string d; // digits, least-significant first, never has trailing (leading) zeros

	void	trim();
	size_t	to_size_t() const;

public:
	bigint();
	bigint(unsigned long long n);
	bigint(const bigint& c);
	bigint& operator=(const bigint& c);
	~bigint();

	friend std::ostream& operator<<(std::ostream& os, const bigint& b);

	bigint& operator++();
	bigint  operator++(int);

	bigint  operator+(const bigint& b) const;
	bigint& operator+=(const bigint& b);

	bigint  operator<<(const bigint& b) const;
	bigint  operator>>(const bigint& b) const;
	bigint& operator<<=(const bigint& b);
	bigint& operator>>=(const bigint& b);

	bool operator==(const bigint& b) const;
	bool operator!=(const bigint& b) const;
	bool operator<(const bigint& b) const;
	bool operator>(const bigint& b) const;
	bool operator<=(const bigint& b) const;
	bool operator>=(const bigint& b) const;
};

#endif

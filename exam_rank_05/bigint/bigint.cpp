#include "bigint.hpp"

void bigint::trim() {
	while (d.size() > 1 && d[d.size() - 1] == '0')
		d.erase(d.size() - 1);
}

size_t bigint::to_size_t() const {
	size_t r = 0;
	for (size_t i = d.size(); i-- > 0; )
		r = r * 10 + (d[i] - '0');
	return r;
}

bigint::bigint() : d("0") {}

bigint::bigint(unsigned long long n) {
	do {
		d += static_cast<char>((n % 10) + '0');
		n /= 10;
	} while (n);
}

bigint::bigint(const bigint& c) : d(c.d) {}
bigint& bigint::operator=(const bigint& c) { d = c.d; return *this; }
bigint::~bigint() {}

std::ostream& operator<<(std::ostream& os, const bigint& b) {
	for (size_t i = b.d.size(); i-- > 0; )
		os << b.d[i];
	return os;
}

bigint& bigint::operator++() { return *this += bigint(1); }
bigint  bigint::operator++(int) { bigint t = *this; ++(*this); return t; }

bigint bigint::operator+(const bigint& b) const {
	bigint r;
	r.d.clear();
	size_t n = d.size() > b.d.size() ? d.size() : b.d.size();
	for (size_t i = 0, carry = 0; i < n || carry; ++i) {
		size_t sum = carry;
		if (i < d.size())   sum += d[i] - '0';
		if (i < b.d.size()) sum += b.d[i] - '0';
		r.d += static_cast<char>((sum % 10) + '0');
		carry = sum / 10;
	}
	return r;
}

bigint& bigint::operator+=(const bigint& b) { return *this = *this + b; }

bigint bigint::operator<<(const bigint& b) const {
	if (d == "0") return *this;
	bigint r = *this;
	r.d.insert(0, b.to_size_t(), '0');
	return r;
}

bigint bigint::operator>>(const bigint& b) const {
	size_t s = b.to_size_t();
	if (s >= d.size()) return bigint();
	bigint r = *this;
	r.d.erase(0, s);
	r.trim();
	return r;
}

bigint& bigint::operator<<=(const bigint& b) { return *this = *this << b; }
bigint& bigint::operator>>=(const bigint& b) { return *this = *this >> b; }

bool bigint::operator==(const bigint& b) const { return d == b.d; }
bool bigint::operator!=(const bigint& b) const { return !(*this == b); }

bool bigint::operator<(const bigint& b) const {
	if (d.size() != b.d.size())
		return d.size() < b.d.size();
	for (size_t i = d.size(); i-- > 0; )
		if (d[i] != b.d[i])
			return d[i] < b.d[i];
	return false;
}

bool bigint::operator>(const bigint& b) const  { return b < *this; }
bool bigint::operator<=(const bigint& b) const { return !(b < *this); }
bool bigint::operator>=(const bigint& b) const { return !(*this < b); }

#pragma once
#include <iostream>

struct InacBit {

	union value
	{
		bool za;//for zero (FALSE) and alpha (TRUE) bit values
		bool bg;//for beta (FALSE) and gamma (TRUE) bit values
		bool o;//placing if InacBit has value 1  (FALSE)
	};

	union type
	{
		bool even; // even (TRUE) InacBits may have _beta_ value
		bool sag; // not even InacBits turn _beta_ value into _alpha_ value (FALSE) or _gamma_ value (TRUE)
	};

private:
	value val;
	type t;
	bool unreliable = 0;
	bool inaccurate = 0;

public:

	InacBit(value v_, type t_) : val(v_), t(t_) {};

	InacBit() {
		val.za = 0; // default IncaBit has ZERO value
		t.even = 1; // default IncaBit is even inacbit
	}
	
	//use to create not even InacBit with value ZERO, sag to alpha (FALSE) or gamma (TRUE)
	InacBit(bool sag) {
		val.za = 0; // default IncaBit has ZERO or FALSE value
		t.sag = sag;
	}

	enum Values
	{
		_ZERO = 0, _ALPHA = 1, _BETA = 2, _GAMMA = 3, _ONE = 4
	};

	InacBit(Values val_, bool even = true) {
		switch (val_)
		{
		case (_ZERO):
			val.za = false;
				break;
		case (_ALPHA):
			val.za = true;
			break;
		case (_BETA):
			val.bg = false;
			break;
		case (_GAMMA):
			val.bg = true;
			break;
		case (_ONE):
			val.o = false;
			break;
		default:
			val.o = false;
			break;
		}
	}

	/*
	Values value;
	*/

	//arithmetic
	InacBit operator= (const InacBit &b) {
		if (&b == this) return *this;
		return InacBit(b.val, b.t);
	}

	InacBit operator+ (const InacBit &b) {

	}

	InacBit operator- (const InacBit &b) {

	}

	InacBit operator* (const InacBit &b) {

	}

	InacBit operator/ (const InacBit &b) {

	}

	InacBit operator% (const InacBit &b) {

	}

	InacBit operator++ () {

	}

	InacBit operator++ (int) {

	}

	InacBit operator-- () {

	}

	InacBit operator-- (int) {

	}

	//unary

	InacBit operator- () {}
	InacBit operator+ () {}

	//arithmetic INT

	InacBit operator= (int i) {
		if (&b == this) return *this;
		return InacBit(b.val, b.t);
	}

	InacBit operator+ (int i) {

	}

	InacBit operator- (int i) {

	}

	InacBit operator* (int i) {

	}

	InacBit operator/ (int i) {

	}

	InacBit operator% (int i) {

	}

	//arithmetic complex
	InacBit operator+= (int i) {	}
	InacBit operator-= (int i) {	}
	InacBit operator*= (int i) {	}
	InacBit operator/= (int i) {	}
	InacBit operator%= (int i) {	}

	

	//comparison

	const bool operator < (const InacBit &b) {	}
	const bool operator > (const InacBit &b) {	}
	const bool operator == (const InacBit &b) {	}
	const bool operator <= (const InacBit &b) {	}
	const bool operator >= (const InacBit &b) {	}
	const bool operator != (const InacBit &b) {	}

	//cast

	operator bool() {

	}

	operator char() {

	}

	//logic

	const bool operator ! () {	}
	const bool operator && (const InacBit &b) {	}
	const bool operator || (const InacBit &b) {	}

	//byte

	InacBit operator ~ () {}
	InacBit operator & (const InacBit &b) {}
	InacBit operator | (const InacBit &b) {}
	InacBit operator ^ (const InacBit &b) {}

	friend std::ostream operator >> (std::ostream &s, const InacBit &b) {}
	friend std::istream operator << (std::istream &s, const InacBit &b) {}

	InacBit operator &= (const InacBit &b) {}
	InacBit operator |= (const InacBit &b) {}
	InacBit operator ^= (const InacBit &b) {}

	friend std::ostream operator >>= (std::ostream &s, const InacBit &b) {}
	friend std::istream operator <<= (std::istream &s, const InacBit &b) {}

	//pointers
	int operator[] (int n);
};


//28:44
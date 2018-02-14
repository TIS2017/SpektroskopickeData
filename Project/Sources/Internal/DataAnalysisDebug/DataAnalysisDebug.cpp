// DataAnalysisDebug.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "../Transformations/TransformationsLib.h"
using namespace DataAnalysis::Transformations;

// #include "../Utils/MathLib.h"
#include <iostream>

void getStr( size_t i, string &str ) {
	for ( size_t j = i ; j < i*i + 1; j++ ) {
		str.push_back( ( i*j ) % 256 );
	}
}

template < class Base = double > class Vector3 {
public:
	Base x, y, z;
};

class A {
public:
	virtual int foo( int a ) = 0;
	int foo( int a, int b ) {
		return a + b;
	}

	virtual int moo( int a, int b ) = 0;
	
	template <class T1, class T2> T1 goo( T1 a, T2 b ) {
		return moo( a, b );
	}
};

class B : public A {
public:
	// this hides foo with 2 arguments from A
	virtual int foo( int a ) {
		return 9 + a - a;
	}
	
	virtual int moo( int a, int b ) {
		return a * b;
	}
};

#include "../Transformations/HermitePolynomialProvider.h"

int main()
{
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );


    return 0;
}


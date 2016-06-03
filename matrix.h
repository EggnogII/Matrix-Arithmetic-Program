// Name: Imran Irfan
//Student ID: 910013902
//Email: imranbirfan@gmail.com or iirfan@sfsu.edu
//Compiler: Visual Studios 2013
#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
using namespace std;

class matrix{
	private:
	//data members
	vector< vector<int> > data;
	int dim;
	
	public:
	//constructors
		//default constructor
		matrix();
		//constructor to initialize a matrix by using values stored in a vector of vectors
		matrix(vector< vector<int> > d, int r);
	//member functions
		//print function
		//set number of rows and number of columns of a matrix and initializes elements to 0
		void setEmptyM(int d);
		//(return dimensionality)
		int rDim(); 
		//retrieve value at (i, j) position
		int rElem(int i, int j);
		int sElem(int i, int j, int v);
		//function to return transpose
		void transpose();

};


//Overloaded Operators
	//* to multiply two matrices based on equal dimensionality
matrix& operator*(matrix &m1, matrix m2);
	//* to multiply matrix by scalar	
matrix operator*(matrix &m, int s);
	//- to subtract two matrices based on equal dimensionality
matrix operator-(matrix &m1, matrix m2);
	//<< output in output stream
ostream& operator<<(ostream& out, matrix m);

#endif
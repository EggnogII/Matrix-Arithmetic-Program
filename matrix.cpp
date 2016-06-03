// Name: Imran Irfan
//Student ID: 910013902
//Email: imranbirfan@gmail.com or iirfan@sfsu.edu
//Compiler: Visual Studios 2013
#include "matrix.h"

matrix::matrix(){
	dim = 0;
}

matrix::matrix(vector< vector<int> > d, int r){
	dim = r;
	data.resize(dim);
	for (int i=0;i<dim;i++){
		data[i].resize(dim);
		for (int j=0;j<dim;j++){
			data[i][j] = d[i][j];
		}
	}
}

void matrix::setEmptyM(int d){
	dim = d;
	data.resize(dim);
	for (int i=0;i<dim;i++){
		data[i].resize(dim);
		for (int j=0;j<dim;j++){
			data[i][j] = 0;
		}
	}
}

int matrix::rDim(){
	return dim;
}

int matrix::rElem(int i, int j){
	return data[i][j];
}

int matrix::sElem(int i, int j, int v){
	data[i][j] = v;
	return data[i][j];
}

void matrix::transpose(){
	vector< vector<int> > copy;
	copy.resize(dim);
	for (int i=0;i<dim;i++){
		copy[i].resize(dim);
		for (int j=0;j<dim;j++){
			copy[i][j] = data[i][j];
				
		}
	}
	
	for (int i=0;i<dim;i++){
		for (int j=0;j<dim;j++){
			data[j][i] = copy[i][j];
		}
	}
}

//Overloaded Operators
	//* to multiply two matrices based on equal dimensionality
matrix& operator*(matrix &m1, matrix m2){
	int product;
	vector< vector<int> > temp1;
	vector< vector<int> > temp2;
	vector< vector<int> > temp3;
	int d=m1.rDim();
	int c=m2.rDim();
	if (d != c){
		cout << "Matrices of inequal dimensionality" << endl;
		}
			
	else if (d == c){
		temp1.resize(d);
		temp2.resize(d);
		temp3.resize(d);
		for (int i=0;i<d;i++){
			temp1[i].resize(d);
			temp2[i].resize(d);
			temp3[i].resize(d);
			for (int j=0;j<d;j++){
				temp1[i][j] = m1.rElem(i, j);
				temp2[i][j] = m2.rElem(i, j);
			}
		}
		
		
		for (int i=0;i<d;i++){
			for (int j=0;j<d;j++){
				int sum = 0;
				for (int k=0;k<d;k++){
					sum = sum +(temp1[i][k]*temp2[k][j]);
				}
				temp3[i][j] = sum;
			}
		}
		
		for (int i=0;i<d;i++){
			for (int j=0;j<d;j++){
				m1.sElem(i, j, temp3[i][j]);
			}
		}
	
	}
	return m1;
}
	//* to multiply matrix by scalar
	
matrix operator*(matrix &m, int s){
	int e;
	for (int i=0;i<m.rDim();i++){
		for (int j=0;j<m.rDim();j++){
			e = m.rElem(i, j);
			e = e*s;
			m.sElem(i, j, e);
		}
	}
	return m;
}
	//- to subtract two matrices based on equal dimensionality
	
matrix operator-(matrix &m1, matrix m2){
	int d = m1.rDim();
	int c = m2.rDim();
	vector< vector<int> > temp1;
	vector< vector<int> > temp2;
	vector< vector<int> > temp3;
	if (d != c){
		cout << "Unequal dimensionality." << endl;
	}
	else if (d == c){
		temp1.resize(d);
		temp2.resize(d);
		temp3.resize(d);
		for (int i=0;i<d;i++){
			temp1[i].resize(d);
			temp2[i].resize(d);
			temp3[i].resize(d);
			for (int j=0;j<d;j++){
				temp1[i][j] = m1.rElem(i, j);
				temp2[i][j] = m2.rElem(i, j);
				temp1[i][j] = temp1[i][j] - temp2[i][j];
				m1.sElem(i , j, temp1[i][j]);
			}
		}
	
	}

	return m1;
}
	//<< output in output stream
ostream& operator<<(ostream& out, matrix m){
	int x;
	for (int i=0; i<m.rDim();i++){
		for (int j=0;j<m.rDim();j++){
			x = m.rElem(i, j);
			out << "[" << x << "]";
		}
		out << endl;
	}
	return out;
}
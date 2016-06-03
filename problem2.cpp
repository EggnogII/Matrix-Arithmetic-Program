// Name: Imran Irfan
//Student ID: 910013902
//Email: imranbirfan@gmail.com or iirfan@sfsu.edu
//Compiler: Visual Studios 2013
#include "matrix.h"
#include <iostream>
using namespace std;

int main(){
	matrix m;
	vector< vector<int> > temp;
	vector< vector<int> > temp2;
	int d;
	int x;
	int s;
	char c;
	cout << "Enter dimensionality of a square matrix: ";
	cin >> d;
	cout << endl;
	temp.resize(d);
	for (int i=0;i<d;i++){
		temp[i].resize(d);
		for (int j=0;j<d;j++){
			cout << "Enter a value for the [" << i << "][" << j << "] element: ";
			cin >> x;
			temp[i][j] = x;
		}
	}
	matrix m2(temp, d);
	cout << m2;
	cout << endl;
	cout << "Multiply matrix by a scalar?[y/n]: ";
	cin >> c;
	if (c == 'y'){
		cout << "Enter a scalar to multiply the matrix: ";
		cin >> s;
		m2 = m2 * s;
		cout << endl;
		cout << m2;
		cout << endl;
	}
	
	cout << "Enter dimensionality of a 2nd square matrix: ";
	cin >> d;
	temp2.resize(d);
	for (int i=0;i<d;i++){
		temp2[i].resize(d);
		for (int j=0;j<d;j++){
			cout << "Enter a value for the [" << i << "][" << j << "] element: ";
			cin >> x;
			temp2[i][j] = x;
		}
	}
	matrix m3(temp2, d);
	cout << m3;
	cout << endl;
	cout << "Multiply Matrices?[y/n]: ";
	cin >> c;
	if (c == 'y'){
		m2 = m2 * m3;
		cout << endl;
		cout << m2;
		cout << endl;
	}
	
	cout << "Subtract Matrices?[y/n]: ";
	cin >> c;
	if (c == 'y'){
		m2 = m2-m3;
		cout << endl;
		cout << m2;
		cout << endl;
	}
	
	cout << "Acquire transpose for first matrix?[y/n]: ";
	cin >> c;
	if (c == 'y'){
	
		cout << "Generating transpose of first matrix." << endl;
		m2.transpose();
		cout << m2;
	}
	cout << "Reset first matrix?[y/n]: ";
	cin >> c;
	if (c == 'y'){
	
		cout << "Enter a new dimensionality for the first matrix. This will empty its current values: ";
		cin >> d;
		m2.setEmptyM(d);
		cout << m2;
	}
	
return 0;
}
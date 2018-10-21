#include <iostream> 
#include <vector> 
#include <fstream>
#include <cstring>
#include <cstdlib> 
#include <cstdio> 
#include <sstream>      
#include <string>
#include <random>
#include "lsh.h"

using namespace std; 

vector<double>* hash_function_v(int d){
	vector<double>* v;
    default_random_engine generator;
	normal_distribution<double> distribution(0.0,1.0);

	cout << "Hash function : ";
	for ( int i = 0 ; i < d ; i++){
		double number = distribution(generator);
		cout << "v" << i << " = " << number << endl;
	}
	return v;
}
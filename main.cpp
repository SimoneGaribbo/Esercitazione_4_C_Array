#include "Utils.hpp"
#include <iostream>
#include <fstream>
 
using namespace std;

int main()
{
	string input_file = "data.txt";
	int n;
	double S;
	double *w = nullptr;
    double *r = nullptr;
	
	bool a = ImportVectors(input_file, S, n, w, r);
	
	if (!a) {
		return 1;
	}
	
	double V = FinalValue(n, S, w, r);
	double ror= RateOfReturn(V, S);
	
	string output_file = "result.txt";
	bool b = ExportResult(output_file, n, S, w, r, V, ror);
	
	if (!b) {
		return 1;
	}
	
    return 0;
}


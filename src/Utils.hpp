#pragma once
#include <iostream>

using namespace std;

bool ImportVectors(const string& inputFilePath,
				   double& S,
                   int& n,
                   double*& w,
                   double*& r);
				   
double FinalValue (const int& n, 
					const double& S,
					const double * const& w,
					const double * const& r);
					
double RateOfReturn (double V, 
					const double& S);
				   
bool ExportResult(const string& outputFilePath,
                  const int& n,
                  const double& S,
				  const double * const& w,
				  const double * const& r,
				  const double& V,
				  const double& ror);
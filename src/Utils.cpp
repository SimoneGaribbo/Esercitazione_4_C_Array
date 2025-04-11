#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include <string>
#include <array>
#include <iomanip>
#include "sstream"

using namespace std;

bool ImportVectors(const string& inputFilePath,
				   double& S,
                   int& n,
                   double*& w,
                   double*& r)
{
	ifstream fstr(inputFilePath);
	
	if (fstr.fail()){
    return false;
	}
	
	std::string temp;
	getline(fstr, temp);
	int pos = temp.find(";");
	S = std::stod(temp.substr(pos+1, temp.size()));
	
	
	getline(fstr, temp);
	pos = temp.find(";");
	n = std::stoi(temp.substr(pos+1, temp.size()));
	
	getline(fstr, temp); 
	
	w = new double [n];
	r = new double [n];
	int i=0;
	while (getline(fstr, temp)) {
		pos = temp.find(";");
		
		w[i] = std::stod(temp.substr(0, pos));
		r[i] = std::stod(temp.substr(pos+1, temp.size()));
		i++;
	}
	return true;
	
}

double FinalValue (const int& n, 
					const double& S,
					const double * const& w,
					const double * const& r)
{
	double V=0;
	for (unsigned int i=0; i<n; i++) {
			V+=(1+r[i])*(w[i]*S);
	}
	
	return V;
}

double RateOfReturn (double V, 
					const double& S)
{
	double ror = (V/S) -1.0;
	return ror;
}							

bool ExportResult(const string& outputFilePath,
                  const int& n,
                  const double& S,
				  const double * const& w,
				  const double * const& r,
				  const double& V,
				  const double& ror)
{
    ofstream file;
    file.open(outputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    file << "S = " << fixed<<setprecision(2)<< S << ", n = "<< n << endl;
	file << "w = [ ";
	for (unsigned int i = 0; i<n; i++)
		file << w[i] << " ";
	file << "]" << endl;
	
	file << "r = [ ";
	for (unsigned int i = 0; i<n; i++)
		file << r[i] << " ";
	file << "]" << endl;
	
	file << "Rate of return of the portfolio : " << fixed << setprecision(4) << ror << endl;
	file << "V: " << fixed << setprecision(2) << V << endl;
	
	cout << "S = " << fixed<<setprecision(2)<< S << ", n = "<< n << endl;
	cout << "w = [ ";
	for (unsigned int i = 0; i<n; i++)
		cout << w[i] << " ";
	cout << "]" << endl;
	
	cout << "r = [ ";
	for (unsigned int i = 0; i<n; i++)
		cout << r[i] << " ";
	cout << "]" << endl;
	
	cout << "Rate of return of the portfolio : " << fixed << setprecision(4) << ror << endl;
	cout << "V: " << fixed << setprecision(2) << V << endl;

    return true;
}

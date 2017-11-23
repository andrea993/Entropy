#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <algorithm>

using namespace std;

const double LN2=log(2);

inline double log2(double x)
{
	return (x==0 ? 0 : log(x)/LN2);
}

inline double diffsat(double a, double b)
{
	return (a-b > 0 ? a-b : 0);
}


int main(int argc, char** argv)
{
	if (argc != 2)
	{
		cout<<"Usage:"<<endl<<"entropy [filename]" <<endl;
		return -1;
	}

	ifstream file(argv[1]);

	if (!file.is_open())
		throw logic_error("Unable to open file");

	unsigned char c;
	vector<double> f(256,0);

	double tot=0;
	double sum=0, sum2=0;

	while (file >> c)
	{
		f[c]++;
		sum += c;
		sum2 += c*static_cast<double>(c);
		tot++;
	}

	file.close();

	double mean=sum/tot;
	double var=(sum2 - sum*sum/tot)/(tot-1.0);
	double sigma=sqrt(var);

	double entropy=0.0;
	double unif=1/255.0;
	double unifP1=0, gaussP1=0;
	const double gausspt1=1.0/sqrt(2*M_PI*var);

	for (unsigned i=0; i<f.size(); i++)
	{
		f[i]/=tot;

		entropy -= f[i]*log2(f[i]);

		if (var > 0)
		{
			double gauss=gausspt1*exp(-0.5*(i-mean)*(i-mean)/var);
			gaussP1 += diffsat(f[i],gauss);
		}
		 unifP1 += diffsat(f[i],unif);

	}

	cout<< "FILE STATS" << endl <<
		"Mean:		"<< mean << endl <<
		"Variance:	"<< var << endl <<
		"Std dev:	"<< sigma << endl <<
		"Entropy:	"<< entropy << endl <<  
		"Gaussian:	"<< (1-gaussP1)*100 <<'%' << endl <<
		"Uniform:	"<< (1-unifP1)*100 <<'%' << endl; 

	return 0;


}

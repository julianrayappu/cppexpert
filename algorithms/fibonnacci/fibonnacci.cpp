
#include <iostream>
#include <ostream>
#include <vector>
#include <sstream>

using namespace std;

ostream& operator<<(ostream& lhs, const vector<int>& rhs)
{
	lhs << "{";
	int size = rhs.size();
	for (int i = 0; i < size; i++)
	{
		lhs << rhs.at(i) << ", ";
	}
	lhs << "}";
}


void fibonnacci(int n, vector<int>& sequence)
{
	int f0 = 0, f1 = 1;
	sequence.push_back(f0);
	sequence.push_back(f1);

	// fi = f(i-1) + f(i-2)
	int fn;
	for (int i=2; i < n; i++)
	{
		fn = sequence.at(i-1) + sequence.at(i-2);
		sequence.push_back(fn);
	}
	
}

vector<string> getargs(int argc, char** argv)
{
	vector<string> args;

	for (int i=0; i < argc; i++)
	{
		args.push_back(argv[i]);
		std::cout << "arg[" << i << "]=" << args[i] << std::endl;
	}

	return args;
}

template <typename T>
bool getargn(int argn, const vector<string>& args, T& arg)
{
	// fibonnacci arg1 arg2 arg3
	// 0	      1    2    3   = 4
	if (argn < args.size())
	{
		stringstream sstr(args.at(argn));
		sstr >> arg;
		cout << "getargn(" << argn << ")=" << arg << endl;
		return true;
	}
	
	return false;
}


int main(int argc, char** argv)
{
	
	vector<int> fibseq;
	int n;
	getargn(1, getargs(argc, argv), n);
	
	fibonnacci(n, fibseq);

	// print
	cout << "fibseq(" << n << ")=" << fibseq << endl;

	float ft;
	getargn(2, getargs(argc, argv), ft);
	cout << "float ft=" << ft << endl; 
}

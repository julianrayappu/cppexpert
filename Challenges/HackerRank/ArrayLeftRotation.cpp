
#include <iostream>
#include <vector>

using namespace std;

ostream& operator<<(ostream& lhs, const vector<int>& array);

vector<int> rotLeft(vector<int> a, int d) 
{
	vector<int> result(a.size());

	int size = result.size();
	for (int i = 0 ; i < size; i++)
	{
		result[i] = a[ (i+d) % size ];
	}

	return result;
}

ostream& operator<<(ostream& lhs, const vector<int>& array)
{
	lhs << "[";
	for (int val : array)
	{
		lhs << val << ", ";
	}
	lhs << "]";

	return lhs;
}

int main(int argc, char** argv)
{
	int n, d;
	
	cin >> n >> d ;
	cout << "array size n=" << n << ", left rotations d=" << d << endl;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "Initial array a=" << a << endl;

	vector<int> result = rotLeft(a, d);

	cout << "Result array, result=" << result << endl;

	return 0;
}


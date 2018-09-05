
#include <iostream>
#include <vector>

using namespace std;


int hourglassSum(const vector< vector<int> >& arr)
{
	// arr is a 6 x 6 2-d vector

	// pseudo-code
	// for each hourglass calculate its sum
	// if the sum is the largest so far, then save it as the maximum

	const int MINIMUM_SUM = -64; //(-9*7=-63)
	int maxSum = MINIMUM_SUM;
	int currentSum;

	int outerSize = arr.size();
	for (int y = 0; y < outerSize - 2; y++)
	{
		int innerSize = arr[y].size();
		for (int x = 0; x < innerSize - 2; x++)
		{
			// for this position we calculate the hourglass position as
			// x,y x+1,y x+2,y
			// x,y+1 x+1,y+1 x+2,y+1
			// x,y+2 x+1,y+2 x+2,y+2
			currentSum =   arr[y+0][x+0] + arr[y+0][x+1] + arr[y+0][x+2] 
						                 + arr[y+1][x+1]
						+  arr[y+2][x+0] + arr[y+2][x+1] + arr[y+2][x+2] ;

			maxSum = (currentSum > maxSum) ? currentSum : maxSum ; 
		}
	}

	return maxSum;
}

int main(int argc, char** argv)
{
	vector< vector<int> > arr;
	arr.resize(6);

	for (int i = 0; i < arr.size(); ++i)
	{
		arr[i].resize(6);

		for (int j = 0; j < arr[i].size(); ++j)
		{
			cin >> arr[i][j];
		}
	}	

	int maxSum = hourglassSum(arr);
	cout << "The maximum hourglass sum is " << maxSum << endl;
}
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double fillTetrahedron(int);
int main()
{
	int edgeOfTetrahedron;
	cout << "Enter edge length of tetrahedron in centimeters: ";
	cin >> edgeOfTetrahedron;

	cout << "The amount of water that can be filled in the tetrahedron is " << setprecision(5) << fillTetrahedron(edgeOfTetrahedron) <<" liters." << endl;
	return 0;
}
double fillTetrahedron(int edgeLength)
{
	double amountOfTetrahedron = 0;
	amountOfTetrahedron = (1/12.0 * sqrt(2.0) * pow((double)edgeLength, 3)) / 1000;
	return amountOfTetrahedron;
}
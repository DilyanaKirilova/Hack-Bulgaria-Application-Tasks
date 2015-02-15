#include<iostream>
#include<cmath>
using namespace std;

const int CAPACYTY = 100;
void fillEdgeLengthOfEachTetrahedron(int[CAPACYTY], int&);
int* sortTetrahedrons(int[CAPACYTY], int);
int maxFilledTetrahedrons(int*, int, int);
double fillTetrahedron(int edgeLength);

int main()
{
	int tetrahedrons[100];

	int numOfTetrahedrons;
	cout << "How many tetrahedrons you will try to fill? ";
	cin>>numOfTetrahedrons;

	fillEdgeLengthOfEachTetrahedron(tetrahedrons, numOfTetrahedrons);
	int *p = sortTetrahedrons(tetrahedrons,numOfTetrahedrons);

	int amountOfWater;
	cout << "Enter the amount of water you want to to fill the tetrahedrons: ";
	cin>>amountOfWater;

	cout <<"With that amount of water can be filled "<< maxFilledTetrahedrons(p,numOfTetrahedrons,amountOfWater) <<" tetrahedrons." <<endl;

	return 0;
}

void fillEdgeLengthOfEachTetrahedron(int tetrahedrons[CAPACYTY], int& numOfTetrahedrons)
{
	cout<<"Type in the edge length of each tetrahedron: ";
	for(int i = 0; i < numOfTetrahedrons; i++)
	{
		cin >> tetrahedrons[i];
	}
}

int* sortTetrahedrons(int arr[CAPACYTY], int numOfTetrahedrons)
{
	for(int i = 0; i < numOfTetrahedrons -1; i++)
	{
		int minElement = i;
		for(int j = i+1 ; j < numOfTetrahedrons; j++)
		{
			if(arr[j] < arr[i])
			{
				minElement = j;
			}
			int temp = arr[i];	
			arr[i] = arr[minElement];
			arr[minElement] = temp;
		}
	}
   return arr;
}

int maxFilledTetrahedrons(int* pTetrahedrons,int numOfTetrahedrons, int waterToFill)
{
	int filled = 0;
	for(int i = 0; i < numOfTetrahedrons; i++)
	{
		double amount = fillTetrahedron(pTetrahedrons[i]);
		if(amount < waterToFill)
		{
			filled++;
			waterToFill -= amount;
		}
	}
	return filled;
}

double fillTetrahedron(int edgeLength)
{
	double amountOfTetrahedron = 0;
	amountOfTetrahedron = (1/12.0 * sqrt(2.0) * pow((double)edgeLength, 3)) / 1000;
	return amountOfTetrahedron;
}
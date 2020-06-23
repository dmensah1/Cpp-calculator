#include <iostream>
using namespace std;

double calcAverage(char * values[], int sz) {
	cout << "Average" << endl;
	double sum = 0;
	double avg = 0;
	double *dynArray = NULL;						//new dynamic array created
	dynArray = new double[sz];

	for (int i = 0; i < sz; i++)
		dynArray[i] = atof(values[i]);				// vaues of the inputed array are passed onto the newy created dynamic array

	for (int x = 0; x < sz; x++)					//sum of the array is taken using the dynamic array
		sum = sum + dynArray[x];


	avg = sum / sz;									//avg is calculated then returned to the main function
	delete[] dynArray;								//dynamic array deleted to not waste memory space
	return avg;
}

 double calcSum(char *values[]) {
	cout << "Sum" << endl;
	double sz = 3;									//size of the array is dynamically created
	double sum = 0;

	for (int x = 0; x < sz; x++) {
		sum = sum + atof(values[x]);				//each array element is converted to a double value then added onto sum
	}
	return sum;										//value of sum returned to main function
}


double calcMedian(char *values[], int sz) {
	cout << "Median" << endl;
	double median;
	int position = sz / 2;
	double *dynArr = NULL;						  //dynamic array is created
	dynArr = new double[sz];

	for (int i = 0; i < sz; i++)				  //values of the original array are converted to double type then passed to the dynamic array
		*(dynArr + i) = atof(*(values + i));

	double temp;								  //through this nested-for block of code, the dynamic array gets sorted smallest to greatest
	for (int i = 0; i < sz; i++) {					 
		for (int e = 0; e < sz - 1; e++) {
			if (*(dynArr + e) > *(dynArr + e + 1)) {
				temp = *(dynArr + e);
				*(dynArr + e) = *(dynArr + e + 1);
				*(dynArr + e + 1) = temp;
			}
		}
	}

	if (sz % 2 == 0)										//if-statement to determine if the array has 1 or 2 values in the middle position
		median = (*(dynArr + position - 1) + *(dynArr + position)) / 2.0;        //average of middle 2 values is assigned to median
	else
		median = *(dynArr + position);						  //value of middle variable in array assigned to median if array size is an odd number

	delete[] dynArr;									 //dynamic array deleted
	return median;										//value of the variable "median" is returned to the main function
} 

int main(int argc, char *argv[]) {
	
		switch (argv[1][0]) {
		case 'A':
			double holdAverage;								 //dummy variable to hold returned value of the average

			holdAverage = calcAverage(&argv[2], argc - 2);
			for (int x = 0; x < argc - 2; x++) {            //array is printed
				cout << argv[x + 2] << " ";
			}

			cout << endl;
			cout << holdAverage << endl;           //value of the average is printed
			break;

		case 'F':
			double holdSum;									//declared dummy variable for which the returned value from the function will be assigned to
			if (argc - 2 == 3) {
				holdSum = calcSum(&argv[2]);
				for (int x = 0; x < argc - 2; x++) {            //array values are printed
					cout << argv[x + 2] << " ";
				}
				cout << endl;
				cout << holdSum << endl;						//value of the sum is printed
			}

			else {
				cout << "Invalid entry! Must only be 3 integers." << endl;
			}
			break;

		case 'M':
			double holdMedian;       //dummy variable to hold returned value of median
			holdMedian = calcMedian(&argv[2], argc - 2);

			for (int x = 0; x < argc - 2; x++)        //array is printed
				cout << argv[x + 2] << " ";

			cout << endl;
			cout << holdMedian << endl;      // value of median is printed

			break;
		}

	return 0;
} 
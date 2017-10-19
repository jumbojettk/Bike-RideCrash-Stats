// Napon Krassner
// CSC 2430, Homework 2
// 01-18-2015
// Due: 01-23-2015
// Name: Bike Ride and Crash Statistics
// Description: This program stores a week's worth of ride data for mountain bikers from
//				user's input and does calculations to output a report and chart for the
//				week's ride statistics.

// include libraries
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Define functions
void initArray(double[], int[], int);
void inputFillArray(double[], int[], int);
void inputFillArray(double[], int[], string[], int);
void calcMean(double[], int[], int, double&, double&);
void calcMaxMin(double[], int[], string[], int, double&, string&, double&, string&, int&, string&, int&, string&);
void printCrashBarChart(string[], int[], int, int);
void printWeeklyRideReport(double, double, double, string, double, string, int, string, int, string);

// Define constants
const int ARRAY_SIZE = 7;

int main()
{
	// Declare variables
	double arrayMilesPerDay[ARRAY_SIZE];
	int arrayCrashPerDay[ARRAY_SIZE];
	string arrayDaysOfWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	double meanMiles;
	double meanCrashes;
	double minMiles;
	string minMilesDay;
	double maxMiles;
	string maxMilesDay;
	int minCrashes;
	string minCrashesDay;
	int maxCrashes;
	string maxCrashesDay;

	// Utilize functions
	initArray(arrayMilesPerDay, arrayCrashPerDay, ARRAY_SIZE);  // Initialize arrays

	inputFillArray(arrayMilesPerDay, arrayCrashPerDay, arrayDaysOfWeek, ARRAY_SIZE);  // Fill arrays with user's input

	calcMean(arrayMilesPerDay, arrayCrashPerDay, ARRAY_SIZE, meanMiles, meanCrashes);  // Calculate mean for miles ridden and crashes in a week

	calcMaxMin(arrayMilesPerDay, arrayCrashPerDay, arrayDaysOfWeek, ARRAY_SIZE, minMiles, minMilesDay, maxMiles, maxMilesDay, minCrashes, minCrashesDay, maxCrashes, maxCrashesDay); // Calculate min max for miles and crashes and the day for those crashes

	printWeeklyRideReport(meanMiles, meanCrashes, minMiles, minMilesDay, maxMiles, maxMilesDay, minCrashes, minCrashesDay, maxCrashes, maxCrashesDay);// print weekly ride report from calcMean result

	printCrashBarChart(arrayDaysOfWeek, arrayCrashPerDay, ARRAY_SIZE, maxCrashes);  // Print crash chart by day in a week

	return 0;
}

// Parameters: array of doubles, array of ints, size of arrays
// Returns: nothing
// Initialize array of doubles (miles) and array of ints (crashes) to 0.0 and 0
void initArray(double milesArr[], int crashArr[], int size)
{
	for (int i = 0; i < size; i++)
		milesArr[i] = 0.0;

	for (int i = 0; i < size; i++)
		crashArr[i] = 0;
}

// Parameters: array of doubles, array of ints, size of arrays
// Returns: nothing
// Fill each array via keyboard from user, stops if array is full or input -1 for miles or crashes
void inputFillArray(double milesArr[], int crashArr[], string daysArr[], int size)
{
	double miles = 0;
	int crashes = 0;
	int index = 0;

	while (miles != -1 && crashes != -1 && index < size)
	{
		cout << "Enter miles ridden followed by number of crashes for " + daysArr[index] << endl;
		cin >> miles >> crashes;
		if (miles >= 0 && crashes >= 0)
		{
			milesArr[index] = miles;
			crashArr[index] = crashes;
			index++;
		}
		else
		{
			if (miles != -1 && crashes != -1)
				cout << "The number of miles ridden or crashes in a week must be greater than 0!" << endl;
		}
	}
}

// Parameters: double array, int array and int for size of array
// Returns: passes back mean for miles ridden in double
//			mean for crashes in double
// Calculate and return the mean for miles ridden in the week
void calcMean(double milesArr[], int crashesArr[], int sizeArr, double& meanMiles, double& meanCrashes)
{
	// Initialize
	meanMiles = 0;
	meanCrashes = 0;

	for (int i = 0; i < sizeArr; i++)
	{
		// Sum of all elements for both arrays
		meanMiles += milesArr[i];
		meanCrashes += crashesArr[i];
	}

	// Divide by size of array
	meanMiles /= sizeArr;
	meanCrashes /= sizeArr;
}

// Parameters: double array, int array, and int for size of array
// Returns: passes back max and min miles ridden in doubles
//			max and min crashes in ints
// Calculate and return max and min for miles ridden and crashes in the week
void calcMaxMin(double milesArr[], int crashesArr[], string daysArr[], int sizeArr, double& minMiles, string& minMilesDay, double& maxMiles, string& maxMilesDay, int& minCrashes, string& minCrashesDay, int& maxCrashes, string& maxCrashesDay)
{
	// Find min miles
	minMiles = milesArr[0];
	minMilesDay = daysArr[0];
	for (int i = 1; i < sizeArr; i++)
	{
		if (minMiles > milesArr[i])
		{
			minMiles = milesArr[i];
			minMilesDay = daysArr[i];  // use index position to return the string from day array
		}
	}

	// Find max miles
	maxMiles = milesArr[0];
	maxMilesDay = daysArr[0];
	for (int i = 1; i < sizeArr; i++)
	{
		if (maxMiles < milesArr[i])
		{
			maxMiles = milesArr[i];
			maxMilesDay = daysArr[i];  // use index position to return the string from day array
		}
	}

	// Find min crashes
	minCrashes = crashesArr[0];
	minCrashesDay = daysArr[0];
	for (int i = 1; i < sizeArr; i++)
	{
		if (minCrashes > crashesArr[i])
		{
			minCrashes = crashesArr[i];
			minCrashesDay = daysArr[i];  // use index position to return the string from day array
		}
	}

	// Find max crashes
	maxCrashes = crashesArr[0];
	maxCrashesDay = daysArr[0];
	for (int i = 1; i < sizeArr; i++)
	{
		if (maxCrashes < crashesArr[i])
		{
			maxCrashes = crashesArr[i];
			maxCrashesDay = daysArr[i];  // use index position to return the string from day array
		}
	}
}

// Paramenters: int array and int for size of array
// Returns: nothing
// Prints a horizontal bar chart showing crashes
void printCrashBarChart(string daysArr[], int crashArr[], int sizeArr, int maxCrashes)
{
	cout << "=========CRASH CHART BY DAY=========" << endl;
	for (int i = 0; i < sizeArr; i++)
	{
		cout << setw(9) << daysArr[i] << ":\t";
		for (int j = 0; j < crashArr[i]; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
	cout << "----------------";
	for (int i = 0; i < maxCrashes; i++)
	{
		cout << "--";
	}
	cout << endl;

	cout << setw(10) << "Crashes:" << "\t";
	for (int i = 1; i <= maxCrashes; i++)
	{
		cout << i << " ";
	}
	cout << endl;
}

// Parameters: mean miles, mean crashes, min miles, and max miles in double
//				min crashes and max crashes in int
// Returns: nothing
// Print statistics for weekly ride report with output formatting
void printWeeklyRideReport(double meanMiles, double meanCrashes, double minMiles, string minMilesDay, double maxMiles, string maxMilesDay, int minCrashes, string minCrashesDay, int maxCrashes, string maxCrashesDay)
{
	cout << "=================WEEKLY RIDE REPORT=================" << endl;
	cout << showpoint << setprecision(5) << fixed;
	cout << setw(29) << "Mean miles ridden this week:\t" << setw(8) << meanMiles << endl;
	cout << setw(29) << "Mean crashes this week:\t" << setw(8) << meanCrashes << endl;
	cout << setw(29) << "Min miles was:\t" << setw(8) << minMiles << " on " << minMilesDay << endl;
	cout << setw(29) << "Max miles was:\t" << setw(8) << maxMiles << " on " << maxMilesDay << endl;
	cout << setw(29) << "Min crashes was:\t" << setw(8) << minCrashes << " on " << minCrashesDay << endl;
	cout << setw(29) << "Max crashes was:\t" << setw(8) << maxCrashes << " on " << maxCrashesDay << endl;
	cout << "====================================================" << endl;
}
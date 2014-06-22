/* oez-P4-main
Student name:			Oscar Zavala
Student ID:				0198873
EGR-123-001				Spring 2014
Programing Exercise: Programming Exercise 4
Assigned:				3/20/2014
Due:						4/07/2014 11:59 PM
Program Description:	Write a program that calculates the diameter of a column
necessary to carry an applied load.
Developed on:			3/27/2014
Modified on:			3/31/2014
							Initially this code ran consecutive for-loops until the 
							answer was found (depending on the required precision).
							Modifications on 3/31 use embeded for loops to control 
							incrementation of diameter variable as well as checking
							it against the required results (56000 lbs, etc)

							Future plans:
							Class implementation? I cannot get the function to work appropriately.
							does #include <cmath> not extend to functions?

*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int option = 1;
	while (option != 0)
	{
		double pi = 3.14159265358979;
		double secantEqu = 0;
		double squrtEq = 0;
		double maxStress = 3000000;
		double safetyFactor = 3;
		double appliedLoad = 65000;
		double eccentricity = 1;
		double elasticity = 30000000;
		double columntLength = 54;
		int userPrecision = 5;		
		double increment = 1;
		double columnDiameter = 3;

		cout << "Given the following: "
			<< "\nMaximum stress \t\t= 56000"
			<< "\nSafety factor \t\t= 3" 
			<< "\nApplied load \t\t= 65,000" 
			<< "\nLoad eccentricity \t= 1"
			<< "\nAlloy elasticity \t= 30,000,000"
			<< "\nColumn length \t\t= 54" << endl;

		cout <<"\n" <<  fixed << setprecision(5);

		for (int	a = 0; a <= userPrecision; ++a, increment /= 10)
		{
			for (int i = 0; maxStress > 56000 ; ++i)
			{
				columnDiameter+= increment;

				squrtEq = (safetyFactor*appliedLoad)/(((pi*pow(columnDiameter,2))/4)*elasticity);
				secantEqu = (columntLength/(2*(columnDiameter/4))*sqrt(squrtEq));

				maxStress = (safetyFactor*appliedLoad/((pi*pow(columnDiameter,2))/4))*(columntLength+(((
					eccentricity*(columnDiameter/2))/pow((columnDiameter/4),2)))*(1/cos(secantEqu)));

				if (maxStress < 56000)
				{
					columnDiameter -= increment;
					maxStress = 300000;
					break;
				}
			}
		}

		cout << "The required column diameter is " << columnDiameter << endl;
		cout << "Enter 0 to terminate, any other key to continue" << endl;
		cin >> option;
		cout << endl;
	}
}

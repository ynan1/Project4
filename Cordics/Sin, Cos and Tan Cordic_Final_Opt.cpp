
//This a Sin,Cos and Tan Cordic Calculator(for any input angle),optimised by LUTs using Smart Pointers.
// With 12 iterations. Final Program for 12 iterations (Error less than 0.04 % except for angles near x axis).

#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string>
#include <mutex>

using namespace std;
using namespace std::chrono;
std::mutex m;

// Smart pointer.

auto objects1 = std::make_unique<int[]>(14);  
auto d = std::make_unique<int[] >(14);
auto objects2 = std::make_unique<float[]>(14);
auto k = std::make_unique<float[] >(14);
auto objects3 = std::make_unique<float[]>(14);
auto ph = std::make_unique<float[] >(14);

int main()
{
	float real_x = .6072;  // intial value for any trigonometric cordic
	float imag_y = 0.;
	float phase;
	float phase1 = 0;

	//typical cordic values

	float k[13] = { 1, 0.5, 0.25, 0.125, 0.0625, 0.03125, 0.015625, 0.0078125, 0.00390625, 0.00195312, 0.000976562, 0.000488281, 0.000244141 };                             //typical cordic values
	float ph[13] = { 0.785398, 0.463648, 0.244979, 0.124355, 0.0624188, 0.0312398, 0.0156237, 0.00781234, 0.00390623, 0.00195312, 0.000976562, 0.000488281, 0.000244141 };  // typical cordic values 
	float ph_temp = 0;
	float x_re = 0.;
	float y_im = 0.;
	int i;
	int count;
	const double PI = 3.141592653589793238463;

	ios_base::sync_with_stdio(false);

	std::cout << "\n This is Sin, Cos and Tan Optimised Cordic Calculator ";
	std::cout << "\n \n Please Enter the Angle in Degree and press enter: ";

	std::cin >> phase1;        // ENTER ANGLE IN DEGREE

	phase = phase1;


	if (phase > 0 && phase > 180.)   // PHASE CONVERSION FOR ANGLE MORE THAN 180 DEGREE
	{
		phase = (phase - 360);
	}
	else if (phase < 0 && phase < -180.)  // ANGLE CONVERSION FOR ANGLE LESS THAN -180 DEGREE
	{
		phase = (phase + 360);
	}

	if (phase > 0 && phase <= 90.)  //INTIALISING VALUES FOR CLACULATION
	{
		ph_temp = PI * phase / 180;
		x_re = real_x;
		y_im = imag_y;
		d[0] = 1;
	}
	else if (phase < 0 && phase >= -90.)  //INTIALISING VALUES FOR CLACULATION
	{
		ph_temp = PI * phase / 180;
		x_re = real_x;
		y_im = imag_y;
		d[0] = -1;
	}

	if (phase > 0 && phase > 90.)             //INTIALISING VALUES FOR CLACULATION
	{
		ph_temp = -(PI - PI * phase / 180);
		x_re = real_x;
		y_im = imag_y;
		d[0] = -1;
	}
	else if (phase < 0 && phase < -90.)        //INTIALISING VALUES FOR CLACULATION   
	{
		ph_temp = (PI + PI * phase / 180);
		x_re = real_x;
		y_im = imag_y;
		d[0] = 1;
	}


	// INITIALISING FIRST CALCULATION WHICH IS NOT ITERATIVE FOR THE CORDIC CALCULATION LIKE IN ARCTAN

	k[0] = 1.;
	x_re = x_re - d[0] * y_im * k[0];
	y_im = y_im + d[0] * x_re * k[0];
	ph_temp = ph_temp - d[0] * ph[0];

	// Calculate

	for (int i = 1; i < 13; i++)   //CALCULATION WHICH IS ITERATIVE FOR THE CORDIC CALCULATION LIKE
		                           // IN ARCTAN EXCEPT EXACT CALCULATIONS ARE DIFFERENT FROM ARCTAN
	{
		if (ph_temp >= 0)      //TYPICAL VALUE IN CORDIC CALCULATION AS IN ARCTAN CORDIC
		{
			d[i] = 1;
		}
		else {
			d[i] = -1;
		}
		
			float x_re1 = 0.;
			x_re = x_re - d[i] * y_im * k[i];  // CALCULATING X_RE(COS VALUE) AS DONE IN TRIGO CORDIC
			x_re1 = x_re + d[i] * y_im * k[i];  // X_RE1 IS  THE VALUE OF "X_RE" ON RIGHT 
			                                    //SIDE OF "=" SIGN IN ABOVE LINE 113(OLD VALUE OF X_RE IN LINE 113)
			                                    // FOR USE IN NEXT LINE 117
			y_im = y_im + d[i] * x_re1 * k[i];  // CALCULATING Y_IM(SIN VALUE) USING X_RE1 
			                   
			ph_temp = ph_temp - d[i] * ph[i];   // CALCULATING PH_TEMP FOR FINDING D[I] VALUE(1 OR -1) AS DONE IN ARCTAN CORDIC

	}

	if (phase > 90. || phase < -90)   //CONDITIONAL X_RE AND Y_IM (AS VALUES ARE CYCLIC FOR SIN AND COS OVER 360 DEGREE)
	{
		x_re = -x_re;  
		y_im = -y_im;
	} 

	if (phase == 0. || phase == 360. || phase == -0. || phase == -360.) // IF ANGLE IS PLUS MINUS 0 OR 360
		             // TAKE THE EXACT VALUES OF X_RE AND Y_IM WITHOUT CALCULATING, THOUGH PROGRAM
	{               //   IS CALCULATING THEM BUT OVERRIDE THOSE CALCULATED VALUES WITH EXACT VALUES
		x_re = 1.;   //THIS IS DONE TO GET ACCURATE VALUES NEAR ANGLES 0/360
		y_im = 0.;
	}

	if (phase == 180. || phase == -180.) // IF ANGLE IS PLUS MINUS 180 
		                    // TAKE THE EXACT VALUES OF X_RE AND Y_IM WITHOUT CALCULATING, THOUGH PROGRAM
	{                   // IS CALCULATING THEM BUT OVERRIDE THOSE CALCULATED VALUES WITH EXACT VALUES
		x_re = -1.;     // THIS IS DONE TO GET ACCURATE VALUES NEAR ANGLES 180
		y_im = 0.;
	}

std::cout << "\n \n Sin(" << phase1 << ") = " << y_im << "\n Percentage Error in Sin, in " << 12 <<" iterations is: " << 100 * ((sin(phase*PI/180) - y_im)/ sin(phase * PI / 180)) <<" % "
		<< "\n \n Cos(" << phase1 << ") = " << x_re << "\n Percentage Error in Cos, in " << 12 << " iterations is: " << 100 * ((cos(phase * PI / 180) - x_re) / cos(phase * PI / 180)) << " % "
		<< "\n \n Tan(" << phase1 << ") = " << (y_im / x_re) << "\n Percentage Error in Tan, in " << 12 << " iterations is: " << 100 * ((tan(phase * PI / 180) - (y_im / x_re)) / tan(phase * PI / 180)) << " % ";
	
	std::cout << '\n';

}

// COMMANDS FOR CALCULATING EXECUTION TIME OF ANY PART OF PROGRAM
// (REMOVED HERE FOR CLARITY)
//auto start1 = high_resolution_clock::now();  // Start of Program
//auto stop1 = high_resolution_clock::now();
	//auto duration1 = duration_cast<microseconds>(stop1 - start1);

	//std::cout << "\n Time taken by Full Program excluding std::cin and cout: "
		//<< duration1.count() << " microseconds" << endl;


//This a Sin,Cos and Tan Cordic Calculator(for any input angle),optimised by LUTs using Smart Pointers.
// With 12 iterations. Final Program for 12 iterations (Error less than 0.04 %).

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
	float real_x = .6072;
	float imag_y = 0.;
	float phase;
	float phase1 = 0;

	float k[14] = { 1, 0.5, 0.25, 0.125, 0.0625, 0.03125, 0.015625, 0.0078125, 0.00390625, 0.00195312, 0.000976562, 0.000488281, 0.000244141 };
	float ph[14] = { 0.785398, 0.463648, 0.244979, 0.124355, 0.0624188, 0.0312398, 0.0156237, 0.00781234, 0.00390623, 0.00195312, 0.000976562, 0.000488281, 0.000244141 };
	float ph_temp = 0;
	float x_re = 0.;
	float y_im = 0.;
	int i;
	int count;
	const double PI = 3.141592653589793238463;

	ios_base::sync_with_stdio(false);

	std::cout << "\n This is Sin, Cos and Tan Optimised Cordic Calculator ";
	std::cout << "\n \n Please Enter the Angle in Degree and press enter: ";

	std::cin >> phase1;

	phase = phase1;

	auto start1 = high_resolution_clock::now();  // Start of Program

	if (phase > 0 && phase > 180.)
	{
		phase = (phase - 360);
	}
	else if (phase < 0 && phase < -180.)
	{
		phase = (phase + 360);
	}

	if (phase > 0 && phase <= 90.)
	{
		ph_temp = PI * phase / 180;
		x_re = real_x;
		y_im = imag_y;
		d[0] = 1;
	}
	else if (phase < 0 && phase >= -90.)
	{
		ph_temp = PI * phase / 180;
		x_re = real_x;
		y_im = imag_y;
		d[0] = -1;
	}

	if (phase > 0 && phase > 90.)
	{
		ph_temp = -(PI - PI * phase / 180);
		x_re = real_x;
		y_im = imag_y;
		d[0] = -1;
	}
	else if (phase < 0 && phase < -90.)
	{
		ph_temp = (PI + PI * phase / 180);
		x_re = real_x;
		y_im = imag_y;
		d[0] = 1;
	}

	// Initialise

	k[0] = 1.;
	x_re = x_re - d[0] * y_im * k[0];
	y_im = y_im + d[0] * x_re * k[0];
	ph_temp = ph_temp - d[0] * ph[0];

	// Calculate

	for (int i = 1; i < 13; i++)   
	{
		if (ph_temp >= 0)
		{
			d[i] = 1;
		}
		else {
			d[i] = -1;
		}
		
			float x_re1 = 0.;
			x_re = x_re - d[i] * y_im * k[i];
			x_re1 = x_re + d[i] * y_im * k[i];
			y_im = y_im + d[i] * x_re1 * k[i];
			ph_temp = ph_temp - d[i] * ph[i];

			count = i;
	}

	if (phase > 90. || phase < -90)
	{
		x_re = -x_re;
		y_im = -y_im;
	}                     
	
	                 // End of Program

	auto stop1 = high_resolution_clock::now();
	auto duration1 = duration_cast<microseconds>(stop1 - start1);

	std::cout << "\n Time taken by Full Program excluding std::cin and cout: "
		<< duration1.count() << " microseconds" << endl;

	if (phase == 0. || phase == 360.)
	{
		x_re = 1.;
		y_im = 0.;
	}
	std::cout << "\n ph_temp = " << ph_temp;
	std::cout << "\n \n Sin(" << phase1 << ") = " << y_im << "\n Percentage Error in Sin, in " << count <<" iterations is: " << 100 * ((sin(phase*PI/180) - y_im)/ sin(phase * PI / 180)) <<" % "
		<< "\n \n Cos(" << phase1 << ") = " << x_re << "\n Percentage Error in Cos, in " << count << " iterations is: " << 100 * ((cos(phase * PI / 180) - x_re) / cos(phase * PI / 180)) << " % "
		<< "\n \n Tan(" << phase1 << ") = " << (y_im / x_re) << "\n Percentage Error in Tan, in " << count << " iterations is: " << 100 * ((tan(phase * PI / 180) - (y_im / x_re)) / tan(phase * PI / 180)) << " % ";
	
	std::cout << '\n';

}
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
//#include <cmath>
#include <mutex>

using namespace std;
using namespace std::chrono;
std::mutex m;

auto objects2 = std::make_unique<float[]>(14);
auto k = std::make_unique<float[] >(14);
const double PI = 3.141592653589793238463;

float arctan(float real_x, float imag_x)
{
	float angle_cal = 0;
	float ph[11] = { 0.7853981633974483,0.4636476090008061,0.2449786631268641,0.1243549945467614,0.06241880999595735,0.03123983343026828, 0.01562372862047683, 0.007812341060101111, 0.003906230131966972, 0.001953122516478819, 0.0009765621895593195 };
	float k[14] = { 1, 0.5, 0.25, 0.125, 0.0625, 0.03125, 0.015625, 0.0078125, 0.00390625, 0.00195312, 0.000976562, 0.000488281, 0.000244141 };
	float ph_temp;
	float y_re;
	float y_im;
	int i = 1;
	float tol = 1;
	


	if (imag_x > 0)
	{
		ph_temp = -PI / 2;
		y_re = imag_x;
		y_im = -real_x;
	}
	else {
		ph_temp = PI / 2;
		y_re = -imag_x;
		y_im = real_x;
	}

	while (tol > 10e-4) {
		if (y_im >= 0)
		{
			y_re = y_re + y_im * k[i];
			y_im = y_im - y_re * k[i];
			ph_temp = ph_temp - ph[i];
		}
		else {
			y_re = y_re - y_im * k[i];
			y_im = y_im + y_re * k[i];
			ph_temp = ph_temp + ph[i];
		}
		tol = fabs(ph_temp + angle_cal);
		angle_cal = -ph_temp;
		std::cout << k[i];
		i++;
	}
	std::cout << "\n" << i-1;
	return 180 * angle_cal / PI;
}

int main()
{
	double x, y;
	float angle = arctan(3, 7);
	std::cout << "\n" << angle;
	y = (7. / 3);
	x =180 * atan(y)/PI;
	std::cout << "\n" << y << ' ' << x;
	std::cout << "\n Error %age: " << 100 * ((x - angle) / x);
	
	
}
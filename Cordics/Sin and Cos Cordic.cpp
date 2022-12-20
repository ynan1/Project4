#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

auto objects1 = std::make_unique<int[]>(14);
auto d = std::make_unique<int[] >(14);
auto objects2 = std::make_unique<float[]>(14);
auto k = std::make_unique<float[] >(14);
auto objects3 = std::make_unique<float[]>(14);
auto ph = std::make_unique<float[] >(14);

float sincostan(float real_x, float imag_y, float phase)
{
	
	float x_cal = 0;
	float y_cal = 0;
	//float ph[11] = { 0.7853981633974483,0.4636476090008061,0.2449786631268641,0.1243549945467614,0.06241880999595735,0.03123983343026828, 0.01562372862047683, 0.007812341060101111, 0.003906230131966972, 0.001953122516478819, 0.0009765621895593195 };
	float ph_temp;
	//int ph = ;
	float x_re;
	float y_im;
	int i = 1;
	const double PI = 3.141592653589793238463;

	//ph_temp = PI * phase/180;
	//x_re = real_x;
	//y_im = imag_y;

	if (real_x > 0)
	{
		ph_temp = PI * phase / 180;
		x_re = real_x;
		y_im = imag_y;
	}
	else {
		ph_temp = PI * phase / 180;
		x_re = real_x;
		y_im = -imag_y;
	}
	
	//std::cout << ph_temp << ' ';
	
	for (int i = 1; i < 14; i++)   // Arrays of 10,000 elements taken here.
	{
		k[i] = pow(2, -(i-1));
		ph[i] = atan(k[i]);
		std::cout  << k[i] << ' ';
		std::cout << "\n";
	}

	x_re = x_re - 1 * y_im * 1;
	y_im = y_im + 1 * x_re * 1;
	ph_temp = ph_temp - 1 * PI / 4;

	std::cout << 1 << ' ';
	std::cout << x_re << ' ';
	std::cout << y_im << ' ';
	std::cout << 180 * ph_temp / PI << ' ' << "\n";

	for (int i = 1; i < 13; i++)   // Arrays of 10,000 elements taken here.
	{
		if (ph_temp >= 0)
		{
			d[i] = 1;
		}
		else {
			d[i] = -1;
		}

		if (y_im >= 0)
		{
			float x_re1 = 0.;
			x_re = x_re - d[i] * y_im * k[i + 1];
			x_re1 = x_re + d[i] * y_im * k[i + 1];
			y_im = y_im + d[i] * x_re1 * k[i + 1];
			ph_temp = ph_temp - d[i] * ph[i + 1];
		
		}
		else {

			float x_re2 = 0.;
			x_re = x_re - d[i] * y_im * k[i+1];
			x_re2 = x_re + d[i] * y_im * k[i + 1];
			y_im = y_im + d[i] * x_re2 * k[i+1];
			ph_temp = ph_temp - d[i] * ph[i+1];
			
		}
		
		std::cout << d[i] << ' ';
		std::cout << x_re << ' ';
		std::cout << y_im << ' ';
		std::cout << 180 * ph_temp / PI << ' ' << "\n";
		
		//tol = fabs(ph_temp - angle_cal);
		x_cal = x_re;
		y_cal = y_im;
		//i++;
	}

	if (real_x < 0)
	{
		x_cal = -x_cal;
		y_cal = -y_cal;
	}
	return x_cal, y_cal; //, y_cal;
	//return y_cal;
}

int main(void)
{
	float value = sincostan(.6072, 0, 70);
	std::cout << "Cos value is: " << "Sin value is: " << value;
}
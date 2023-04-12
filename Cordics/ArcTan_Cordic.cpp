if (imag_x == 0 && real_x > 0)
{
	angle_cal = 0;
}

if (imag_x == 0 && real_x < 0)
{
	angle_cal = PI;
}

if (real_x == 0 && imag_x > 0)
{
	angle_cal = PI / 2;
}
if (real_x == 0 && imag_x < 0)
{
	angle_cal = -PI / 2;
}

for (int j = 0; j < 10000; j++)   // Arrays of 10,000 elements taken here.
{
	b[j] = (rand() % (-1 - -15707962)) + -15707962; //values starting from 1 and goes upto 100. 
	//syntax:(rand() % (upper limit -lower limit)) + lower limit
	printf("%f   \n", b[j]);

}


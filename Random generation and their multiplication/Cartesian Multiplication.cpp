#include <iostream>
#include <string>
#include<stdlib.h>
#include <thread>


int main()
{
    std::cout << "Thread ID: " << std::thread::hardware_concurrency() << '\n';
    int* s = new int[20000] {}; // Here we allocate memory(object) space for hundred integers, an array of hundred
    // integers using operator new[]. Our pointer s now points at the first
             // element in the array. tewt

    int* k = new int[20000] {}; // we can use short int(2 byte) or int(4 byte).
    float* cr = new float[40000] {}; // real part of complex random no.
    float* ci = new float[40000] {};  // imaginary part of complex random no.
    float* S = new float[20000] {};
    float* K = new float[20000] {};
    int J = 0;
    int R = 0;
    int* d = new int[20000] {};
    int Count;

    std::cout << "The size of type float is: " << sizeof(float) << " byte(s)" << '\n';
    std::cout << "The size of type double is: " << sizeof(double) << " byte(s)" << '\n';

    srand(time(0));         // intialising random variable each time program starts, else rand() will give
    // same value each time program is run.

    for (int i = 0; i < 20000; i++)   // Arrays of 10,000 elements taken here.
    {
        s[i] = (rand() % (3000 - -3000)) + -3000; //values starting from 1 and goes upto 100. 
        //syntax:(rand() % (upper limit -lower limit)) + lower limit
        k[i] = (rand() % (3000 - -3000)) + -3000;
    }
    // std::cout << "Values of Ss are: " << '\n'; // print

    for (int n = 0;n < 20000;n++)
    {
        S[n] = s[n] / 1000.;
        // std::cout << S[n] << ' ';
    }
    std::cout << '\n';

    // std::cout << "Values of Ks are: " << '\n' << '\n';

    for (int p = 0;p < 20000;p++)
    {
        K[p] = k[p] / 1000.;
        //std::cout << K[p] << ' ';
    }
    std::cout << "Values of CRs are: " << '\n';  // real part of complex random no. matrix multiplication

    for (int r = 0; r < 100; r++)
    {

        for (int j = 0; j < 100; j++)
        {

            float tempr = 0;

            for (int m = 0; m < 100; m++)
            {

                tempr = tempr + (S[100 * r + m] * K[100 * j + m]);

            }

            cr[r * 100 + j] = tempr;

            std::cout << cr[r * 100 + j] << ' ';

            J = j + 1;
        }

        R = r + 1;

    }

    std::cout << '\n' << '\n';
    std::cout << "Values of CIs are: " << '\n'; // imag. part of complex random no. matrix multiplication

    for (int r = 0; r < 100; r++)
    {

        for (int j = 0; j < 100; j++)
        {


            float tempi = 0;
            for (int m = 0; m < 100; m++)
            {

                tempi = tempi + (S[10000 + 100 * r + m] * K[10000 + 100 * j + m]);

            }

            ci[r * 100 + j] = tempi;

            std::cout << ci[r * 100 + j] << ' ';
            //J = j + 1;
        }

        //R = r + 1;

    }
    std::cout << '\n' << '\n';
    std::cout << "Values of CRs truncated to 3 decimal points are: " << '\n'; //Truncation to 3 decimals
    for (int i = 0;i < R * J;i++)
    {

        if (cr[i] > 0)
        {
            d[i] = (int)(cr[i] * 1000 + .5);
        }
        else
        {
            d[i] = (int)(cr[i] * 1000 - .5);
        }

        cr[i] = (float)d[i] / 1000;     // float values of CRs truncated to 3 decimal points.

        std::cout << cr[i] << ' ';


    }
    std::cout << '\n' << '\n';
    std::cout << "Values of CIs truncated to 3 decimal points are: " << '\n'; //Truncation to 3 decimals

    for (int i = 0;i < R * J;i++)
    {

        if (ci[i] > 0)
        {
            d[i] = (int)(ci[i] * 1000 + .5);
        }
        else
        {
            d[i] = (int)(ci[i] * 1000 - .5);
        }

        ci[i] = (float)d[i] / 1000;     // float values of CIs truncated to 3 decimal points.

        std::cout << ci[i] << ' ';


    }
    std::cout << '\n';
    delete[] s;    // Clear memory/objects.
    delete[] k;
    delete[] S;    // Clear memory/objects.
    delete[] K;
    delete[] cr;    // Clear memory/objects.
    delete[] ci;
    delete[] d;    // Clear memory/objects.


}
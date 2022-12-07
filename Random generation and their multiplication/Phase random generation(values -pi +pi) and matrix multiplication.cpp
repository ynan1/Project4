#include <iostream>
#include <string>
#include<stdlib.h>
#include <thread>


int main()
{
    std::cout << "Thread ID: " << std::thread::hardware_concurrency() << '\n';
    int* s = new int[15000] {}; // Here we allocate memory(object) space for hundred integers, an array of hundred
    // integers using operator new[]. Our pointer s now points at the first
             // element in the array. tewt

    int* k = new int[15000] {}; // we can use short int(2 byte) or int(4 byte).
    float* cr = new float[30000] {};
    float* ci = new float[30000] {};
    float* S = new float[15000] {};
    float* K = new float[15000] {};                                     // we can use int(4 byte) or int64_t(8 byte).
    int J = 0;
    int R = 0;
    int* d = new int[15000] {};
    int Count;

    std::cout << "The size of type float is: " << sizeof(float) << " byte(s)" << '\n';
    std::cout << "The size of type double is: " << sizeof(double) << " byte(s)" << '\n';

    srand(time(0));         // intialising random variable each time program starts, else rand() will give
    // same value each time program is run.

    for (int i = 0; i < 10000; i++)   // Arrays of 10,000 elements taken here.
    {
        s[i] = (rand() % (3142 - -3142)) + -3142; //values starting from 1 and goes upto 100. 
        //syntax:(rand() % (upper limit -lower limit)) + lower limit
        k[i] = (rand() % (3142 - -3142)) + -3142;
    }
   // std::cout << "Values of Ss are: " << '\n'; // print

    for (int n = 0;n < 10000;n++)
    {
        S[n] = s[n] / 1000.;
       // std::cout << S[n] << ' ';
    }
    std::cout << '\n';

   // std::cout << "Values of Ks are: " << '\n' << '\n';

    for (int p = 0;p < 10000;p++)
    {
        K[p] = k[p] / 1000.;
        //std::cout << K[p] << ' ';
    }
    std::cout << "Values of CRs are: " << '\n';

    for (int r = 0; r < 100; r++)
    {

        for (int j = 0; j < 100; j++)
        {

            float tempr = 0;
            float tempi = 0;
            for (int m = 0; m < 100; m++)
            {

                tempr = tempr + cos(S[100 * r + m] + K[100 * j + m]);
            
            }
            
            cr[r * 100 + j] = tempr;
            
           std::cout << cr[r * 100 + j] << ' ';
          
            J = j + 1;
        }

        R = r + 1;
        
    }
    std::cout  << '\n' << '\n';
    std::cout << "Values of CIs are: " << '\n';

    for (int r = 0; r < 100; r++)
    {

        for (int j = 0; j < 100; j++)
        {

            float tempr = 0;
            float tempi = 0;
            for (int m = 0; m < 100; m++)
            {

                tempi = tempi + sin(S[100 * r + m] + K[100 * j + m]);

            }
            
            ci[r * 100 + j] = tempi;

           std::cout << ci[r * 100 + j] << ' ';
            //J = j + 1;
        }

        //R = r + 1;

    }
    

}
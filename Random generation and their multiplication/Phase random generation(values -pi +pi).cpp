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
   
    float* S = new float[15000] {};
    float* K = new float[15000] {};                                     // we can use int(4 byte) or int64_t(8 byte).
    int J = 0;
    int R = 0;
    
  

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
    std::cout << "Values of Ss are: " << '\n'; // print

    for (int n = 0;n < 10000;n++)
    {
        S[n] = s[n] / 1000.;
        std::cout << S[n] << ' ';
    }
    std::cout << '\n';

    std::cout << "Values of Ks are: " << '\n';
    for (int p = 0;p < 10000;p++)
    {
        K[p] = k[p] / 1000.;
        std::cout << K[p] << ' ';
    }

    delete[] s;    // Clear memory/objects.
    delete[] k;
    delete[] S;    // Clear memory/objects.
    delete[] K;
   
}
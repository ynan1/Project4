#include <iostream>
#include <string>
#include<stdlib.h>
#include <thread>

int main()
{
    std::cout << "Thread ID: " << std::thread::hardware_concurrency() << '\n';

    int* s = new int[15000] {}; // Here we allocate memory(object) space for hundred integers, an array of hundred
                              // integers using operator new[]. Our pointer s now points at the first
                                // element in the array. 

    int* k = new int[15000] {}; // we can use short int(2 byte) or int(4 byte).
    

   // std::cout << "The size of type float is: " << sizeof(float) << " byte(s)" << '\n';
    //std::cout << "The size of type double is: " << sizeof(double) << " byte(s)" << '\n';

    srand(time(0));     // intialising random variable each time program starts, else rand() will give
    float r = rand();                  // same value each time program is run.
    std::cout <<"Random initialisation value is: " << r;
    std::cout << '\n';

    for (int i = 0; i < 10000; i++)   // Arrays of 10,000 elements taken here.
    {
        s[i] = (rand() % (2 - 0)) + 0; //values starting from 1 and goes upto 100. 
        //syntax:(rand() % (upper limit -lower limit)) + lower limit
        k[i] = (rand() % (2 - 0)) + 0;
    }
    std::cout << "Values of Ss are: " << '\n'; // print

    for (int n = 0;n < 10000;n++)
    {
        if(s[n] == 0)
        {
            s[n] = -1;
        }
        std::cout << s[n] << ' ';
    }
    std::cout << '\n';

    std::cout << "Values of Ks are: " << '\n';
    for (int p = 0;p < 10000;p++)
    {
        if (k[p] == 0)
        {
            k[p] = -1;
        }
        std::cout << k[p] << ' ';
    }
    std::cout << '\n';

    //std::cout << "Total number of Cs in a row calculated = " << J << '\n';
    //std::cout << "Total number of row in C array calculated = " << R + 1 << '\n';}

    delete[] s;    // Clear memory/objects.
    delete[] k;
    
}
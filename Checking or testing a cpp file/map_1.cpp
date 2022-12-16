#include <iostream>
#include <string>
#include<stdlib.h>
#include <thread>
#include <memory>

int main()
{
    
    auto objects = std::make_unique<float[]>(4);
    auto cr1 = std::make_unique<float[] >(4);

   
    int  arr[2][2][2] = { { { 1, -1 }, {1, -1} }, { { 1, -1 }, {-1, 1} } };
   // std::cout << arr[1][1][1] ;
    const int  c1[2] = { 1, -1 };
    const int  c2[2] = { 1, -1 };

    for (int r = 0; r < 2; r++)
    {
        int k = 0;

        for (int j = 0; j < 2; j++)
        {

            std::cout << arr[1][r][j] <<' ';

         // cr1[k + r + j] = c1[r] * c2[j];

          //  std::cout << cr1[r + j + k] << ' ';
        }
       // k = k + 1;
    }
}
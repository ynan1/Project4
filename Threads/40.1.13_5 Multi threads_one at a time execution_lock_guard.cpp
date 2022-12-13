// We can forget to unlock the mutex manually. A better approach is to use the std::lock_guard
// function instead. It locks the mutex, and once it goes out of scope, it automatically unlocks
// the mutex. 
// We can forget to unlock the mutex manually. A better approach is to use the std::lock_guard 
//function instead. It locks the mutex, and once it goes out of scope, it automatically unlocks
// the mutex.

#include <iostream>
#include <thread>
#include <mutex>

std::mutex m; // will guard std::cout
void function1(const std::string& param1)
{
	for (int i = 0; i < 10; i++)
	{
		std::lock_guard<std::mutex> lg(m);
		std::cout << "Executing function1." << param1 << '\n';
		
	}
}
void function2(const std::string& param2)
{
	for (int i = 0; i < 10; i++)
	{
		std::lock_guard<std::mutex> lg(m);
		std::cout << "Executing function2." << param2 << '\n';
		// m.unlock();
	}
}
int main()
{
	std::thread t1{ function1,  "Hello World from a thread." }; // t1 gets executed later than t2
	std::thread t2{ function2, "Hello World from a thread." };  // Here t2 gets executed first and t1 later, run and see the result
	t1.join();
	t2.join();
}
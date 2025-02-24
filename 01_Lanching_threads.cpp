#include<iostream>
#include<thread>

//using namespace std;

void test() {
    std::cout << "Hello from  test" << std::endl;
}
void functionA() {
    std::cout << "This is function A" << std::endl;
    std::thread threadC(test);
    threadC.join();
}

void functionB() {
    std::cout << "This is function B" << std::endl;
}



int main()
{
    std::thread threadA(functionA);
    std::thread threadB(functionB);
    threadA.join();
    threadB.join();
    return 0;
}
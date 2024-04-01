#include <iostream>
#include "myhandler.cpp"

int main()
{
    std::ostream &ostream = std::cout;
    std::istream &istream = std::cin;
    MyHandler *myHandler = new MyHandler(ostream, istream);
    myHandler->start();

    return 0;
}
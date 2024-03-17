#include <stdio.h>
#include <iostream>
#include "commander/Line.cpp"
#include "Stack.cpp"
#include "Tree.cpp"
#include "Terminal.cpp"
#include "myhandler.cpp"

int main()
{
    std::ostream &ostream = std::cout;
    std::istream &istream = std::cin;
    MyHandler *myHandler = new MyHandler(ostream, istream);
    myHandler->start();

    return 0;
}
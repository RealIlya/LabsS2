#include <stdio.h>
#include <iostream>
#include "commander/Command.cpp"
#include "commander/Executor.cpp"
#include "commander/Handler.cpp"
#include "commands.cpp"
#include "linked_list.cpp"
#include "myhandler.cpp"

int main()
{
    std::ostream &ostream = std::cout;
    std::istream &istream = std::cin;
    MyHandler *myHandler = new MyHandler(ostream, istream);
    myHandler->start('0');

    return 0;
}
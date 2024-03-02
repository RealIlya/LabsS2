#include "commander/Line.h"
#include "proto/Terminal.h"
#include "proto/Stack.h"
#include <iostream>

class MyHandler
{
    std::ostream &ostream;
    std::istream &istream;

public:
    MyHandler(std::ostream &ostream, std::istream &istream) : ostream{ostream}, istream{istream}
    {
    }

    ~MyHandler()
    {
    }

    void start(std::string stopCommand)
    {
        Terminal *invoker = new Terminal(new Stack(4), ostream);
        Line *line;
        std::string str;

        while (true)
        {
            std::getline(istream, str);
            line = new Line(str);
            invoker->invoke(line);
        }
    }
};

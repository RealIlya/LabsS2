#include "commander/Line.h"
#include "proto/Terminal.h"

class MyHandler
{
    std::ostream &ostream;
    std::istream &istream;

public:
    MyHandler(std::ostream &ostream, std::istream &istream) : ostream{ostream}, istream{istream} {}

    void start()
    {
        Terminal *invoker = new Terminal(ostream, istream);
        Line *line;
        std::string str;

        while (true)
        {
            std::getline(istream, str);
            if (str.empty())
                continue;
            line = new Line(str);
            if (!invoker->invoke(line))
                break;
        }

        delete invoker;
        invoker = nullptr;
        delete line;
        line = nullptr;
    }
};

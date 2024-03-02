<<<<<<< HEAD
#include "commander/Handler.h"
#include "proto/commands.h"

class MyHandler : public Handler
=======
#include "commander/Line.h"
#include "proto/Terminal.h"
#include "proto/Stack.h"
#include <iostream>

class MyHandler
>>>>>>> db494945ff30ef6d203725f23de0e7e8e46b30eb
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

    void start() override
    {
        Terminal *invoker = new Terminal(new Stack(4), ostream);
        Line *line;
        std::string str;

        while (true)
        {
<<<<<<< HEAD
            istream >> command;
            if (commands->checkStopCommand(command))
                break;

            if (!executor->executeCommand(command))
            {
                ostream << "Incorrect command, try again >> ";
            }
=======
            std::getline(istream, str);
            line = new Line(str);
            invoker->invoke(line);
>>>>>>> db494945ff30ef6d203725f23de0e7e8e46b30eb
        }
    }
};

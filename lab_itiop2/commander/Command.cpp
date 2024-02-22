#include <functional>
#include "Command.h"

Command::Command(std::function<void()> command) : command{command} {}

void Command::execute()
{
    command();
}
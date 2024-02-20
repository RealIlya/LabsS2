#include "proto/commands.h"

Commands::Commands(std::ostream &ostream, std::istream &istream) : ostream{ostream}, istream{istream}
{
    ostream << "Input command (h for help) >> ";
    list = new struct list;
}

Commands::~Commands()
{
    delete list;
    list = nullptr;
}

void Commands::help_Command()
{
    ostream << "p to push back an elem to list\n"
            << "d to delete an elem from list\n"
            << "z to get a size\n"
            << "c to check elem is contained in list\n"
            << "t to print a list\n"
            << "0 to terminate program" << std::endl;
}

void Commands::pushBack_Command()
{
    char *elem = new char;
    ostream << "Input a char to push back >> ";
    istream >> *elem;
    list->push_back(elem);
}

void Commands::delete_Command()
{
    char *elem = new char;
    ostream << "Input a char to delete >> ";
    istream >> *elem;
    ostream << (list->del(elem) ? "Deleted" : "List does not contain this value") << std::endl;
}

void Commands::getSize_Command()
{
    ostream << "List size (with root) is " << list->size() << std::endl;
}

void Commands::checkContent_Command()
{
    char *elem = new char;
    ostream << "Input a char to check containing >> ";
    istream >> *elem;
    ostream << (list->contains(elem) ? "Is in" : "Is not in") << std::endl;
}

void Commands::print_Command()
{
    list->print(ostream);
}
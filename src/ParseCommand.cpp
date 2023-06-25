#include <string>

#include "ParseCommand.h"
#include "CWDCommand.h"
#include "NOPCommand.h"
#include "ExecutableCommand.h"

namespace seashell {
    Command* parseCommand(std::string commandText) {
        std::string firstToken = commandText.substr(0, commandText.find(' '));

        if (firstToken == "cd") return new CWDCommand(commandText);
        if (firstToken == "") return new NOPCommand();
        return new ExecutableCommand(commandText);

    }
}
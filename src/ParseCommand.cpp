#include <string>

#include "ParseCommand.h"
#include "CWDCommand.h"
#include "NOPCommand.h"
#include "ExitCommand.h"
#include "SetPromptCommand.h"
#include "ExecutableCommand.h"
#include "PathPrefixedExecutableCommand.h"

namespace seashell {
    Command* parseCommand(std::string commandText) {
        std::string firstToken = commandText.substr(0, commandText.find(' '));

        if (firstToken == "cd") return new CWDCommand(commandText);
        if (firstToken == "") return new NOPCommand();
        if (firstToken == "exit") return new ExitCommand(commandText);
        if (firstToken == "setp") return new SetPromptCommand(commandText);

        if (firstToken.find('/') != std::string::npos) return new ExecutableCommand(commandText);
        return new PathPrefixedExecutableCommand(commandText);

    }
}
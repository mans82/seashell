#include "Command.h"

#include <iostream>

namespace seashell {
    Command::Command(std::string commandText) {
        
        std::size_t nextDelimPosition = commandText.find(' ');

        this->baseCommand = commandText.substr(0, nextDelimPosition);
        this->args.push_back(this->baseCommand);

        std::size_t lastDelimPosition = nextDelimPosition;

        while (lastDelimPosition != std::string::npos) {
            nextDelimPosition = commandText.find(' ', lastDelimPosition + 1);

            if (nextDelimPosition > lastDelimPosition + 1) {
                std::string curArg = commandText.substr(lastDelimPosition + 1, nextDelimPosition - lastDelimPosition - 1);
                this->args.push_back(curArg);
            }

            lastDelimPosition = nextDelimPosition;
        }

    }
}
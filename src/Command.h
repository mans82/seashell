#pragma once

#include <string>
#include <vector>

#include "ShellState.h"

namespace seashell {

    class Command {

    protected:
        std::string baseCommand;
        std::vector<std::string> args;

    public:
        Command(std::string);

        virtual void execute(ShellState&) = 0;
    };

}
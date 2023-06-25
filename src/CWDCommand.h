#pragma once

#include <string>

#include "Command.h"
#include "ShellState.h"

namespace seashell {
    class CWDCommand : public Command {
    public:
        CWDCommand(std::string);
        void execute(ShellState&);
    };
}
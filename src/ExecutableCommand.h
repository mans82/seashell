#pragma once

#include <vector>
#include "Command.h"

namespace seashell {
    class ExecutableCommand : public Command {
    public:
        ExecutableCommand(std::string commandText);
        void execute(ShellState&);
    };
}
#pragma once

#include <string>

#include "Command.h"
#include "ShellState.h"

namespace seashell {

    class ExitCommand : public Command {
    public:
        ExitCommand(std::string);
        void execute(ShellState&) override;
    };

}
#pragma once

#include <string>

#include "ExecutableCommand.h"
#include "ShellState.h"

namespace seashell {
    
    class PathPrefixedExecutableCommand : public ExecutableCommand {
    public:
        PathPrefixedExecutableCommand(std::string);
        void execute(ShellState&) override;

    };

}
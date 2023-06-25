#include <string>

#include "PathPrefixedExecutableCommand.h"

namespace seashell {
    
    PathPrefixedExecutableCommand::PathPrefixedExecutableCommand(std::string commandText) : ExecutableCommand(commandText) {}

    void PathPrefixedExecutableCommand::execute(ShellState& state) {
        
        std::string pathPrefixedCommand = state.path + '/' + this->baseCommand;
        std::string originalBaseCommand = this->baseCommand;

        this->baseCommand = pathPrefixedCommand; 

        this->ExecutableCommand::execute(state);

        this->baseCommand = originalBaseCommand;
    }

}
#include <string>
#include <iostream>

#include "ExitCommand.h"
#include "ShellState.h"

namespace seashell {

    ExitCommand::ExitCommand(std::string commandText) : Command(commandText) {}

    void ExitCommand::execute(ShellState& state) {
        if (this->args.size() > 2) {
            std::cerr << "seashell: too many arguemnts for exit" << std::endl;
            state.lastExitCode = 1;
            return;
        }

        ExitCode exitCode = 0;

        if (this->args.size() == 2) {
            try {
                exitCode = std::stoi(this->args[1]);
            } catch (std::invalid_argument) {
                std::cerr << "seashell: invalid exit code - must be numeric" << std::endl;
                exitCode = 1;
            }
        }

        exit(exitCode);
    }
}
#include <unistd.h>
#include <iostream>
#include <string>

#include "CWDCommand.h"

namespace seashell {
    CWDCommand::CWDCommand(std::string commandText) : Command(commandText) {}

    void CWDCommand::execute(ShellState& state) {
        if (this->args.size() < 2) {
            std::cerr << "seashell: argument missing for cd" << std::endl;
            state.lastExitCode = 0;
            return;
        }

        if (this->args.size() > 2) {
            std::cerr << "seashell: too many arguments for cd" << std::endl;
            state.lastExitCode = 0;
            return;
        }

        int status = chdir(this->args[1].data());

        if (status == -1) {
            state.lastExitCode = 1;
            std::cerr << "seashell: cd failed" << std::endl;
        } else {
            state.lastExitCode = 0;
        }
    }
}
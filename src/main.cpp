#include <iostream>
#include <string>

#include "ExecutableCommand.h"
#include "ShellState.h"

int main() {
    ShellState state;
    state.lastExitCode = 0;
    while (std::cin) {
        std::cout << "SEASHELL: ";
        std::cout.flush();

        std::string line;
        std::getline(std::cin, line);

        seashell::ExecutableCommand currentCommand(line);

        currentCommand.execute(state);

        std::cout << "Process exited with error code " << state.lastExitCode << std::endl;
    }
}
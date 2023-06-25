#include <iostream>
#include <string>
#include <memory>

#include "ShellState.h"
#include "ParseCommand.h"

int main() {
    ShellState state;
    state.path = "/usr/bin";
    state.lastExitCode = 0;

    while (std::cin) {
        std::cout << "SEASHELL: ";
        std::cout.flush();

        std::string line;
        std::getline(std::cin, line);

        seashell::Command* parsedCommandPtr = seashell::parseCommand(line);

        std::unique_ptr<seashell::Command> currentCommand(parsedCommandPtr);

        currentCommand->execute(state);

        std::cout << "Process exited with error code " << state.lastExitCode << std::endl;
    }
}
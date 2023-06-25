#include <iostream>
#include <string>
#include <memory>

#include "ShellState.h"
#include "Prompt.h"
#include "ParseCommand.h"

int main() {
    ShellState state;
    state.path = "/usr/bin";
    state.promptTextFormat = "\033[1m $? $c $u $# \033[0m";
    state.lastExitCode = 0;

    while (std::cin) {
        std::cout << seashell::makePrompt(state);
        std::cout.flush();

        std::string line;
        std::getline(std::cin, line);

        seashell::Command* parsedCommandPtr = seashell::parseCommand(line);

        std::unique_ptr<seashell::Command> currentCommand(parsedCommandPtr);

        currentCommand->execute(state);

    }
}
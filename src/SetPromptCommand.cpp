#include <string>
#include <iostream>
#include <regex>

#include "SetPromptCommand.h"
#include "ShellState.h"

namespace seashell {

    SetPromptCommand::SetPromptCommand(std::string commandText) : Command("") {
        
        const std::regex commandRegex("^\\w+\\s+\"(.*)\"$");
        std::smatch matchObject;

        if (std::regex_match(commandText, matchObject, commandRegex)) {
            this->newPrompt = matchObject[1].str();
            this->isCommandValid = true;
        } else this->isCommandValid = false;
    }

    void SetPromptCommand::execute(ShellState& state) {
        if (this->isCommandValid) state.promptTextFormat = this->newPrompt;
        else std::cerr << "seashell: malformed command" << std::endl;
    }

}
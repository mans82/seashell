#pragma once

#include <string>

#include "Command.h"
#include "ShellState.h"

namespace seashell {

    class SetPromptCommand : public Command {
    private:
        std::string newPrompt;
        bool isCommandValid = false;
    public:
        SetPromptCommand(std::string);
        void execute(ShellState&) override;
    };

}
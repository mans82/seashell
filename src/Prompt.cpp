#include "Prompt.h"
#include "ProcessInfo.h"
#include "ShellState.h"

#include <string>

namespace seashell {

    std::string makePrompt(std::string promptTextFormat, ShellState& state) {
        
        std::string res = promptTextFormat;

        size_t pos;

        if ((pos = res.find("$u")) != std::string::npos) {
            res.replace(pos, 2, getUserName());
        }

        if ((pos = res.find("$c")) != std::string::npos) {
            res.replace(pos, 2, getCurrentWorkingDirectory());
        }

        if ((pos = res.find("$?")) != std::string::npos) {
            res.replace(pos, 2, std::to_string(state.lastExitCode));
        }

        if ((pos = res.find("$#")) != std::string::npos) {
            res.replace(pos, 2, isRunningAsRoot() ? "#" : "$");
        }

        return res;

    }

}
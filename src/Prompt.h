#pragma once

#include "ShellState.h"

namespace seashell {

    std::string getInitialPrompt();

    std::string makePrompt(ShellState&);

}
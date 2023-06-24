#pragma once

#include <string>

using ExitCode = unsigned short;

struct ShellState {
    std::string promptText;
    ExitCode lastExitCode;
};
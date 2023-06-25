#pragma once

#include <string>

using ExitCode = unsigned short;

struct ShellState {
    std::string promptTextFormat;
    std::string path;

    ExitCode lastExitCode;
};
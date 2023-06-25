#include "Prompt.h"
#include "ProcessInfo.h"
#include "ShellState.h"

#include <string>

namespace seashell {

    std::string getInitialPrompt() {
        return
        "\033[1;36m" R"(                     )" "\033[1;37m"           R"(                      _          _ _ )" "\n"
        "\033[1;36m" R"(      _.---._        )" "\033[1;37m"           R"(                     | |        | | |)" "\n"
        "\033[1;36m" R"(  .'"".'/|\`.""'.    )" "\033[1;37m"           R"(   ___  ___  __ _ ___| |__   ___| | |)" "\n"
        "\033[1;36m" R"( :  .' / | \ `.  :   )" "\033[1;37m"           R"(  / __|/ _ \/ _` / __| '_ \ / _ \ | |)" "\n"
        "\033[1;36m" R"( '.'  /  |  \  `.'   )" "\033[1;37m"           R"(  \__ \  __/ (_| \__ \ | | |  __/ | |)" "\n"
        "\033[1;36m" R"(  `. /   |   \ .'    )" "\033[1;37m"           R"(  |___/\___|\__,_|___/_| |_|\___|_|_|)" "\n"
        "\033[1;36m" R"(    `-.__|__.-'        )" "\033[1;30m\033[47m"   R"(https://github.com/mans82/seashell)" 
        "\033[0m"
        "\n\n";
    }

    std::string makePrompt(ShellState& state) {
        
        std::string res = state.promptTextFormat;

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

        std::string boldRes = "\033[1m" + res + "\033[0m";
        return boldRes;

    }

}
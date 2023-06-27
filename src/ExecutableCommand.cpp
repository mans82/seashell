#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <cstring>

#include "ExecutableCommand.h"
#include "ShellState.h"
#include <signal.h>

#include "NullTerminatedBuffer.h"

namespace seashell {
    void emptySignalHandler(int signal) {}

    ExecutableCommand::ExecutableCommand(std::string commandText) : Command(commandText) {};

    void ExecutableCommand::execute(ShellState& state) {
        NullTerminatedBuffer argsArray(this->args);
        const char* path = this->baseCommand.data();

        pid_t childPid = fork();
        if (childPid != 0) {
            // This is the parent

            struct sigaction oldSignalHandler;

            sigaction(SIGINT, NULL, &oldSignalHandler);
            signal(SIGINT, emptySignalHandler);

            int childStatus;
            waitpid(childPid, &childStatus, 0);

            sigaction(SIGINT, &oldSignalHandler, NULL);

            ExitCode childExitCode = WEXITSTATUS(childStatus);

            state.lastExitCode = childExitCode;

            
        } else {
            int execResult = execv(path, argsArray.buffer());
            if (execResult == -1) {
                std::cerr << "seashell: Command failed to execute" << std::endl;
                exit(1);
            }
        }
    }
}
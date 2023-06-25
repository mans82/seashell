#include "Command.h"
#include "ShellState.h"

namespace seashell {
    class NOPCommand : public Command {
    public:
        NOPCommand();
        void execute(ShellState&);
    };
}
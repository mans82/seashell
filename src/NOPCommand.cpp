#include "NOPCommand.h"

namespace seashell {
    
    NOPCommand::NOPCommand() : Command("") {}
    
    void NOPCommand::execute(ShellState& state) {}
}
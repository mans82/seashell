#pragma once

#include <vector>
#include <string>

namespace seashell {
    class NullTerminatedBuffer {
    private:
        char** buff;
        int size;
    public:
        NullTerminatedBuffer(std::vector<std::string>&);
        char** buffer();
        ~NullTerminatedBuffer();
    };
}
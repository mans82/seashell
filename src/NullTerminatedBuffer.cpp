#include <cstring>

#include "NullTerminatedBuffer.h"

namespace seashell {
    NullTerminatedBuffer::NullTerminatedBuffer(std::vector<std::string>& stringVector) {
        this->size = stringVector.size();


        this->buff = new char*[this->size + 1];

        for (int i = 0; i < this->size; i++) {
            const int curStringSize = stringVector[i].size();
            this->buff[i] = new char[curStringSize + 1];
            strcpy(this->buff[i], stringVector[i].data());
        }

        buff[this->size] = 0;
    }

    char** NullTerminatedBuffer::buffer() {
        return this->buff;
    }

    NullTerminatedBuffer::~NullTerminatedBuffer() {
        for (int i = 0; i < this->size; i++) delete[] this->buff[i];

        delete[] this->buff;
    }
}
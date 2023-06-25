#include <string>
#include <unistd.h>
#include <pwd.h>

#include "ProcessInfo.h"

const size_t MAX_PATH_LENGTH = 4096;

namespace seashell {

    std::string getUserName() {

        uid_t uid = getuid();
        passwd* passwdEntry = getpwuid(uid);

        if (passwdEntry) {
            return passwdEntry->pw_name;
        } else {
            return "?!";
        }
    }

    std::string getCurrentWorkingDirectory() {
        char* cwdPathStringBuffer = new char[MAX_PATH_LENGTH];

        char* returnedBuffer = getcwd(cwdPathStringBuffer, MAX_PATH_LENGTH);

        std::string res;

        if (returnedBuffer == NULL) res = "?!";
        else res = std::string(cwdPathStringBuffer);

        delete[] cwdPathStringBuffer;

        return res;
    }

    bool isRunningAsRoot() {
        return getuid() == 0;
    }

}
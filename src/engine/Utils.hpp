#ifndef PTUT_UTILS_HPP
#define PTUT_UTILS_HPP

#include <filesystem>

class Utils {
public:
    Utils() = delete;

    static void setExePath(const char* path);
    static std::string getPath(const char* path);

private:
    static std::filesystem::path exePath;
};

#endif //PTUT_UTILS_HPP

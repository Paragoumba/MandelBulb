//
// Created by paragoumba on 08/10/2019.
//

#ifndef MANDELBULB_TRANSLATIONMANAGER_HPP
#define MANDELBULB_TRANSLATIONMANAGER_HPP

#include <string>
#include <map>

class TranslationManager {
private:
    TranslationManager() = default;

    static TranslationManager* instance;

    std::map<const std::string, const std::string> strings;

public:
    static TranslationManager* getInstance();

    [[nodiscard]] const std::string* get(const char* id) const;
};

#endif //MANDELBULB_TRANSLATIONMANAGER_HPP

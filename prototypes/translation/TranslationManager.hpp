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

    std::map<const std::string, std::string> strings;
    std::string lang = "";

public:
    enum Langs {
        EN,
        FR
    };

    static TranslationManager* getInstance(Langs lang);

    void loadLang();
    [[nodiscard]] const std::string* get(const char* id) const;
    void setLang(Langs newLang);
};

#endif //MANDELBULB_TRANSLATIONMANAGER_HPP

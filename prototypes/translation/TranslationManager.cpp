//
// Created by paragoumba on 08/10/2019.
//

#include <yaml-cpp/yaml.h>
#include <iostream>

#include "TranslationManager.hpp"

TranslationManager* TranslationManager::instance = nullptr;

void TranslationManager::loadLang(){

    std::vector<std::string> fileNames = {"../lang.yml"};

    if (!lang.empty()){

        fileNames.push_back("../lang-" + lang + ".yml");

    }

    for (const std::string& fileName : fileNames){

        try {

            YAML::Node translations = YAML::LoadFile(fileName);

            for (auto it = translations.begin(); it != translations.end(); ++it){

                strings[it->first.as<std::string>()] = it->second.as<std::string>();

            }

        } catch(YAML::BadFile& e){

            std::cout << "Cannot find file " << fileName << std::endl;
            delete(instance);
            instance = nullptr;

        }
    }
}

const std::string* TranslationManager::get(const char* id) const {

    auto iterator = strings.find(std::string(id));

    return iterator == strings.end() ? nullptr : &iterator->second;

}

TranslationManager* TranslationManager::getInstance(Langs lang){

    if (instance == nullptr){

        instance = new TranslationManager();

        instance->setLang(lang);

    }

    return instance;

}

void TranslationManager::setLang(Langs newLang) {

    std::string langId;

    switch (newLang){

        case FR:
            TranslationManager::lang = "fr";
            break;

        case EN:
        default:
            TranslationManager::lang = "";

    }

    loadLang();

}

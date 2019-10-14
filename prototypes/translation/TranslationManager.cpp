//
// Created by paragoumba on 08/10/2019.
//

#include <yaml-cpp/yaml.h>
#include <iostream>

#include "TranslationManager.hpp"

TranslationManager* TranslationManager::instance = nullptr;

const std::string* TranslationManager::get(const char* id) const {

    auto iterator = strings.find(std::string(id));

    return iterator == strings.end() ? nullptr : &iterator->second;

}

TranslationManager* TranslationManager::getInstance(){

    if (instance == nullptr){

        instance = new TranslationManager();
        std::string fileName("../lang.yml");

        try {

            YAML::Node lang = YAML::LoadFile(fileName);

            for (auto it = lang.begin(); it != lang.end(); ++it) {

                auto key = it->first.as<std::string>();
                auto value = it->second.as<std::string>();

                instance->strings.insert(std::make_pair(key, value));

                std::cout << key << ":" << value << std::endl;

            }

        } catch(YAML::BadFile& e){

            std::cout << "Cannot find file " << fileName << std::endl;
            delete(instance);
            instance = nullptr;

        }
    }

    return instance;

}

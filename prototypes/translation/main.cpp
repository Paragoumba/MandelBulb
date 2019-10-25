//
// Created by Paragoumba on 08/10/19.
//

#include <cstdlib>
#include <iostream>

#include "TranslationManager.hpp"

int main(){

    TranslationManager* translationManager = TranslationManager::getInstance(TranslationManager::FR);

    if (translationManager != nullptr){

        const std::string* s = translationManager->get("horse");

        if (s != nullptr) std::cout << "horse -> " << *s << std::endl;
        else std::cout << "Null" << std::endl;

        translationManager->setLang(TranslationManager::EN);

        const std::string* s2 = translationManager->get("milky-way");

        if (s2 != nullptr) std::cout << "milky-way -> " << *s2 << std::endl;
        else std::cout << "Null" << std::endl;

        delete (translationManager);

    }

    return EXIT_SUCCESS;

}
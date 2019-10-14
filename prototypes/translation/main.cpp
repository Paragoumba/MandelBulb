//
// Created by Paragoumba on 08/10/19.
//

#include <cstdlib>
#include <iostream>

#include "TranslationManager.hpp"

int main(){

    TranslationManager* translationManager = TranslationManager::getInstance();

    if (translationManager != nullptr) {

        const std::string* s = translationManager->get("test");

        if (s != nullptr) std::cout << *s << std::endl;
        else std::cout << "Null" << std::endl;

        delete (translationManager);

    }

    return EXIT_SUCCESS;

}
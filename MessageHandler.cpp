#include "MessageHandler.h"
#include <iostream>

MessageHandler::MessageHandler(const std::string& lang) : language(lang) {}

std::string MessageHandler::getMessage(const std::string& enMessage, const std::string& deMessage) const {
    return (language == "DE") ? deMessage : enMessage;
}

void MessageHandler::printMessage(const std::string& enMessage, const std::string& deMessage) const {
    std::cout << getMessage(enMessage, deMessage) << std::endl;
}

void MessageHandler::setLanguage(const std::string& lang) {
    language = lang;
}

#ifndef MESSAGE_HANDLER_H
#define MESSAGE_HANDLER_H

#include <string>
#include <iostream>

class MessageHandler {
    std::string language;

public:
    MessageHandler(const std::string& lang = "EN") : language(lang) {}

    std::string getMessage(const std::string& enMessage, const std::string& deMessage) const {
        if (language == "DE") {
            return deMessage;
        }
        return enMessage;
    }

    void printMessage(const std::string& enMessage, const std::string& deMessage) const {
        std::cout << getMessage(enMessage, deMessage) << std::endl;
    }

    void setLanguage(const std::string& lang) {
        language = lang;
    }
};

#endif // MESSAGE_HANDLER_H

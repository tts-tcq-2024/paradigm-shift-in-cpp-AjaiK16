#ifndef MESSAGE_HANDLER_H
#define MESSAGE_HANDLER_H

#include <string>

class MessageHandler {
    std::string language;

public:
    MessageHandler(const std::string& lang = "EN");
    std::string getMessage(const std::string& enMessage, const std::string& deMessage) const;
    void printMessage(const std::string& enMessage, const std::string& deMessage) const;
    void setLanguage(const std::string& lang);
};

#endif // MESSAGE_HANDLER_H

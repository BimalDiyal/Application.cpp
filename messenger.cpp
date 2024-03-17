#include <iostream>
#include <vector>
#include <string>

class Message {
public:
    std::string sender;
    std::string content;

    Message(const std::string& sender, const std::string& content)
        : sender(sender), content(content) {}
};

class Messenger {
private:
    std::vector<Message> messages;

public:
    void sendMessage(const std::string& sender, const std::string& content) {
        Message newMessage(sender, content);
        messages.push_back(newMessage);
    }

    void displayMessages() const {
        for (const auto& message : messages) {
            std::cout << "[" << message.sender << "]: " << message.content << std::endl;
        }
    }
};

int main() {
    Messenger messenger;

    std::cout << "Lite Messenger - Type 'exit' to end the conversation\n";

    std::string currentUser;
    std::cout << "Enter your username: ";
    std::cin >> currentUser;

    std::string recipient;
    std::cout << "Enter recipient's username: ";
    std::cin >> recipient;

    std::string input;
    while (true) {
        std::cout << currentUser << ": ";
        std::getline(std::cin, input);

        if (input == "exit") {
            break;
        }

        messenger.sendMessage(currentUser, input);
        messenger.displayMessages();
    }

    return 0;
}

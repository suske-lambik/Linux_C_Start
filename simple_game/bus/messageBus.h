#include <functional>
#include <queue>
#include <vector>
#include <iostream>


class Message
{
public:
    Message(const std::string event);
    std::string getEvent();
private:
    std::string messageEvent;
};

class MessageBus
{
public:
    MessageBus();
    ~MessageBus();

    void addReceiver(std::function<void (Message)> messageReceiver);
    void sendMessage(Message message);
    void notify();
private:
    std::vector<std::function<void (Message)>> receivers;
    std::queue<Message> messages;
};

/*
 * This class should be the base for all components which want to  
 * communicate via this bus
 */
class BusNode
{
public:
    BusNode(MessageBus *messageBus);
    virtual void update();
protected:
    std::function<void (Message)> getNotifyFunc();
    void send(Message message);
    virtual void onNotify(Message message);
    
    MessageBus *messageBus;
};

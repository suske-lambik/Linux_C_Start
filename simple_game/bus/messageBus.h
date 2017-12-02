#include <functional>
#include <queue>
#include <vector>
#include <iostream>

enum MessageId {A, B, C};

class Message
{
public:
    Message(MessageId id, const std::string event);
    MessageId getId() {return messageId;};
    std::string getEvent() {return messageEvent;};
private:
    std::string messageEvent;
    MessageId messageId;
};

class MessageBus
{
public:
    MessageBus();
    ~MessageBus();

    void addReceiver(MessageId id, std::function<void (Message)> messageReceiver);
    void sendMessage(Message message);
    void notify();
private:
    std::vector<std::vector<std::function<void (Message)>>> receivers;
    std::queue<Message> messages;
};

/*
 * This class should be the base for all components which want to  
 * communicate via this bus
 */
class BusNode
{
public:
    BusNode(MessageBus *mB, std::vector<MessageId> subIds);
    virtual void update();
protected:
    std::vector<MessageId> subscribedIds;
    std::function<void (Message)> getNotifyFunc(MessageId id);
    void send(Message message);
    virtual void onNotify(Message message);
    
    MessageBus *messageBus;
};

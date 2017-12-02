#include <iostream>
#include <string>

#include "messageBus.h"

class NodeA : public BusNode
{
public:
	NodeA(MessageBus* messageBus,  std::vector<MessageId> subIds) : BusNode(messageBus, subIds) {std::cout << "Create A" << std::endl;};
	void update()
	{
		std::cout << "Update A" << std::endl;
	};
private:
	void onNotify(Message message)
	{
		std::cout << "A has received: " << message.getEvent() << std::endl;
		if (messageIsGreeting(message)) {send(Message(MessageId::B, "Hi B! What's up?"));};
	};
	
	bool messageIsGreeting(Message msg)
	{
		std::size_t pos = msg.getEvent().find("hi");
		if (pos != std::string::npos) {return true;}
		return false;
	};
};

class NodeB : public BusNode
{
public:
	NodeB(MessageBus* messageBus,  std::vector<MessageId> subIds) : BusNode(messageBus, subIds) {m_greetingDone = false;};
	void update()
	{
		std::cout << "Update B" << std::endl;
		if(!m_greetingDone){
			send(Message(MessageId::A, "B says hi!"));
		}
		m_greetingDone = true;
	};
private:
	void onNotify(Message message)
	{
		std::cout << "B has received: " << message.getEvent() << std::endl;
		m_greetingDone = messageIsAnswer(message);
	};
	
	bool messageIsAnswer(Message msg)
	{
		std::size_t pos = msg.getEvent().find("What's up?");
		if (pos != std::string::npos) {return true;}
		return false;
	}
	
	bool m_greetingDone;
};

int main()
{
    std::cout << "Start" << std::endl;
    std::vector<MessageId> cA {B, C};
    std::vector<MessageId> cB {A, C};
    std::cout << "Start" << std::endl;
    MessageBus messageBus;
    NodeA compA(&messageBus, cA);
    std::cout << "Start" << std::endl;
    NodeB compB(&messageBus, cB);

    std::cout << "Start" << std::endl;
    // This is supposed to act like a game loop.
    for (int ctr = 0; ctr < 10; ctr++) {
        compA.update();
        compB.update();
        messageBus.notify();
    }

    return 0;
}

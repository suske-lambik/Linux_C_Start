#include <iostream>
#include <string>

#include "messageBus.h"

class NodeA : public BusNode
{
public:
	NodeA(MessageBus* messageBus) : BusNode(messageBus) {};
	void update()
	{
		std::cout << "Update A" << std::endl;
	};
private:
	void onNotify(Message message)
	{
		std::cout << "A has received: " << message.getEvent() << std::endl;
		if (messageIsGreeting(message)) {send(Message("Hi B! What's up?"));};
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
	NodeB(MessageBus* messageBus) : BusNode(messageBus) {m_greetingDone = false;};
	void update()
	{
		std::cout << "Update B" << std::endl;
		if(!m_greetingDone){
			send(Message("B says hi!"));
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
    MessageBus messageBus;
    NodeA compA(&messageBus);
    NodeB compB(&messageBus);

    // This is supposed to act like a game loop.
    for (int ctr = 0; ctr < 10; ctr++) {
        compA.update();
        compB.update();
        messageBus.notify();
    }

    return 0;
}

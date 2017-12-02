#include <functional>
#include <queue>
#include <vector>
#include <iostream>

#include "messageBus.h"


Message::Message(MessageId id, const std::string event)
{
	messageEvent = event;
    messageId = id;
}

MessageBus::MessageBus() {};

MessageBus::~MessageBus() {};

void MessageBus::addReceiver(MessageId id, std::function<void (Message)> messageReceiver)
{
    unsigned int idIdx = static_cast<unsigned int>(id);
    if (idIdx >= receivers.size()) {
        std::vector<std::function<void (Message)>> idRow;
        receivers.push_back(idRow);
    }
	receivers[static_cast<int>(id)].push_back(messageReceiver);
}

void MessageBus::sendMessage(Message message)
{
	messages.push(message);
}

void MessageBus::notify()
{
	while(!messages.empty()) {
        int idIdx = static_cast<int>(messages.front().getId());
		for (auto iter = receivers[idIdx].begin(); iter != receivers[idIdx].end(); iter++) {
			(*iter)(messages.front());
		}

		messages.pop();
	}
}

/*
 * This class should be the base for all components which want to  
 * communicate via this bus
 */
BusNode::BusNode(MessageBus * mB, std::vector<MessageId> subIds)
{
    std::cout << "Create BusNode" << std::endl;
    //~ subscribedIds.resize(subIds.size());
    //~ std::cout << "resize" << std::endl;
    subscribedIds = subIds;
	this->messageBus = mB;
    this->messageBus->addReceiver(A, this->getNotifyFunc(A));;
    //~ for (auto iter = subIds.begin(); iter != subIds.end(); iter ++) {
        //~ std::cout << "Add id " << std::endl;
        //~ std::cout << *iter << std::endl;    
        //~ subscribedIds.push_back(*iter);
        //~ std::cout << "Add id (cont'd)" << std::endl;
        //~ std::cout << *iter << std::endl;
        //~ std::cout << "Add id (cont'd)" << std::endl;
        //~ this->messageBus->addReceiver(*iter, this->getNotifyFunc(*iter));
        //~ std::cout << "Add id (final)" << std::endl;
    //~ }
}

void BusNode::update() {};
std::function<void (Message)> BusNode::getNotifyFunc(MessageId id)
{
	auto messageListener = [=](Message message) -> void {
		this->onNotify(message);
	};
	return messageListener;
}

void BusNode::send(Message message)
{
	messageBus->sendMessage(message);
}

void BusNode::onNotify(Message message)
{
	// Do something here. Your choice. You could do something like this.
	// std::cout << "Siopao! Siopao! Siopao! (Someone forgot to implement onNotify().)" << std::endl;
	std::cout << "Alarm alarm alarm! (Someone forgot to implement onNotify().)" << std::endl;
}



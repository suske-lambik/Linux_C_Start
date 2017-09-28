#include <functional>
#include <queue>
#include <vector>
#include <iostream>

#include "messageBus.h"


Message::Message(const std::string event)
{
	messageEvent = event;
}

std::string Message::getEvent()
{
	return messageEvent;
}

MessageBus::MessageBus() {};

MessageBus::~MessageBus() {};

void MessageBus::addReceiver(std::function<void (Message)> messageReceiver)
{
	receivers.push_back(messageReceiver);
}

void MessageBus::sendMessage(Message message)
{
	messages.push(message);
}

void MessageBus::notify()
{
	while(!messages.empty()) {
		for (auto iter = receivers.begin(); iter != receivers.end(); iter++) {
			(*iter)(messages.front());
		}

		messages.pop();
	}
}

/*
 * This class should be the base for all components which want to  
 * communicate via this bus
 */
BusNode::BusNode(MessageBus *messageBus)
{
	this->messageBus = messageBus;
	this->messageBus->addReceiver(this->getNotifyFunc());
}

void BusNode::update() {};
std::function<void (Message)> BusNode::getNotifyFunc()
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



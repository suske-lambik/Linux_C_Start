#include <iostream>

class messageQueue
{
	public:
		messageQueue();
		~messageQueue();
		void add_interface(std::int id, void* (*callbackFunction)(void*));
		void remove_interface(std::int id);
		void handle_msg(std::int id, 
	private:
		std::map<std::int , void* (*) (void*)> callback;
	
};


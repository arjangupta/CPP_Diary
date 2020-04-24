#include "specific_thread_user.hpp"

#include <iostream>
#include <sstream>

namespace thread_pool_example
{

SpecificThreadUser::SpecificThreadUser( const std::string& user_name,
                                        ThreadPoolInterface& thread_interface) :
    GenericThreadUser::GenericThreadUser(user_name, thread_interface)
{
    std::cout << "SpecificThreadUser constructor has been called: " << _user_name << std::endl;
}

SpecificThreadUser::~SpecificThreadUser()
{}

void SpecificThreadUser::_createJobs()
{
    _thread_pool_interface.sendSpecificThreadUserJob(this, &SpecificThreadUser::_waitForFood);
    _thread_pool_interface.sendSpecificThreadUserJob(this, &SpecificThreadUser::_decideToExercise);
}

void SpecificThreadUser::_waitForFood()
{
    std::stringstream output_str_stream;
    {
    std::lock_guard<std::mutex> user_name_lock_guard(_mutex_user_name);
    output_str_stream << _user_name << " is waiting for food..." << std::endl;
    }

    ThreadUserMessage waiting_for_food_message;
    waiting_for_food_message._payload      = output_str_stream.str();
    waiting_for_food_message._is_important = false;
    
    std::this_thread::sleep_for(std::chrono::seconds(1));

    {
    std::lock_guard<std::mutex> outbound_queue_lock(_mutex_outbound_queue);
    _outbound_queue.push(waiting_for_food_message);
    }
    
    output_str_stream.str("");
    output_str_stream.clear();
    {
    std::lock_guard<std::mutex> user_name_lock_guard(_mutex_user_name);
    output_str_stream << _user_name << " now requires food!" << std::endl;
    }

    ThreadUserMessage food_requirement_message;
    food_requirement_message._payload      = output_str_stream.str();
    food_requirement_message._is_important = true;

    {
    std::lock_guard<std::mutex> outbound_queue_lock(_mutex_outbound_queue);
    _outbound_queue.push(food_requirement_message);
    }
}

void SpecificThreadUser::_decideToExercise()
{
    std::stringstream output_str_stream;
    {
    std::lock_guard<std::mutex> user_name_lock(_mutex_user_name);
    output_str_stream << _user_name << " is thinking of exercising..." << std::endl;
    }

    ThreadUserMessage exercise_thinking_message;
    exercise_thinking_message._payload      = output_str_stream.str();
    exercise_thinking_message._is_important = false;

    {
    std::lock_guard<std::mutex> outbound_queue_lock(_mutex_outbound_queue);
    _outbound_queue.push(exercise_thinking_message);
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));
    
    output_str_stream.str("");
    output_str_stream.clear();
    {
    std::lock_guard<std::mutex> user_name_lock_guard(_mutex_user_name);
    output_str_stream << _user_name << " has decided to do " << rand() % 10 << " x 100 meter sprints!" << std::endl;
    }

    ThreadUserMessage exercise_decision_message;
    exercise_decision_message._payload      = output_str_stream.str();
    exercise_decision_message._is_important = true;

    {
    std::lock_guard<std::mutex> outbound_queue_lock(_mutex_outbound_queue);
    _outbound_queue.push(exercise_decision_message);
    }
}

} // namespace thread_pool_example
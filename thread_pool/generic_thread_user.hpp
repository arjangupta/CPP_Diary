#ifndef _GENERIC_THREAD_USER_HPP_
#define _GENERIC_THREAD_USER_HPP_

#include "thread_pool_interface.hpp"

#include <string>
#include <future>
#include <mutex>

namespace thread_pool_example
{

struct ThreadUserMessage final
{
    std::string _payload;
    bool        _is_important;
    bool        _is_empty;
};

class GenericThreadUser
{
public:
    GenericThreadUser() = delete;
    GenericThreadUser(const std::string&, ThreadPoolInterface&);
    virtual ~GenericThreadUser();
    void generateMessages();
    bool hasOutboundMessages() const;
    void getOldestMessage(ThreadUserMessage&) const;
    void notifyUsageOfOldestMessage();
protected:
    ThreadPoolInterface&          _thread_pool_interface;
    std::string                   _user_name;
    std::mutex                    _mutex_user_name;
    std::queue<ThreadUserMessage> _outbound_queue;
    std::mutex mutable            _mutex_outbound_queue;
private:
    virtual void _createJobs();
};

} // namespace thread_pool_example

#endif // _GENERIC_THREAD_USER_HPP_
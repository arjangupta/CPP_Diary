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
};

class GenericThreadUser
{
public:
    GenericThreadUser() = delete;
    GenericThreadUser(std::string&, ThreadPoolInterface&);
    virtual ~GenericThreadUser();
    void generateMessages();
protected:
    std::string&                               _user_name;
    std::mutex                                 _mutex_user_name;
    ThreadPoolInterface&                       _thread_pool_interface;
    std::queue<std::future<ThreadUserMessage>> _outbound_queue;
private:
    virtual void _createJobs();
};

} // namespace thread_pool_example

#endif // _GENERIC_THREAD_USER_HPP_
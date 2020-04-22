#ifndef _SPECIFIC_THREAD_USER_HPP_
#define _SPECIFIC_THREAD_USER_HPP_

#include "generic_thread_user.hpp"
#include "thread_pool_interface.hpp"

namespace thread_pool_example
{

class SpecificThreadUser final : public GenericThreadUser
{
public:
    SpecificThreadUser() = delete;
    SpecificThreadUser(std::string&, ThreadPoolInterface&);
    ~SpecificThreadUser();
private:
    void _createJobs() override;
    void _waitForFood();
    void _decideToExercise();
};

} // namespace thread_pool_example


#endif // _SPECIFIC_THREAD_USER_HPP_
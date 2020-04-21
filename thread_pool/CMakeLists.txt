add_executable(thread_pool_exec
    main.cpp
    thread_pool_interface.cpp
    generic_thread_user.cpp
    # x_specific_thread_user.cpp
    # y_specifc_thread_user.cpp
)

target_link_libraries(thread_pool_exec
    pthread
)
#include "Thread.hpp"

namespace ACLIB
{
    Thread::Thread()
        : m_thread_id(0)
        , m_running(true)
    {
        m_thread_handle = CreateThread(nullptr, 0, &Thread::startThread, this, 0, &m_thread_id);

        if(m_thread_handle == nullptr)
        {
            // err
        }
    }

    Thread::~Thread()
    {
        stop();
        CloseHandle(m_thread_handle);
    }

    void Thread::run()
    {
    }

    void Thread::stop()
    {
        m_running = false;
    }
}

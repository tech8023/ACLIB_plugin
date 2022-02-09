#ifndef ACLIB_PLUGIN_THREAD_HPP
#define ACLIB_PLUGIN_THREAD_HPP

#include <windows.h>

namespace ACLIB
{
    class Thread
    {
    private:
        DWORD  m_thread_id;
        HANDLE m_thread_handle;

    protected:
        bool m_running;

    public:
        Thread();
        ~Thread();

        static DWORD WINAPI startThread(LPVOID p)
        {
            if(p == nullptr)
            {
                // error
                return -1;
            }
            reinterpret_cast<Thread*>(p)->run();
            return 0;
        }

        virtual void run();
        virtual void stop();
    };

}  // namespace ACLIB

#endif  // ACLIB_PLUGIN_THREAD_HPP

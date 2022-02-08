#ifndef ACLIB_PLUGIN_MEMORY_HPP
#define ACLIB_PLUGIN_MEMORY_HPP

#include <windows.h>
#include <handleapi.h>

namespace ACLIB
{
    /**
     * Returns the size of an array at compile time.
     */
    template<class T, size_t N>
    constexpr size_t sizeOfArray(T (&)[N])
    {
        return N;
    }

    /**
     * Shared memory class. Stores the memory page handle and a pointer to the type of the memory
     * page.
     */
    template<typename T>
    class Memory
    {
    private:
        HANDLE m_handle;
        T*     m_data;

    public:
        explicit Memory(const char* name)
        {
            m_handle =
                CreateFileMapping(INVALID_HANDLE_VALUE, nullptr, PAGE_READWRITE, 0, sizeof(T), name);

            if(m_handle != nullptr)
            {
                m_data = reinterpret_cast<T*>(MapViewOfFile(m_handle, FILE_MAP_READ, 0, 0, sizeof(T)));
            }
        }

        T* data()
        {
            return m_data;
        }

        T operator*()
        {
            return *m_data;
        }

        T* operator->()
        {
            return m_data;
        }

        ~Memory()
        {
            CloseHandle(m_handle);
        }
    };
}  // namespace ACLIB

#endif  // ACLIB_PLUGIN_MEMORY_HPP

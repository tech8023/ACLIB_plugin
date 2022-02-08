#ifndef ACLIB_PLUGIN_EVENTLOOP_HPP
#define ACLIB_PLUGIN_EVENTLOOP_HPP

#include "AC.hpp"
#include "SharedMemory.hpp"
#include "util/Thread.hpp"

#include <vector>

namespace ACLIB
{
    class EventLoop : protected Thread
    {
    private:
        Uint32 m_timeout_ms;

        SharedMemory<AC::Physics> m_physics;
        SharedMemory<AC::Graphics> m_graphics;
        SharedMemory<AC::Statics> m_statics;

        AC::Physics m_physics_compare;
        AC::Graphics m_graphics_compare;
        AC::Statics m_statics_compare;

        std::vector<EVENT> m_events;

    public:
        EventLoop();

        virtual void run() override;

        void pumpEvent();
        void refreshCompare();
    };

}  // namespace ACLIB

#endif  // ACLIB_PLUGIN_EVENTLOOP_HPP

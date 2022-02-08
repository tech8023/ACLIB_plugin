#ifndef ACLIB_PLUGIN_ACLIB_HPP
#define ACLIB_PLUGIN_ACLIB_HPP

#include <cstdint>

namespace ACLIB
{
    typedef std::uint32_t Uint32;
    typedef std::int32_t  Sint32;
    typedef wchar_t       WChar;

    enum EVENT : Uint32
    {
        PHYSICS  = 0x00000000,
        GEAR_CHANGED,
        GRAPHICS = 0x10000000,
        STATUS_CHANGED,
        SESSION_CHANGED,
        COMPLETED_LAPS_CHANGED,
        POSITION_CHANGED,
        IS_IN_PIT,
        STATICS  = 0x20000000,
    };

}  // namespace ACLIB

#endif  // ACLIB_PLUGIN_ACLIB_HPP

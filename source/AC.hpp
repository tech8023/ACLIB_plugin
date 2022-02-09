#ifndef ACLIB_PLUGIN_AC_HPP
#define ACLIB_PLUGIN_AC_HPP

#include "ACLIB.hpp"

namespace AC
{
    using Uint32 = ACLIB::Uint32;
    using WChar  = ACLIB::WChar;

    enum class AC_SESSION : Uint32
    {
        UNKNOWN     = -1,
        PRACTICE    = 0,
        QUALIFYING  = 1,
        RACE        = 2,
        HOTLAP      = 3,
        TIME_ATTACK = 4,
        DRIFT       = 5,
        DRAG        = 6,
    };

    enum class AC_STATUS : Uint32
    {
        OFF    = 0,
        REPLAY = 1,
        LIVE   = 2,
        PAUSE  = 3,
    };

    struct Physics
    {
        Uint32 packetId               = 0;
        float  gas                    = 0;
        float  brake                  = 0;
        float  fuel                   = 0;
        Uint32 gear                   = 0;
        Uint32 rpm                    = 0;
        float  steerAngle             = 0;
        float  speedKmh               = 0;
        float  velocity[3]            = {};
        float  accG[3]                = {};
        float  wheelSlip[4]           = {};
        float  wheelLoad[4]           = {};
        float  wheelsPressure[4]      = {};
        float  wheelAngularSpeed[4]   = {};
        float  tyreWear[4]            = {};
        float  tyreDirtyLevel[4]      = {};
        float  tyreCoreTemperature[4] = {};
        float  camberRAD[4]           = {};
        float  suspensionTravel[4]    = {};
        float  drs                    = 0;
        float  tc                     = 0;
        float  heading                = 0;
        float  pitch                  = 0;
        float  roll                   = 0;
        float  cgHeight               = 0;
        float  carDamage[5]           = {};
        Uint32 numberOfTyresOut       = 0;
        Uint32 pitLimiterOn           = 0;
        float  abs                    = 0;
    };

    struct Graphics
    {
        Uint32     packetId              = 0;
        AC_STATUS  status                = AC_STATUS::OFF;
        AC_SESSION session               = AC_SESSION::PRACTICE;
        WChar      currentTime[15]       = {};
        WChar      lastTime[15]          = {};
        WChar      bestTime[15]          = {};
        WChar      split[15]             = {};
        Uint32     completedLaps         = 0;
        Uint32     position              = 0;
        Uint32     iCurrentTime          = 0;
        Uint32     iLastTime             = 0;
        Uint32     iBestTime             = 0;
        float      sessionTimeLeft       = 0;
        float      distanceTraveled      = 0;
        Uint32     isInPit               = 0;
        Uint32     currentSectorIndex    = 0;
        Uint32     lastSectorTime        = 0;
        Uint32     numberOfLaps          = 0;
        WChar      tyreCompound[33]      = {};
        float      replayTimeMultiplier  = 0;
        float      normalizedCarPosition = 0;
        float      carCoordinates[3]     = {};
    };

    struct Statics
    {
        WChar smVersion[15] = {};
        WChar acVersion[15] = {};

        // session static info
        Uint32 numberOfSessions  = 0;
        Uint32 numCars           = 0;
        WChar  carModel[33]      = {};
        WChar  track[33]         = {};
        WChar  playerName[33]    = {};
        WChar  playerSurname[33] = {};
        WChar  playerNick[33]    = {};
        Uint32 sectorCount       = 0;

        // car static info
        float  maxTorque              = 0;
        float  maxPower               = 0;
        Uint32 maxRpm                 = 0;
        float  maxFuel                = 0;
        float  suspensionMaxTravel[4] = {};
        float  tyreRadius[4]          = {};
    };

}  // namespace AC

#endif  // ACLIB_PLUGIN_AC_HPP

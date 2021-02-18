/** ****************************************************************************
 * \file Timer.h
 * \brief Interface for a class to track elapsed time.
 *
 * \author Daniel Heise
 * \version 0.0
 * \date February 2021
 * \bug n/a
 * \todo make timer asychronous - use <thread>
 * \copyright MIT License
 ******************************************************************************/
#ifndef TIMER_H_
#define TIMER_H_

#include <chrono>       // time utilities

/** ****************************************************************************
 * \class Timer Timer.h "Timer.h"
 * \brief This class measures time elapsed from a specific start time.
 ******************************************************************************/
class Timer
{
public:
    /** ************************************************************************
     * \brief sets the time from which the timer counts
     *
     * Uses steady_clock which is monotonic and not relient on the system time;
     * i.e. if system time is set in the past it will not affect the tick count
     *
     * \note every consecutive call updates the #start_time_ member variable
     **************************************************************************/
    void start();
    /** ************************************************************************
     * \brief calculates the time since the timer started
     *
     * The elapsed time is determined in chrono::nanoseconds followed by a 
     * chrono::duration conversion to represent the time as a double in seconds.
     * 
     * \return a double representing elapsed time in seconds
     **************************************************************************/
    double runtime_dbl();
private:
    /** ************************************************************************
     * \brief a point in time from which to start timing
     **************************************************************************/
    std::chrono::time_point<std::chrono::steady_clock> start_time_;
};

#endif // TIMER_H_
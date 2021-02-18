/** ****************************************************************************
 * \file Timer.cpp
 * \brief Implementation of a class (Timer) that tracks elapsed time from a
 *        given start point.
 *
 * \author Daniel Heise
 * \version 0.0
 * \date February 2021
 * \bug n/a
 * \todo n/a
 * \copyright MIT License
 ******************************************************************************/
#include "Timer.h"

/** ****************************************************************************
 * \brief sets the time from which the timer counts
 ******************************************************************************/
void Timer::start()
{
    start_time_ = std::chrono::steady_clock::now();
}
/** ****************************************************************************
 * \brief calculates the time since the timer started
 ******************************************************************************/
double Timer::runtime_dbl()
{
    using milliseconds_dbl = std::chrono::duration<double, std::ratio<1, 1>>;
    auto dt = std::chrono::steady_clock::now() - start_time_;

    return milliseconds_dbl(dt).count();
}

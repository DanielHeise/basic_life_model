/** ****************************************************************************
 * \file organism.h
 * \brief Interface to organism specific attributes and functionality.
 *
 * \author Daniel Heise
 * \version 0.0
 * \date February 2021
 * \bug n/a
 * \todo n/a
 * \copyright MIT License
 ******************************************************************************/
#ifndef ORGANISM_H_
#define ORGANISM_H_

#include <iostream>

/*!
 *  \addtogroup organism
 *  @{
 */

//! collection of attributes and functionality for organisms
namespace organism
{
/** ****************************************************************************
 * \brief the character used to represent an organism; i.e. for console output
 ******************************************************************************/
constexpr auto mark{'@'};

}

/*! @} end of addtogroup*/

#endif // ORGANISM_H_
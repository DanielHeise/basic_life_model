/** ****************************************************************************
 * \file string_literals.h
 * \brief Fixed string literals meant for user feedback, log entries, etc.
 * 
 * \author Daniel Heise
 * \version 0.0
 * \date February 2021
 * \bug n/a
 * \todo n/a
 * \copyright MIT License
 ******************************************************************************/
#ifndef STRING_LITERALS_H_
#define STRING_LITERALS_H_

#include <string_view>

/*!
 *  \addtogroup literals
 *  @{
 */

//! collection of string literals for user feedback
namespace literals
{

constexpr std::string_view GENERATION_LIT("Generation ");
constexpr std::string_view ALL_DEAD_LIT("All organisms have died.");
constexpr std::string_view HARMONY_LIT("Model reached harmony.");
constexpr std::string_view UNABLE_TO_STABLIZE_LIT("Model unable to stablize within generation limit.");
constexpr std::string_view TOTAL_BIRTHS_LIT("Total Births: ");
constexpr std::string_view TOTAL_DEATHS_LIT("Total Deaths: ");
constexpr std::string_view LIVING_ORGANISMS_LIT("Living Organisms: ");

}
/*! @} end of addtogroup*/

#endif // STRING_LITERALS_H_
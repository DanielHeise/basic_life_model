/** ****************************************************************************
 * \file colors.h
 * \brief Escape characters that modify the color of standard output.
 *
 * Usage:
 * \code
 * using namespace std;
 * using namespace colors;
 * 
 * cout << RED_BOLD << "Error(id10T): tell someone!!" << RESET_COLOR << endl;
 * \endcode
 * 
 * \author Daniel Heise
 * \version 0.0
 * \date February 2021
 * \bug n/a
 * \todo n/a
 * \copyright MIT License
 ******************************************************************************/
#ifndef CONSOLE_COLORS_H_
#define CONSOLE_COLORS_H_

#include <string_view>  // allows string-like objects to work with constexpr

/*!
 *  \addtogroup colors
 *  @{
 */

//! collection of escape characters and methods to modify standard output
namespace colors
{

constexpr std::string_view RED_BOLD("\033[31;1m");
constexpr std::string_view RED_NORM("\033[31m");

constexpr std::string_view YEL_BOLD("\033[33;1m");
constexpr std::string_view YEL_NORM("\033[33m");

constexpr std::string_view GRN_BOLD("\033[32;1m");
constexpr std::string_view GRN_NORM("\033[32m");

constexpr std::string_view BLU_BOLD("\033[34;1m");
constexpr std::string_view BLU_NORM("\033[34m");

constexpr std::string_view CYN_BOLD("\033[36;1m");
constexpr std::string_view CYN_NORM("\033[36m");

constexpr std::string_view MAG_BOLD("\033[35;1m");
constexpr std::string_view MAG_NORM("\033[35m");

constexpr std::string_view WHT_BOLD("\033[37;1m");
constexpr std::string_view WHT_NORM("\033[37m");

constexpr std::string_view BLK_BOLD("\033[30;1m");
constexpr std::string_view BLK_NORM("\033[30m");

constexpr std::string_view RESET_COLOR("\033[0m");


// TODO: consider implementing a call to clean up code using [colors]
// void print(std::string_view& _clr, const std::string& _msg, bool _endl);

}
/*! @} end of addtogroup*/

#endif // CONSOLE_COLORS_H_
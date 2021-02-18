/** ****************************************************************************
 * \file Cell.cpp
 * \brief Implements the smallest spacial unit in a grid. Cells may (not) be
 * populated with an organism.
 *
 * \author Daniel Heise
 * \version 0.0
 * \date February 2021
 * \bug n/a
 * \todo n/a
 * \copyright MIT License
 ******************************************************************************/
#include "Cell.h"

/** ****************************************************************************
 * \brief default constructor
 ******************************************************************************/
Cell::Cell()
: populated_(false)
{
    // default ctor
}
/** ****************************************************************************
 * \brief custom constructor
 ******************************************************************************/
Cell::Cell(bool _populated=false)
: populated_(_populated)
{
    // allow populating during instantiation
}
/** ****************************************************************************
 * \brief retrieves the cell matrix associated with this object
 ******************************************************************************/
bool Cell::empty()
{
    return populated_ ? false : true;
}
/** ****************************************************************************
 * \brief populates a cell
 ******************************************************************************/
void Cell::populate()
{
    populated_ = true;
}
/** ****************************************************************************
 * \brief depopulates a cell
 ******************************************************************************/
void Cell::depopulate()
{
    populated_ = false;
}
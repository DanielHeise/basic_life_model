/** ****************************************************************************
 * \file Cell.h
 * \brief Interface for the smallest spacial unit in a grid. Cells may (not) be
 * populated with an organism.
 *
 * \author Daniel Heise
 * \version 0.0
 * \date February 2021
 * \bug n/a
 * \todo n/a
 * \copyright MIT License
 ******************************************************************************/
#ifndef CELL_H_
#define CELL_H_

/** ****************************************************************************
 * \class Cell Cell.h "Cell.h"
 * \brief This class manages an individual cell.
 ******************************************************************************/
class Cell
{
public:
    /** ************************************************************************
     * \brief default constructor
     *
     * Creates an empty cell object
     **************************************************************************/
    Cell();
    /** ************************************************************************
     * \brief custom constructor
     *
     * Offers the ability to populate a cell object upon creation
     * 
     * \param[in] a boolean populated value; i.e. [True]empty, [False]populated
     **************************************************************************/
    Cell(bool);
    /** ************************************************************************
     * \brief retrieves a cell's populated state
     * 
     * \return a boolean value indicating cell vacancy
     * \see #populated_
     **************************************************************************/
    bool empty();
    /** ************************************************************************
     * \brief populates a cell
     *
     * Sets the #populated_ flag
     **************************************************************************/
    void populate();
    /** ************************************************************************
     * \brief depopulates a cell
     *
     * Clears the #populated_ flag
     **************************************************************************/
    void depopulate();
private:
    /** ************************************************************************
     * \brief flag indicated whether or not a cell is empty
     * \brief [False] populated
     * \brief [True] empty
     **************************************************************************/
    bool populated_;
};

#endif // CELL_H_
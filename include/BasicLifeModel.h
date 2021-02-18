/** ****************************************************************************
 * \file BasicLifeModel.h
 * \brief Interface to the model's rules and general behavior.
 *
 * \author Daniel Heise
 * \version 0.0
 * \date February 2021
 * \bug n/a
 * \todo n/a
 * \copyright MIT License
 ******************************************************************************/
#ifndef BASIC_LIFE_MODEL_H_
#define BASIC_LIFE_MODEL_H_

#include <iostream>
#include <utility>
#include "Grid.h"           // interface to the Grid class
#include "colors.h"         // console text colors

/*!
 *  \addtogroup basic_life_model
 *  @{
 */

//! collection of attributes and functionality related to the basic life model
namespace basic_life_model
{

/** ****************************************************************************
 * life transitions of an organism
 ******************************************************************************/
enum TRANSITIONS {
    BIRTH               = 0, /*!< an organism is born into an empty cell with 
                                  exactly three living neighbors */
    SURVIVAL,                /*!< an organism with either two or three living 
                                  neighbors survives from one generation to the 
                                  next */
    DEATH,                   /*!< an organism with four or more neighbors dies 
                                  from overcrowding. an organism with fewer than
                                  two neighbors dies from loneliness */
    NUM_TRANSITIONS
};

/** ****************************************************************************
 * \class BasicLifeModel BasicLifeModel.h "BasicLifeModel.h"
 * \brief This class manages the aspects of the Basic Life Model.
 ******************************************************************************/
class BasicLifeModel
{
public:
    /** ************************************************************************
     * \brief default constructor
     * 
     * Initializes all the member variables
     **************************************************************************/
    BasicLifeModel();
    /** ************************************************************************
     * \brief prints the underlying grid for the model
     **************************************************************************/
    void print();
    /** ************************************************************************
     * \brief triggers the next generational transition on the grid
     * 
     * The entire grid is updated cell-by-cell based on the model's rules
     **************************************************************************/
    void update();
    /** ************************************************************************
     * \brief checks if the model has stablized
     * 
     * \return boolean flag indicating the model has settled out
     **************************************************************************/
    bool harmony();
    /** ************************************************************************
     * \brief checks if any organisms are still alive
     * 
     * \return boolean flag indicating organism extinction
     **************************************************************************/
    bool all_dead();
    /** ************************************************************************
     * \brief getter for total simulation birth count
     * 
     * \return int reference to #births_total_
     **************************************************************************/
    const int& get_births_total();
    /** ************************************************************************
     * \brief getter for total simulation death count
     * 
     * \return int reference to #deaths_total_
     **************************************************************************/
    const int& get_deaths_total();
    /** ************************************************************************
     * \brief getter for last known living organism count
     * 
     * \return int reference to #organisms_living_
     **************************************************************************/
    const int& get_organisms_living();
private:
    /** ****************************************************************************
     * \brief determine the life transistion for a cell
     ******************************************************************************/
    TRANSITIONS life_transition(const std::pair<bool,int>& info)
    {
        // info.first = is cell empty?
        // info.second = number of neighbors
        if (info.first) {
            if (info.second == 3) {
                return TRANSITIONS::BIRTH;
            }
        } else {
            if (info.second >= 4 || info.second < 2) {
                return TRANSITIONS::DEATH;
            } else {
                return TRANSITIONS::SURVIVAL;
            }
        }

        return TRANSITIONS::NUM_TRANSITIONS;
    }
private:
    /** ************************************************************************
     * \brief birth count during entire simulation
     **************************************************************************/
    int births_total_;
    /** ************************************************************************
     * \brief death count during entire simulation
     **************************************************************************/
    int deaths_total_;
    /** ************************************************************************
     * \brief most current generation's organism count
     **************************************************************************/
    int organisms_living_;
    /** ************************************************************************
     * \brief flag indicating no organism exist
     **************************************************************************/
    bool bAllDead_;
    /** ************************************************************************
     * \brief flag indicating the model is stable
     **************************************************************************/
    bool bHarmony_;
    /** ************************************************************************
     * \brief grid of cells to run the simulation on
     **************************************************************************/
    grid::Grid modelgrid_;
};

} // namespace basic_life_model
/*! @} end of addtogroup*/

#endif // BASIC_LIFE_MODEL_H_
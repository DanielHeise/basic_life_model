/** ****************************************************************************
 * \file BasicLifeModel.cpp
 * \brief Implements the model's rules and general behavior.
 *
 * \author Daniel Heise
 * \version 0.0
 * \date February 2021
 * \bug n/a
 * \todo n/a
 * \copyright MIT License
 ******************************************************************************/
#include <iostream>
#include "BasicLifeModel.h"
#include "string_literals.h"

// #define DEBUG   1

using namespace basic_life_model;
using namespace literals;

/** ****************************************************************************
 * \brief default constructor
 ******************************************************************************/
BasicLifeModel::BasicLifeModel()
: births_total_(0), deaths_total_(0), organisms_living_(0), 
    bAllDead_(false), bHarmony_(false)
{
    // default ctor
}
/** ****************************************************************************
 * \brief prints the underlying grid for the model
 ******************************************************************************/
void BasicLifeModel::print()
{
    modelgrid_.print();
}
/** ****************************************************************************
 * \brief triggers the next generational transition on the grid
 ******************************************************************************/
void BasicLifeModel::update()
{
    static int it{0};
    #ifndef DEBUG
    system("clear");
    #endif
    std::cout << colors::WHT_BOLD << GENERATION_LIT << ++it << colors::RESET_COLOR << std::endl;

    auto births{0};
    auto deaths{0};
    auto organisms{0};
    for (auto col{1}; col<=static_cast<int>(grid::kN); ++col) {
        for (auto row{1}; row<=static_cast<int>(grid::kN); ++row) {
            auto cell_info = modelgrid_.get_cell_info(col, row);

            switch( life_transition(cell_info) )
            {
                case TRANSITIONS::BIRTH:
                    modelgrid_.populate_cell(col, row);
                    ++births;
                    ++organisms;
                    break;
                case TRANSITIONS::DEATH:
                    modelgrid_.depopulate_cell(col, row);
                    ++deaths;
                    break;
                case TRANSITIONS::SURVIVAL:
                    ++organisms;
                    break;
                default:
                    break;
            }

            #ifdef DEBUG
            std::cout << births << " " << deaths << " " << organisms << std::endl;
            #endif
        }
    }

    // update totals
    births_total_ += births;
    deaths_total_ += deaths;
    organisms_living_ = organisms;

    // check for model stability; all dead, no deaths & no births
    if (!organisms) {
        bAllDead_ = true;
    } else {
        if ( !births && !deaths ) {
            bHarmony_ = true;
        }
    }

    #ifdef DEBUG
    std::cout << "births: " << births << std::endl;
    std::cout << "deaths: " << deaths << std::endl;
    std::cout << "organisms: " << organisms << std::endl;
    #endif
}
/** ****************************************************************************
 * \brief checks if the model has stablized
 ******************************************************************************/
bool BasicLifeModel::harmony()
{
    return bHarmony_;
}
/** ****************************************************************************
 * \brief checks if any organisms are still alive
 ******************************************************************************/
bool BasicLifeModel::all_dead()
{
    return bAllDead_;
}
/** ****************************************************************************
 * \brief getter for total simulation birth count
 ******************************************************************************/
const int& BasicLifeModel::get_births_total()
{
    return births_total_;
}
/** ****************************************************************************
 * \brief getter for total simulation death count
 ******************************************************************************/
const int& BasicLifeModel::get_deaths_total()
{
    return deaths_total_;
}
/** ****************************************************************************
 * \brief getter for last known living organism count
 ******************************************************************************/
const int& BasicLifeModel::get_organisms_living()
{
    return organisms_living_;
}
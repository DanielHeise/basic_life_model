/** ****************************************************************************
 * \file Grid.h
 * \brief Interface to a container comprised of spacial units (i.e. cells). A 
 * grid is where organism relationships are derived and thus determines 
 * generational transitions; e.g. birth, survival, death.
 *
 * \author Daniel Heise
 * \version 0.0
 * \date February 2021
 * \bug n/a
 * \todo life transitions: make cell selection random; currently (first->last)
  * \copyright MIT License
 ******************************************************************************/
#ifndef GRID_H_
#define GRID_H_

#include <array>        // container for the cells of an area
#include <utility>
#include <random>       // random # generation for initial population of grid
#include "Cell.h"       // class Cell interface
#include "organism.h"   // contains symbol for organism
#include "colors.h"     // console text colors

/*!
 *  \addtogroup grid
 *  @{
 */

//! collection of attributes and functionality related to a Grid class
namespace grid
{

/** ****************************************************************************
 * \brief 1-D size of area; used to determine col/row depth
 ******************************************************************************/
static const unsigned int kN{10};
/** ****************************************************************************
 * \brief adds enough padding around the entire matrix to create a frame
 ******************************************************************************/
static const unsigned int frame{2};
/** ****************************************************************************
 * \brief slightly memory-bloated matrix; computation should be better
 ******************************************************************************/
static constexpr unsigned int kN_framed{kN + frame};
/** ****************************************************************************
 * \brief reusable definition for the grid color
 ******************************************************************************/
static const auto kGridColor{colors::CYN_BOLD};
/** ****************************************************************************
 * \brief reusable definition for the mark/organism color
 ******************************************************************************/
static const auto kMarkColor{colors::YEL_NORM};

/** ****************************************************************************
 * \class Grid Grid.h "Grid.h"
 * \brief This class manages a collection of cells.
 ******************************************************************************/
class Grid
{
public:
    /** ************************************************************************
     * \brief default constructor
     *
     * Initializes the #grid_ upon instantiation.
     **************************************************************************/
    Grid();
    /** ************************************************************************
     * \brief outputs an ascii matrix to standard out
     *
     * The matrix consists of characters representing walls and organisms.
     **************************************************************************/
    void print();
    /** ************************************************************************
     * \brief retrieves the cell matrix associated with this object
     * 
     * \return a reference to #grid_
     **************************************************************************/
    std::array<std::array<Cell, kN_framed>, kN_framed>& get_grid();
    /** ************************************************************************
     * \brief TODO
     * 
     * \param[in] TODO
     * \param[in] TODO
     * \return TODO
     **************************************************************************/
    std::pair<bool,int> get_cell_info(const int, const int);

    void populate_cell(const int&, const int&);

    void depopulate_cell(const int&, const int&);

private:
    /** ************************************************************************
     * \brief initialize each cell in the grid
     *
     * The grid is initialized in a linear fashion (first-->last) where each
     * cell is randomly determined to either have an organism of not.
     **************************************************************************/
    void init()
    {
        for (auto row{grid_.begin()+1}; row!=grid_.end()-1; ++row) {
            for (auto cell{row->begin()+1}; cell!=row->end()-1; ++cell) {
                populate_rand() ? cell->populate() : cell->depopulate();
            }
        }
    }
    /** ************************************************************************
     * \brief generates a boolean value at random
     *
     * A uniformily-distributed random number generator, using the Mersenne
     * Twister algorith, is used to produce either 0 or 1.
     **************************************************************************/
    bool populate_rand()
    {
        std::random_device rd;
        std::mt19937 re(rd());
        std::uniform_int_distribution<int> uidist(0, 1);

        return static_cast<bool>( uidist(re) ? true : false );
    }
    /** ************************************************************************
     * \brief outputs a set of characters representing a horizontal row
     **************************************************************************/
    void print_divide_horizontal()
    {
        std::cout << kGridColor;
        for (auto x{0}; x<static_cast<int>(kN); ++x){
            std::cout << "+---";
        }
        std::cout << "+";
        std::cout << colors::RESET_COLOR << std::endl;
    }
    /** ************************************************************************
     * \brief outputs a vertical "wall" character to the console
     **************************************************************************/
    void print_wall()
    {
        std::cout << kGridColor << "|" << colors::RESET_COLOR;
    }
    /** ************************************************************************
     * \brief outputs the cells contents to the console
     * 
     * \param[in] reference to a cell object
     **************************************************************************/
    void print_cell_contents(Cell& cell)
    {
        std::cout << " ";
        std::cout << kMarkColor << (cell.empty() ? ' ' : organism::mark);
        std::cout << " ";
    }
    /** ************************************************************************
     * \brief counts the number of populated cells surrounding a given cell
     * 
     * \param[in] reference to a cell object
     * \return an integer representing the surrounding neighbors with organisms
     **************************************************************************/
    int cnt_cell_neighbors(const int col, const int row)
    {
        auto neighbors{0};
        std::array<std::pair<int,int>, 8> offsets {
            std::make_pair<int,int>(-1,-1),
            std::make_pair<int,int>(0,-1),
            std::make_pair<int,int>(1,-1),
            std::make_pair<int,int>(1,0),
            std::make_pair<int,int>(1,1),
            std::make_pair<int,int>(0,1),
            std::make_pair<int,int>(-1,1),
            std::make_pair<int,int>(-1,0)
        };
        
        for (auto offset: offsets) {
            if (!grid_.at(col + offset.first).at(row + offset.second).empty()) {
                ++neighbors;
            }
        }

        return std::move(neighbors);
    }
    /** ************************************************************************
     * \brief counts the number of populated cells surrounding a given cell
     * 
     * \param[in] reference to a cell object
     * \return an integer representing the surrounding neighbors with organisms
     **************************************************************************/
    bool get_cell_state(const int col, const int row)
    {
        return grid_.at(col).at(row).empty();
    }
private:
    /** ************************************************************************
     * \brief matrix of kN_framed x kN_framed cells
     **************************************************************************/
    std::array<std::array<Cell, kN_framed>, kN_framed> grid_;
};

} // namespace grid
/*! @} end of addtogroup*/

#endif // GRID_H_
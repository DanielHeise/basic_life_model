/** ****************************************************************************
 * \file Grid.cpp
 * \brief Implements a container comprised of spacial units (i.e. cells). A grid
 * is where organism relationships are derived and thus determines generational
 * transitions; e.g. birth, survival, death.
 *
 * \author Daniel Heise
 * \version 0.0
 * \date February 2021
 * \bug n/a
 * \todo n/a
 * \copyright MIT License
 ******************************************************************************/
#include "Grid.h"

using namespace grid;

/** ****************************************************************************
 * \brief default constructor
 ******************************************************************************/
Grid::Grid()
{
    init();

    // for (auto row{grid_.begin()+1}; row!=grid_.end()-1; ++row) {
    //     for (auto cell{row->begin()+1}; cell!=row->end()-1; ++cell) {
    //         std::cout << std::boolalpha << cell->empty() << " ";
    //     }
    //     std::cout << std::endl;
    // }
}
/** ****************************************************************************
 * \brief outputs an ascii matrix to standard out
 ******************************************************************************/
void Grid::print()
{
    #if false
    for (auto& row : grid_) {
        print_divide_horizontal();
        for (auto& cell : row) {
            print_wall();
            print_cell_contents(cell);
        }
        print_wall();
        std::cout << std::endl;
    }
    print_divide_horizontal();
    #endif

    for (auto row{grid_.begin()+1}; row!=grid_.end()-1; ++row) {
        print_divide_horizontal();
        for (auto cell{row->begin()+1}; cell!=row->end()-1; ++cell) {
            print_wall();
            print_cell_contents(*cell);
        }
        print_wall();
        std::cout << std::endl;
    }
    print_divide_horizontal();

    // for (auto col{1}; col<=static_cast<int>(kN); ++col) {
    //     print_divide_horizontal();
    //     for (auto row{1}; row<=static_cast<int>(kN); ++row) {
    //         print_wall();
    //         print_cell_contents(grid_.at(col).at(row));
    //     }
    //     print_wall();
    //     std::cout << std::endl;
    // }
    // print_divide_horizontal();
}
/** ****************************************************************************
 * \brief retrieves the cell matrix associated with this object
 ******************************************************************************/
std::array<std::array<Cell, kN_framed>, kN_framed>& Grid::get_grid()
{
    return grid_;
}
/** ****************************************************************************
 * \brief retrieves cell state and the neighbor count
 ******************************************************************************/
std::pair<bool, int> Grid::get_cell_info(const int col, const int row)
{
    auto cnt{cnt_cell_neighbors(col, row)};
    auto state{get_cell_state(col, row)};

    return std::make_pair<bool, int>(std::forward<bool>(state), std::forward<int>(cnt));
}
/** ****************************************************************************
 * \brief places an organism in a cell
 ******************************************************************************/
void Grid::populate_cell(const int& col, const int& row)
{
    grid_.at(col).at(row).populate();
}
/** ****************************************************************************
 * \brief removes an organism from a cell
 ******************************************************************************/
void Grid::depopulate_cell(const int& col, const int& row)
{
    grid_.at(col).at(row).depopulate();
}
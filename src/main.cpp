/** ****************************************************************************
 * \file main.cpp
 * \brief Program for running simulations on the (basic) Life Model.
 *
 * \author Daniel Heise
 * \version 0.0
 * \date February 2021
 * \bug n/a
 * \todo make life_cycles configurable via commandline
 * \todo make model_rate configurable via commandline
 * \copyright MIT License
 ******************************************************************************/
#include <iostream>
#include "BasicLifeModel.h"
#include "Timer.h"
#include "colors.h"
#include "string_literals.h"

using namespace colors;
using namespace literals;

int main(int argc, char **argv) {
    Timer T;
    basic_life_model::BasicLifeModel model;
    auto model_rate{0.05};          // simulation rate; seconds
    auto life_cycles{50};          // simulation iterations

    // clear the console
    system("clear");

    // run the simulation
    std::cout << WHT_BOLD << GENERATION_LIT << "0" << RESET_COLOR << std::endl;
    model.print();
    do {
        T.start();
        model.update();
        model.print();

        // check if the model has reached "an end"
        if (model.all_dead()) {
            std::cout << RED_BOLD << ALL_DEAD_LIT << RESET_COLOR << std::endl;
            break;
        } else if (model.harmony()) {
            std::cout << GRN_BOLD << HARMONY_LIT << RESET_COLOR << std::endl;
            break;
        }

        // burn any remaining time before the next run
        while ( T.runtime_dbl() < model_rate ) { }
    } while (life_cycles--);

    // check if the model ever stablized
    if (!model.harmony() && !model.all_dead()) {
        std::cout << YEL_BOLD << UNABLE_TO_STABLIZE_LIT << RESET_COLOR << std::endl;
    }

    // output some statistics
    std::cout << TOTAL_BIRTHS_LIT << model.get_births_total() << std::endl;
    std::cout << TOTAL_DEATHS_LIT << model.get_deaths_total() << std::endl;
    std::cout << LIVING_ORGANISMS_LIT << model.get_organisms_living() << std::endl;
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
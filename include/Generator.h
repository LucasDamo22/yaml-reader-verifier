#ifndef GENERATOR_H
#define GENERATOR_H

/// @brief Generate a random number within a range.
/// @param min Smallest random number possible.
/// @param max Highest random number possible.
/// @return Return the random number.
float random(int min, int max);
/// @brief Generate the random yaml file.
/// @param utilizacao targeted utilization value for the random yaml file.
int generator(int utilizacao);

#endif
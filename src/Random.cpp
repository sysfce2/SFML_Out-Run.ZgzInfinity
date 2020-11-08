/*
 * Copyright (c) 2020 Andres Gavin
 * Copyright (c) 2020 Ruben Rodriguez
 *
 * This file is part of Out Run.
 * Out Run is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Out Run is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Out Run.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <random>
#include "../include/Random.hpp"


using namespace std;

static thread_local random_device rd;
static thread_local std::mt19937 generator(rd());
static thread_local uniform_real_distribution<float> dist(0.0f, 1.0f);

float random_zero_one() {
    return dist(generator);
}

int random_zero_n(int n) {
    return uniform_int_distribution<>(0, n)(generator);
}

int random_int(int min, int max) {
    return uniform_int_distribution<int>(min, max)(generator);
}

float random_float(float min, float max) {
    return uniform_real_distribution<float>(min, max)(generator);
}


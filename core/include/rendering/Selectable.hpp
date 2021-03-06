/*
 * Copyright (C) 2015  eBusiness Information
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef ARPIGL_SELECTABLE_HPP
#define ARPIGL_SELECTABLE_HPP

#include "glm/glm.hpp"

namespace dma {

    class Selectable {

    public:
        ~Selectable(){}

        virtual bool intersects(const glm::vec3& ray, const glm::vec3& origin) = 0;

    };
}

#endif //ARPIGL_SELECTABLE_HPP

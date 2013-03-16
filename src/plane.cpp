/* Copyright (C) 2013  Mike Pedersen
 * This file is part of Bumpier.
 * 
 * Bumpier is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 * 
 * Bumpier is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with Bumpier. If not, see <http://www.gnu.org/licenses/>.
 */

#include "models/plane.h"

Eigen::Matrix3f bumpier::plane::tangentspace(Eigen::Vector2f point) const
{
    return Eigen::Matrix3f::Identity();
}

Eigen::Vector3f bumpier::plane::position(Eigen::Vector2f point, float value) const
{
    Eigen::Vector3f v;
    v << point[0], point[1], value;
    return v;
}

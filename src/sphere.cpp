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

#include "models/sphere.h"

Eigen::Vector3f bumpier::sphere::normal(Eigen::Vector2f point) const
{
    Eigen::Vector2f v(point[0] * M_PI * 2, point[1] * M_PI);
    return Eigen::Vector3f(std::sin(v[1]) * std::cos(v[0]),
                           std::sin(v[1]) * std::sin(v[0]),
                           std::cos(v[1]));
}

Eigen::Vector3f bumpier::sphere::position(Eigen::Vector2f point, float value) const
{
    return normal(point) * ((value + 1.0) * 0.5 / M_PI);
}

Eigen::Matrix3f bumpier::sphere::tangentspace(Eigen::Vector2f point) const
{
	Eigen::Vector3f n = normal(point);
	Eigen::Vector3f t = normal(point + Eigen::Vector2f(0.0, 0.5));
    Eigen::Matrix3f m;
	
    m << t.cross(n), t, n;
	m.transposeInPlace();

    return m;
}

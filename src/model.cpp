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

#include "model.h"
#include <cassert>
#include <iostream>
#include <png++/png.hpp>

Eigen::Vector3f bumpier::model::position(const png::image<png::gray_pixel_16>& image, int x, int y) const
{
    return position(Eigen::Vector2f((float)x / image.get_width(), (float)y / image.get_height()), (float)image.get_pixel(x, y) / 0xFFFF);
}

png::image<png::rgb_pixel_16> bumpier::model::calculate_normals(const png::image<png::gray_pixel_16>& input, double phi, space_type space) const
{
    int width = input.get_width(), height = input.get_height();
    png::image<png::rgb_pixel_16> output(width, height);

    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
        {
            int xmin = (x + width  - 1) % width,
                ymin = (y + height - 1) % height,
                xmax = (x + 1) % width,
                ymax = (y + 1) % height;

            Eigen::Vector3f normal = (position(input, x, ymax) - position(input, x, ymin)).cross(
                                      position(input, xmax, y) - position(input, xmin, y));

            if(space == tangent_space)
				normal = tangentspace(Eigen::Vector2f((float)x / width, (float)y / height)) * normal;

			normal.normalize();

            normal = (normal.array() * 0.5 + 0.5) * 0xFFFF;
            output.set_pixel(x, y, png::rgb_pixel_16(normal[0], normal[1], normal[2]));
        }

    return output;
}

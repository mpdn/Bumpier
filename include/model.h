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

#ifndef MODEL_H
#define MODEL_H

#include <Eigen/Dense>
#include <png++/png.hpp>

namespace bumpier
{
	enum space_type
	{
		tangent_space,
		object_space
	};

	class model
	{
		private:
		Eigen::Vector3f position(const png::image<png::gray_pixel_16>& image, int x, int y) const;

		public:
		virtual ~model() { };

		//Returns the tangent space matrix at a given point
		virtual Eigen::Matrix3f tangentspace(Eigen::Vector2f point) const = 0;

		//Returns the 3D position of a point, displaced by a value
		virtual Eigen::Vector3f position(Eigen::Vector2f point, float value) const = 0;

		//Generates a normal map using this model and a displacement map.
		png::image<png::rgb_pixel_16> calculate_normals(
			const png::image<png::gray_pixel_16>& input,
			double phi = 1,
			space_type space = tangent_space) const;
	};
}

#endif // MODEL_H

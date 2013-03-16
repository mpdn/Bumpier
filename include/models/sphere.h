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

#ifndef BUMPIER_SPHERE_H
#define BUMPIER_SPHERE_H

#include "model.h"

namespace bumpier
{
	struct sphere : public model
	{
		Eigen::Matrix3f tangentspace(Eigen::Vector2f point) const;
		Eigen::Vector3f position(Eigen::Vector2f point, float value) const;

		private:
		Eigen::Vector3f normal(Eigen::Vector2f point) const;
	};
}

#endif

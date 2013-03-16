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

#include <iostream>
#include <memory>
#include <png++/png.hpp>
#include "cmdline.h"
#include "models/all"

int main(int argc, char **argv)
{
	try
	{
		gengetopt_args_info args;

		if (cmdline_parser(argc, argv, &args))
		    return 1;

		std::auto_ptr<bumpier::model> mdl;
		if (args.plane_given)
		    mdl = std::auto_ptr<bumpier::model>(new bumpier::plane());
		else if (args.sphere_given)
		    mdl = std::auto_ptr<bumpier::model>(new bumpier::sphere());

		bumpier::space_type space = args.object_space_flag ? bumpier::object_space : bumpier::tangent_space;
		png::image<png::gray_pixel_16> input(args.input_arg);
		mdl->calculate_normals(input, args.phi_arg, space).write(args.output_arg);
    	return 0;
	}
	catch (png::std_error& err)
	{
		std::cerr << err.what() << std::endl;
		return 1;
	}
}

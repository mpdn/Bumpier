Bumpier
=======
Bumpier is a simple command-line application for generating normal maps from bump maps. This is done using a 3-dimensional model (currently either a plane or a sphere).

Only PNG's are supported as input image. The output image will always be 16-bit PNG's. It might be a good idea to convert these to 8-bit to reduce file size.

Use the binary with the --help parameter for more information.

Building
--------
This project uses [Premake 4.3](http://industriousone.com/premake) in order to easily create cross-platform projects. The default premake file assumes a UNIX-like environment, but can be changed for different systems.

Bumpier has the following dependencies:
* Eigen3
* PNG++
* LibPNG
* Gengetopt (for building the parameter parser)

On an Ubuntu system, the process of building would be something like this (assuming premake4 is already installed):
	sudo apt-get install libeigen3-dev libpng++-dev libpng12-dev gengetopt &
	premake4 gmake &
	make config=release

To install it you can use the following commands:
	sudo cp Bumpier /usr/bin/bumpier &
	sudo chmod +x /usr/bin/bumpier

License
-------
This project is licensed under the LGPLv3 license. See COPYING for more information.

Authors
-------
[Mike Pedersen](https://github.com/Noctune)

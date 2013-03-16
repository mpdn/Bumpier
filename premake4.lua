local gengetoptcmd = "gengetopt"

if (os.execute(gengetoptcmd .. " --header-output-dir include --src-output-dir src < cmdline.ggo") ~= 0) then
	print "Gengetopt failed. Aborting"
	os.exit(1)
end

solution "Bumpier"
	configurations { "Debug", "Release" }

	project "Bumpier"
		kind "ConsoleApp"
		language "C++"
		files { "include/*.h", "src/*.cpp", "src/cmdline.c" }
		links { "png" }

		--These two directories have to be changed for non-unix systems
		includedirs { "include", "/usr/include/eigen3" }
		libdirs { "/usr/lib" }

		configuration "Debug"
			defines { "DEBUG" }
			flags { "Symbols" }
		
		configuration "Release"
			defines { "NDEBUG" }
			flags { "Optimize", "FloatFast" }

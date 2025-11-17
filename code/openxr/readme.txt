compiled using CMake, then Visual Studio

remember to add build\x64 dir

use CMake to configure, generate, then open project and compile debug+release

for mobile/arm64, use given platform provided libs (oculus/vive) (and only libs are really required, nothing else)
also copy includes as they are platform specific and are to be added to actual openxr (which comes from official builds)
	just remove "openxr/" where not required

includes are the same

copy libs into structure
lib\provider\platform\debugrelease
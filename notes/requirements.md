# Requirements

- CMAKE 3.10 or above
- GLFW 3 or above
- gcc, mingw OR clang
- GLAD [Current glad files](https://gen.glad.sh/#generator=c&api=gl%3D3.3&profile=gl%3Dcore%2Cgles1%3Dcommon&options=LOADER)

This file is used to find any GLFW installations that you might have on your OS when you run the cmake command.
I personally use cmake-gui to configure and generate.

[FindGLFW3 file](../cmake/FindGLFW3.cmake)

## Linux

You can install the GLFW libs and headers by using:

```sh
sudo apt-get install libglfw3
sudo apt-get install libglfw3-dev
```

This is pretty much hassle free and you'll basically have all the dependencies installed along the way.

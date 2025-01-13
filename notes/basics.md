# Basics

<!--toc:start-->

- [Basics](#basics)
  - [Core mode](#core-mode)
  - [Objects](#objects)
  <!--toc:end-->

OpenGL is a graphics library. I'll be using version 3.3 because all subsequent
versions just implement further add-ons to it.

Currently referencing the OpenGL book from here [OpenGL free book](https://learnopengl.com/book/book_pdf.pdf)

## Core mode

Core mode means we get to expose more of what OpenGL does as a state machine
and modify how it handles the graphics.
Core mode will raise an error whenever we don't use modern practices.

## Objects

Objects are collections of options that represent a subset of OpenGL's state.
The book exemplifies it as a C struct. OpenGL_Context is usually the set of options to set the window properties.

```c
struct OpenGL_Context {
...
object_name* object_Window_Target;
...
};

```

## Common workflow

```C
// create object
unsigned int objectId = 0;
glGenObject(1, &objectId);
// bind/assign object to context
glBindObject(GL_WINDOW_TARGET, objectId);
// set options of object currently bound to GL_WINDOW_TARGET
glSetObjectOption(GL_WINDOW_TARGET, GL_OPTION_WINDOW_WIDTH, 800);
glSetObjectOption(GL_WINDOW_TARGET, GL_OPTION_WINDOW_HEIGHT, 600);
// set context target back to default
glBindObject(GL_WINDOW_TARGET, 0);
```

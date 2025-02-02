# Drawing on the screen

## Multiple Colors

Each color that you require has to be specified on a fragment shader and its own program and be linked to it.

## Drawing several shapes

1. Initialize the VBO and VAO arrays
   `unsigned int VBOs[n], VAOs[n];`
2. Generate the gl array objects
   `glGenVertexArrays(n, VAOs);`
3. Generate the gl buffer objects
   `glGenBuffers(n, VBOs);`
4. Setup the shape(s) `n` times to be drawn using triangles:

   ```cpp
   glBindVertexArray(VAOs[n]);
   glBindBuffer(GL_ARRAY_BUFFER, VBOs[n]);
   glBufferData(GL_ARRAY_BUFFER, sizeof(nShape), nShape, GL_STATIC_DRAW);
   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
   glEnableVertexAttribArray(0);
   ```

This setup is necessary each time you want a new shape **with a
different shader**. We can also just use an Element buffer object to indicate
indices as well.

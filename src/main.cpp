/******************************************************************************
 * This is the main file from which we run the Window loop
 * @file main.cpp
 * @author felix-rojas
 * @brief
 * @version
 * @date 2025-01-20
 *
 ******************************************************************************/

#include <cmath>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <filesystem>
#include <fstream>
#include <glad/gl.h>
#include <iostream>
#include <string>

// utility for input_map debugging
#include "input_mapping.h"
input_mapping *input_mapping::instance = nullptr;

// the build path is the considered the current path
std::filesystem::path shaders = "../src/shaders";
std::filesystem::path vertex_shader = "../src/shaders/vertex.glsl";
std::filesystem::path fragment_shader = "../src/shaders/fragment.glsl";

/**
 * @brief Check if the current file exists before reading, OS-independent
 *
 * @param p is a filesystem path
 * @param s is the file status known by the OS
 * @return void, used for debugging
 */

void check_exists(
    const std::filesystem::path &p,
    std::filesystem::file_status s = std::filesystem::file_status{}) {
  std::cout << p;
  if (std::filesystem::status_known(s) ? std::filesystem::exists(s)
                                       : std::filesystem::exists(p))
    std::cout << " exists\n";
  else
    std::cout << " does not exist\n";
}

/**
 * @brief Read shader files
 *
 * @param filename is a string poiting towards the shader file to loadd
 * @return string with all the data from the shader file
 */

std::string readShaders(const std::string &filename) {
#ifdef DEBUG
  check_exists(filename);
#endif

  std::ifstream myfile(filename);
  // Read the whole file into a string
  std::string fileContent((std::istreambuf_iterator<char>(myfile)),
                          std::istreambuf_iterator<char>());

  // Close the file (optional here since the file will be
  // closed automatically when file goes out of scope)
  myfile.close();
  // Output the file content to the console
#ifdef DEBUG
  std::cout << "File content:\n" << fileContent << std::endl;
#endif
  return fileContent;
}

/** @defgroup settings Settings group
 * These are all the initial settings fro the window initialization
 * @{
 */
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);
void key_callback(GLFWwindow *window, int key, int scancode, int action,
                  int mods);
void mouse_button_callback(GLFWwindow *window, int key, int action, int mods);
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

/** @} */ // end of settings

int main() {

  std::string v_source = readShaders(vertex_shader.generic_string());
  std::string f_source = readShaders(fragment_shader.generic_string());

#ifdef DEBUG
  std::cout << v_source << std::endl;
  std::cout << f_source << std::endl;
#endif

  const char *vertexShaderSource = v_source.c_str();
  const char *fragmentShaderSource = f_source.c_str();

  // glfw: initialize and configure
  // ------------------------------
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  // glfw window creation
  // --------------------
  GLFWwindow *window =
      glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
  if (window == NULL) {

    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // glad: load all OpenGL function pointers
  // ---------------------------------------
  if (!gladLoadGL((GLADloadfunc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  // build and compile our shader program
  // ------------------------------------
  // vertex shader
  unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);
  // check for shader compile errors
  int success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
              << infoLog << std::endl;
  }
  // fragment shader
  unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);
  // check for shader compile errors
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
              << infoLog << std::endl;
  }
  // link shaders
  unsigned int shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);
  // check for linking errors
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
              << infoLog << std::endl;
  }
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  /** Set up vertex data (and buffer(s)) and configure vertex attributes.
   * These will be reused through an Element Object Buffer
   */
  float vertices[] = {
      // first triangle
      -0.9f, -0.5f, 0.0f, // left
      -0.0f, -0.5f, 0.0f, // right
      -0.45f, 0.5f, 0.0f, // top

      // second triangle
      0.0f, -0.5f, 0.0f, // left
      0.9f, -0.5f, 0.0f, // right
      0.45f, 0.5f, 0.0f  // top
  };
  //
  // /** Indicate the shapes we will make reusing the coordinates from the
  // vertices
  //  * array */
  // unsigned int indices[] = {
  //     // note that we start from 0!
  //     0, 1, 3, // first triangle
  //     1, 2, 3  // second triangle
  // };

  unsigned int VBO, VAO, EBO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);
  /** bind the Vertex Array Object first, then bind and set vertex buffer(s),
   * and then configure vertex attributes(s).
   */
  glBindVertexArray(VAO);
  /** copy vertices array
   */
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
  // GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  /** note that this is allowed, the call to glVertexAttribPointer
   * registered VBO as the vertex attribute's bound vertex buffer
   * object so afterwards we can safely unbind
   */
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  /** You can unbind the VAO afterwards so other VAO calls won't
   * accidentally modify this VAO, but this rarely happens.
   * Modifying other VAOs requires a call to glBindVertexArray
   * anyways so we generally don't unbind VAOs (nor VBOs) when it's
   * not directly necessary.
   */
  glBindVertexArray(0);

  // uncomment this call to draw in wireframe polygons.
  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  // render loop
  // -----------
  while (!glfwWindowShouldClose(window)) {
    // input
    // -----
    processInput(window);

    // render
    // ------
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // here we run the program to dynamicallly change on the while loop
    float timeValue = glfwGetTime();
    float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
    int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");

    // run the program
    glUseProgram(shaderProgram);
    glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

    glBindVertexArray(VAO); // seeing as we only have a single VAO there's no
                            // need to bind it every time, but we'll do so to
                            // keep things a bit more organized

    // We switched to drawing elements to reuse them
    glDrawArrays(GL_TRIANGLES, 0, 6);
    // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    // glBindVertexArray(0); // no need to unbind it every time

    // glfw: swap buffers and poll IO events (keys
    // pressed/released, mouse moved etc.)
    // -------------------------------------------------------------------------------
    glfwSwapBuffers(window);
    glfwPollEvents();
    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
  }

  // glfw: terminate, clearing all previously allocated GLFW
  // resources.
  // ------------------------------------------------------------------
  glfwTerminate();
  return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released
// this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback
// function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  // make sure the viewport matches the new window dimensions; note that width
  // and height will be significantly larger than specified on retina
  // displays.
  glViewport(0, 0, width, height);
}

/**
 * @brief Prints the received keyboard input as a US keyboard.
 *
 * @param window window instance
 * @param key integer code defined in the GLFW macros
 * @param scancode window instance
 * @param action Indicates whether the key is being pressed, held or released
 * @param mods registers if a modifier key is being pressed
 */

void key_callback(GLFWwindow *window, int key, int scancode, int action,
                  int mods) {
  // singleton instance of the input_maps
  input_mapping *input_mapInstance = input_mapping::getInstance();

  if (mods)
    std::cout << input_mapInstance->getModKeyName(mods) << " + ";
  if (action == GLFW_PRESS)
    std::cout << "Pressed: " << input_mapInstance->getKeyName(key) << std::endl;
  if (action == GLFW_RELEASE)
    std::cout << "Released: " << input_mapInstance->getKeyName(key)
              << std::endl;
  if (action == GLFW_REPEAT)
    std::cout << "Holding: " << input_mapInstance->getKeyName(key) << std::endl;
}

void mouse_button_callback(GLFWwindow *window, int key, int action, int mods) {
  input_mapping *input_mapInstance = input_mapping::getInstance();
  if (action == GLFW_PRESS)
    std::cout << "Pressed: " << input_mapInstance->getMouseKeyName(key)
              << std::endl;
  if (action == GLFW_RELEASE)
    std::cout << "Released: " << input_mapInstance->getMouseKeyName(key)
              << std::endl;
  if (action == GLFW_REPEAT)
    std::cout << "Holding: " << input_mapInstance->getMouseKeyName(key)
              << std::endl;
}

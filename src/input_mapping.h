#ifndef INPUT_MAPPING_H
#define INPUT_MAPPING_H
#include <map>
#include <string>

/******************************************************************************
 * @file input_mapping.h
 * @author felix-rojas
 * @brief header that contains maps of most inputs defined in GLFW
 * @version
 * @date 2025-02-02
 *
 ******************************************************************************/

class input_mapping {
private:
  static input_mapping *instance;

  // Private constructor to prevent instantiation
  input_mapping() {}

  // Delete copy constructor and assignment operator to prevent copying
  input_mapping(const input_mapping &) = delete;
  input_mapping &operator=(const input_mapping &) = delete;

  const std::map<const int, const std::string> glfw_mapped_keys = {
      {32, "GLFW_KEY_SPACE"},
      {39, "GLFW_KEY_APOSTROPHE"}, /* ' */
      {44, "GLFW_KEY_COMMA"},      /* , */
      {45, "GLFW_KEY_MINUS"},      /* - */
      {46, "GLFW_KEY_PERIOD"},     /* . */
      {47, "GLFW_KEY_SLASH"},      /* / */
      {48, "GLFW_KEY_0"},
      {49, "GLFW_KEY_1"},
      {50, "GLFW_KEY_2"},
      {51, "GLFW_KEY_3"},
      {52, "GLFW_KEY_4"},
      {53, "GLFW_KEY_5"},
      {54, "GLFW_KEY_6"},
      {55, "GLFW_KEY_7"},
      {56, "GLFW_KEY_8"},
      {57, "GLFW_KEY_9"},
      {59, "GLFW_KEY_SEMICOLON"}, /* ; */
      {61, "GLFW_KEY_EQUAL"},     /* = */
      {65, "GLFW_KEY_A"},
      {66, "GLFW_KEY_B"},
      {67, "GLFW_KEY_C"},
      {68, "GLFW_KEY_D"},
      {69, "GLFW_KEY_E"},
      {70, "GLFW_KEY_F"},
      {71, "GLFW_KEY_G"},
      {72, "GLFW_KEY_H"},
      {73, "GLFW_KEY_I"},
      {74, "GLFW_KEY_J"},
      {75, "GLFW_KEY_K"},
      {76, "GLFW_KEY_L"},
      {77, "GLFW_KEY_M"},
      {78, "GLFW_KEY_N"},
      {79, "GLFW_KEY_O"},
      {80, "GLFW_KEY_P"},
      {81, "GLFW_KEY_Q"},
      {82, "GLFW_KEY_R"},
      {83, "GLFW_KEY_S"},
      {84, "GLFW_KEY_T"},
      {85, "GLFW_KEY_U"},
      {86, "GLFW_KEY_V"},
      {87, "GLFW_KEY_W"},
      {88, "GLFW_KEY_X"},
      {89, "GLFW_KEY_Y"},
      {90, "GLFW_KEY_Z"},
      {91, "GLFW_KEY_LEFT_BRACKET"},  /* [ */
      {92, "GLFW_KEY_BACKSLASH"},     /* \ */
      {93, "GLFW_KEY_RIGHT_BRACKET"}, /* ] */
      {96, "GLFW_KEY_GRAVE_ACCENT"},  /* ` */
      {161, "GLFW_KEY_WORLD_1"},      /* non-US #1 */
      {162, "GLFW_KEY_WORLD_2"},      /* non-US #2 */
      {256, "GLFW_KEY_ESCAPE"},
      {257, "GLFW_KEY_ENTER"},
      {258, "GLFW_KEY_TAB"},
      {259, "GLFW_KEY_BACKSPACE"},
      {260, "GLFW_KEY_INSERT"},
      {261, "GLFW_KEY_DELETE"},
      {262, "GLFW_KEY_RIGHT"},
      {263, "GLFW_KEY_LEFT"},
      {264, "GLFW_KEY_DOWN"},
      {265, "GLFW_KEY_UP"},
      {266, "GLFW_KEY_PAGE_UP"},
      {267, "GLFW_KEY_PAGE_DOWN"},
      {268, "GLFW_KEY_HOME"},
      {269, "GLFW_KEY_END"},
      {280, "GLFW_KEY_CAPS_LOCK"},
      {281, "GLFW_KEY_SCROLL_LOCK"},
      {282, "GLFW_KEY_NUM_LOCK"},
      {283, "GLFW_KEY_PRINT_SCREEN"},
      {284, "GLFW_KEY_PAUSE"},
      {290, "GLFW_KEY_F1"},
      {291, "GLFW_KEY_F2"},
      {292, "GLFW_KEY_F3"},
      {293, "GLFW_KEY_F4"},
      {294, "GLFW_KEY_F5"},
      {295, "GLFW_KEY_F6"},
      {296, "GLFW_KEY_F7"},
      {297, "GLFW_KEY_F8"},
      {298, "GLFW_KEY_F9"},
      {299, "GLFW_KEY_F10"},
      {300, "GLFW_KEY_F11"},
      {301, "GLFW_KEY_F12"},
      {302, "GLFW_KEY_F13"},
      {303, "GLFW_KEY_F14"},
      {304, "GLFW_KEY_F15"},
      {305, "GLFW_KEY_F16"},
      {306, "GLFW_KEY_F17"},
      {307, "GLFW_KEY_F18"},
      {308, "GLFW_KEY_F19"},
      {309, "GLFW_KEY_F20"},
      {310, "GLFW_KEY_F21"},
      {311, "GLFW_KEY_F22"},
      {312, "GLFW_KEY_F23"},
      {313, "GLFW_KEY_F24"},
      {314, "GLFW_KEY_F25"},
      {320, "GLFW_KEY_KP_0"},
      {321, "GLFW_KEY_KP_1"},
      {322, "GLFW_KEY_KP_2"},
      {323, "GLFW_KEY_KP_3"},
      {324, "GLFW_KEY_KP_4"},
      {325, "GLFW_KEY_KP_5"},
      {326, "GLFW_KEY_KP_6"},
      {327, "GLFW_KEY_KP_7"},
      {328, "GLFW_KEY_KP_8"},
      {329, "GLFW_KEY_KP_9"},
      {330, "GLFW_KEY_KP_DECIMAL"},
      {331, "GLFW_KEY_KP_DIVIDE"},
      {332, "GLFW_KEY_KP_MULTIPLY"},
      {333, "GLFW_KEY_KP_SUBTRACT"},
      {334, "GLFW_KEY_KP_ADD"},
      {335, "GLFW_KEY_KP_ENTER"},
      {336, "GLFW_KEY_KP_EQUAL"},
      {340, "GLFW_KEY_LEFT_SHIFT"},
      {341, "GLFW_KEY_LEFT_CONTROL"},
      {342, "GLFW_KEY_LEFT_ALT"},
      {343, "GLFW_KEY_LEFT_SUPER"},
      {344, "GLFW_KEY_RIGHT_SHIFT"},
      {345, "GLFW_KEY_RIGHT_CONTROL"},
      {346, "GLFW_KEY_RIGHT_ALT"},
      {347, "GLFW_KEY_RIGHT_SUPER"},
      {348, "GLFW_KEY_MENU"}};

  const std::map<const int, const std::string> glfw_mod_mapped_keys = {
      {0x0001, "GLFW_MOD_SHIFT"},     {0x0002, "GLFW_MOD_CONTROL"},
      {0x0004, "GLFW_MOD_ALT"},       {0x0008, "GLFW_MOD_SUPER"},
      {0x0010, "GLFW_MOD_CAPS_LOCK"}, {0x0020, "GLFW_MOD_NUM_LOCK"}};

  const std::map<const int, const std::string> glfw_mouse_mapped_keys = {
      {0, "GLFW_MOUSE_BUTTON_1"}, {1, "GLFW_MOUSE_BUTTON_2"},
      {2, "GLFW_MOUSE_BUTTON_3"}, {3, "GLFW_MOUSE_BUTTON_4"},
      {4, "GLFW_MOUSE_BUTTON_5"}, {5, "GLFW_MOUSE_BUTTON_6"},
      {6, "GLFW_MOUSE_BUTTON_7"}, {7, "GLFW_MOUSE_BUTTON_8"}};

public:
  static input_mapping *getInstance() {
    if (instance == nullptr) {
      instance = new input_mapping();
    }
    return instance;
  }
  std::string getKeyName(int keyCode) {
    auto it = glfw_mapped_keys.find(keyCode);
    if (it != glfw_mapped_keys.end()) {
      return it->second;
    }
    return "UNKNOWN_KEY";
  }
  std::string getModKeyName(int modKeyCode) {
    std::string res = "UNKNOWN_KEY: " + std::to_string(modKeyCode);
    auto it = glfw_mod_mapped_keys.find(modKeyCode);
    if (it != glfw_mod_mapped_keys.end()) {
      return it->second;
    }
    return res;
  }

  std::string getMouseKeyName(int keyCode) {
    auto it = glfw_mouse_mapped_keys.find(keyCode);
    if (it != glfw_mouse_mapped_keys.end()) {
      return it->second;
    }
    return "UNKNOWN_KEY";
  }
};
#endif // INPUT_MAPPING_H

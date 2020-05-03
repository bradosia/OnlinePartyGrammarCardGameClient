/*
 * @name Crazy Sentences Online
 * @author Branden Lee
 * @version 1.00
 * @license MIT
 * @brief A game for ESL students to learn and have fun!
 */

#ifndef CRAZY_SENTENCES_ONLINE_CLIENT_MODULE_CLIENT_H
#define CRAZY_SENTENCES_ONLINE_CLIENT_MODULE_CLIENT_H

// Config
#include "../core/config.hpp"

// C++
#include <iostream>
#include <memory>

/* Dear ImGui 1.75
 * License: MIT
 */
#include <imgui/imgui.h>
#include <imgui/imgui_impl_sdl.h>
#include <imgui/imgui_impl_opengl3.h>

/* Ogre3D 1.12.2
 * License: MIT
 */
#include <OgreRenderWindow.h>
#include <OgreRoot.h>
#include <OgreTextureManager.h>
// basically does #include <GL/glew.h>
#include <RenderSystems/GL/OgreGLRenderSystem.h>
#include <RenderSystems/GL/OgreGLTexture.h>

// Local Project
#include "../Interface.hpp"

/*
 * CSO = Crazy Sentences Online
 */
namespace CSO {

class ClientWidget : public Client {

public:
  ClientWidget();
  ~ClientWidget();
  // Interface
  bool handleEventFromSdl(SDL_Event *);
  void setMainLoopFlag(bool *);
  bool initGraphics(SDL_Window *);
  bool render();

  // Custom
  void setStyle1();
  void addDrawArrow();

  ImFont *fontArialTitle;
  ImFont *fontArialText;
  Ogre::Root *root;

protected:
  void initializeGL();

private:
  /* Does not take ownership of the window
   * No guarantee window pointer is valid
   */
  SDL_Window *window;
  bool* mainLoopFlag;
  // Our state
  ImVec4 clear_color;
  // Decide GL+GLSL versions
#if __APPLE__
  // GL 3.2 + GLSL 150
  const char *glsl_version = "#version 150";
#else
  // GL 3.0 + GLSL 130
  const char *glsl_version = "#version 130";
  unsigned int textureName = 1;
  unsigned int glID = 0;
#endif
};

} // namespace CSO

#endif
// end CRAZY_SENTENCES_ONLINE_CLIENT_MODULE_CLIENT_H
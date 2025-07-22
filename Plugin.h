#ifndef PLUGIN_H
#define PLUGIN_H

#include <Arduino.h>

// Base class for plugin modules in MATA
class Plugin {
public:
  virtual void init() = 0;           // Called at startup
  virtual void update() = 0;         // Called every loop
  virtual String getName() = 0;      // Identifies the plugin
};

#endif

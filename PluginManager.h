#ifndef PLUGIN_MANAGER_H
#define PLUGIN_MANAGER_H

void initPlugins();        // Load plugins at boot
void updatePlugins();      // Call plugin logic every loop
void listPlugins();        // Display plugin names to user

#endif

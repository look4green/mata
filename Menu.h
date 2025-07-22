#ifndef MENU_H
#define MENU_H

#include <Arduino.h>

// Menu system for MATA: navigable screens, state switching, and preview zones

void initMenu();             // Setup menu system
void updateMenu();           // Refresh display + selection
void nextMenuItem();         // Move down
void prevMenuItem();         // Move up
void selectMenuItem();       // Trigger selected action
int getMenuIndex();          // For external querying
void setMenuIndex(int index);

#endif

#ifndef BUTTON_H
#define BUTTON_H

#include <raylib.h>

int initialize_buttons(void);
void delete_buttons(void);
int create_button(const float x, const float y, const float width, const float height, const Texture2D* texture);

#endif // !BUTTON_H
#ifndef TABLE_H
#define TABLE_H

void draw_table();
int initialize_buttons(void);
void delete_buttons(void);
int create_button(const float x, const float y, const float width,
				  const float height);
bool is_clicking_box(const Vector2);

#endif // !TABLE_H

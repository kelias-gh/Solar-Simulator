#include "SGL.h"
#include <stdio.h>
#include <math.h>

#define G_CONST 0.0001
char font8x8_basic[128][8] = {
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0000 (nul)
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0001
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0002
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0003
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0004
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0005
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0006
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0007
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0008
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0009
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+000A
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+000B
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+000C
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+000D
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+000E
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+000F
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0010
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0011
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0012
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0013
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0014
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0015
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0016
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0017
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0018
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0019
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+001A
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+001B
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+001C
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+001D
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+001E
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+001F
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0020 (space)
    {0x18, 0x3C, 0x3C, 0x18, 0x18, 0x00, 0x18, 0x00}, // U+0021 (!)
    {0x36, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0022 (")
    {0x36, 0x36, 0x7F, 0x36, 0x7F, 0x36, 0x36, 0x00}, // U+0023 (#)
    {0x0C, 0x3E, 0x03, 0x1E, 0x30, 0x1F, 0x0C, 0x00}, // U+0024 ($)
    {0x00, 0x63, 0x33, 0x18, 0x0C, 0x66, 0x63, 0x00}, // U+0025 (%)
    {0x1C, 0x36, 0x1C, 0x6E, 0x3B, 0x33, 0x6E, 0x00}, // U+0026 (&)
    {0x06, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0027 (')
    {0x18, 0x0C, 0x06, 0x06, 0x06, 0x0C, 0x18, 0x00}, // U+0028 (()
    {0x06, 0x0C, 0x18, 0x18, 0x18, 0x0C, 0x06, 0x00}, // U+0029 ())
    {0x00, 0x66, 0x3C, 0xFF, 0x3C, 0x66, 0x00, 0x00}, // U+002A (*)
    {0x00, 0x0C, 0x0C, 0x3F, 0x0C, 0x0C, 0x00, 0x00}, // U+002B (+)
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x06}, // U+002C (,)
    {0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00}, // U+002D (-)
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x00}, // U+002E (.)
    {0x60, 0x30, 0x18, 0x0C, 0x06, 0x03, 0x01, 0x00}, // U+002F (/)
    {0x3E, 0x63, 0x73, 0x7B, 0x6F, 0x67, 0x3E, 0x00}, // U+0030 (0)
    {0x0C, 0x0E, 0x0C, 0x0C, 0x0C, 0x0C, 0x3F, 0x00}, // U+0031 (1)
    {0x1E, 0x33, 0x30, 0x1C, 0x06, 0x33, 0x3F, 0x00}, // U+0032 (2)
    {0x1E, 0x33, 0x30, 0x1C, 0x30, 0x33, 0x1E, 0x00}, // U+0033 (3)
    {0x38, 0x3C, 0x36, 0x33, 0x7F, 0x30, 0x78, 0x00}, // U+0034 (4)
    {0x3F, 0x03, 0x1F, 0x30, 0x30, 0x33, 0x1E, 0x00}, // U+0035 (5)
    {0x1C, 0x06, 0x03, 0x1F, 0x33, 0x33, 0x1E, 0x00}, // U+0036 (6)
    {0x3F, 0x33, 0x30, 0x18, 0x0C, 0x0C, 0x0C, 0x00}, // U+0037 (7)
    {0x1E, 0x33, 0x33, 0x1E, 0x33, 0x33, 0x1E, 0x00}, // U+0038 (8)
    {0x1E, 0x33, 0x33, 0x3E, 0x30, 0x18, 0x0E, 0x00}, // U+0039 (9)
    {0x00, 0x0C, 0x0C, 0x00, 0x00, 0x0C, 0x0C, 0x00}, // U+003A (:)
    {0x00, 0x0C, 0x0C, 0x00, 0x00, 0x0C, 0x0C, 0x06}, // U+003B (;)
    {0x18, 0x0C, 0x06, 0x03, 0x06, 0x0C, 0x18, 0x00}, // U+003C (<)
    {0x00, 0x00, 0x3F, 0x00, 0x00, 0x3F, 0x00, 0x00}, // U+003D (=)
    {0x06, 0x0C, 0x18, 0x30, 0x18, 0x0C, 0x06, 0x00}, // U+003E (>)
    {0x1E, 0x33, 0x30, 0x18, 0x0C, 0x00, 0x0C, 0x00}, // U+003F (?)
    {0x3E, 0x63, 0x7B, 0x7B, 0x7B, 0x03, 0x1E, 0x00}, // U+0040 (@)
    {0x0C, 0x1E, 0x33, 0x33, 0x3F, 0x33, 0x33, 0x00}, // U+0041 (A)
    {0x3F, 0x66, 0x66, 0x3E, 0x66, 0x66, 0x3F, 0x00}, // U+0042 (B)
    {0x3C, 0x66, 0x03, 0x03, 0x03, 0x66, 0x3C, 0x00}, // U+0043 (C)
    {0x1F, 0x36, 0x66, 0x66, 0x66, 0x36, 0x1F, 0x00}, // U+0044 (D)
    {0x7F, 0x46, 0x16, 0x1E, 0x16, 0x46, 0x7F, 0x00}, // U+0045 (E)
    {0x7F, 0x46, 0x16, 0x1E, 0x16, 0x06, 0x0F, 0x00}, // U+0046 (F)
    {0x3C, 0x66, 0x03, 0x03, 0x73, 0x66, 0x7C, 0x00}, // U+0047 (G)
    {0x33, 0x33, 0x33, 0x3F, 0x33, 0x33, 0x33, 0x00}, // U+0048 (H)
    {0x1E, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x1E, 0x00}, // U+0049 (I)
    {0x78, 0x30, 0x30, 0x30, 0x33, 0x33, 0x1E, 0x00}, // U+004A (J)
    {0x67, 0x66, 0x36, 0x1E, 0x36, 0x66, 0x67, 0x00}, // U+004B (K)
    {0x0F, 0x06, 0x06, 0x06, 0x46, 0x66, 0x7F, 0x00}, // U+004C (L)
    {0x63, 0x77, 0x7F, 0x7F, 0x6B, 0x63, 0x63, 0x00}, // U+004D (M)
    {0x63, 0x67, 0x6F, 0x7B, 0x73, 0x63, 0x63, 0x00}, // U+004E (N)
    {0x1C, 0x36, 0x63, 0x63, 0x63, 0x36, 0x1C, 0x00}, // U+004F (O)
    {0x3F, 0x66, 0x66, 0x3E, 0x06, 0x06, 0x0F, 0x00}, // U+0050 (P)
    {0x1E, 0x33, 0x33, 0x33, 0x3B, 0x1E, 0x38, 0x00}, // U+0051 (Q)
    {0x3F, 0x66, 0x66, 0x3E, 0x36, 0x66, 0x67, 0x00}, // U+0052 (R)
    {0x1E, 0x33, 0x07, 0x0E, 0x38, 0x33, 0x1E, 0x00}, // U+0053 (S)
    {0x3F, 0x2D, 0x0C, 0x0C, 0x0C, 0x0C, 0x1E, 0x00}, // U+0054 (T)
    {0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x3F, 0x00}, // U+0055 (U)
    {0x33, 0x33, 0x33, 0x33, 0x33, 0x1E, 0x0C, 0x00}, // U+0056 (V)
    {0x63, 0x63, 0x63, 0x6B, 0x7F, 0x77, 0x63, 0x00}, // U+0057 (W)
    {0x63, 0x63, 0x36, 0x1C, 0x1C, 0x36, 0x63, 0x00}, // U+0058 (X)
    {0x33, 0x33, 0x33, 0x1E, 0x0C, 0x0C, 0x1E, 0x00}, // U+0059 (Y)
    {0x7F, 0x63, 0x31, 0x18, 0x4C, 0x66, 0x7F, 0x00}, // U+005A (Z)
    {0x1E, 0x06, 0x06, 0x06, 0x06, 0x06, 0x1E, 0x00}, // U+005B ([)
    {0x03, 0x06, 0x0C, 0x18, 0x30, 0x60, 0x40, 0x00}, // U+005C (\)
    {0x1E, 0x18, 0x18, 0x18, 0x18, 0x18, 0x1E, 0x00}, // U+005D (])
    {0x08, 0x1C, 0x36, 0x63, 0x00, 0x00, 0x00, 0x00}, // U+005E (^)
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF}, // U+005F (_)
    {0x0C, 0x0C, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0060 (`)
    {0x00, 0x00, 0x1E, 0x30, 0x3E, 0x33, 0x6E, 0x00}, // U+0061 (a)
    {0x07, 0x06, 0x06, 0x3E, 0x66, 0x66, 0x3B, 0x00}, // U+0062 (b)
    {0x00, 0x00, 0x1E, 0x33, 0x03, 0x33, 0x1E, 0x00}, // U+0063 (c)
    {0x38, 0x30, 0x30, 0x3e, 0x33, 0x33, 0x6E, 0x00}, // U+0064 (d)
    {0x00, 0x00, 0x1E, 0x33, 0x3f, 0x03, 0x1E, 0x00}, // U+0065 (e)
    {0x1C, 0x36, 0x06, 0x0f, 0x06, 0x06, 0x0F, 0x00}, // U+0066 (f)
    {0x00, 0x00, 0x6E, 0x33, 0x33, 0x3E, 0x30, 0x1F}, // U+0067 (g)
    {0x07, 0x06, 0x36, 0x6E, 0x66, 0x66, 0x67, 0x00}, // U+0068 (h)
    {0x0C, 0x00, 0x0E, 0x0C, 0x0C, 0x0C, 0x1E, 0x00}, // U+0069 (i)
    {0x30, 0x00, 0x30, 0x30, 0x30, 0x33, 0x33, 0x1E}, // U+006A (j)
    {0x07, 0x06, 0x66, 0x36, 0x1E, 0x36, 0x67, 0x00}, // U+006B (k)
    {0x0E, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x1E, 0x00}, // U+006C (l)
    {0x00, 0x00, 0x33, 0x7F, 0x7F, 0x6B, 0x63, 0x00}, // U+006D (m)
    {0x00, 0x00, 0x1F, 0x33, 0x33, 0x33, 0x33, 0x00}, // U+006E (n)
    {0x00, 0x00, 0x1E, 0x33, 0x33, 0x33, 0x1E, 0x00}, // U+006F (o)
    {0x00, 0x00, 0x3B, 0x66, 0x66, 0x3E, 0x06, 0x0F}, // U+0070 (p)
    {0x00, 0x00, 0x6E, 0x33, 0x33, 0x3E, 0x30, 0x78}, // U+0071 (q)
    {0x00, 0x00, 0x3B, 0x6E, 0x66, 0x06, 0x0F, 0x00}, // U+0072 (r)
    {0x00, 0x00, 0x3E, 0x03, 0x1E, 0x30, 0x1F, 0x00}, // U+0073 (s)
    {0x08, 0x0C, 0x3E, 0x0C, 0x0C, 0x2C, 0x18, 0x00}, // U+0074 (t)
    {0x00, 0x00, 0x33, 0x33, 0x33, 0x33, 0x6E, 0x00}, // U+0075 (u)
    {0x00, 0x00, 0x33, 0x33, 0x33, 0x1E, 0x0C, 0x00}, // U+0076 (v)
    {0x00, 0x00, 0x63, 0x6B, 0x7F, 0x7F, 0x36, 0x00}, // U+0077 (w)
    {0x00, 0x00, 0x63, 0x36, 0x1C, 0x36, 0x63, 0x00}, // U+0078 (x)
    {0x00, 0x00, 0x33, 0x33, 0x33, 0x3E, 0x30, 0x1F}, // U+0079 (y)
    {0x00, 0x00, 0x3F, 0x19, 0x0C, 0x26, 0x3F, 0x00}, // U+007A (z)
    {0x38, 0x0C, 0x0C, 0x07, 0x0C, 0x0C, 0x38, 0x00}, // U+007B ({)
    {0x18, 0x18, 0x18, 0x00, 0x18, 0x18, 0x18, 0x00}, // U+007C (|)
    {0x07, 0x0C, 0x0C, 0x38, 0x0C, 0x0C, 0x07, 0x00}, // U+007D (})
    {0x6E, 0x3B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+007E (~)
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}  // U+007F
};

#define CHAR_WIDTH 8
#define CHAR_HEIGHT 8

typedef struct planet
{
  f32 pos_x;
  f32 pos_y;

  f32 vel_x;
  f32 vel_y;

  f32 acc_x;
  f32 acc_y;

  f32 radius;
  f32 mass;
  f32 gravity;
} planet;

u32 num_planets = 0;
planet *planets = 0;

void new_planet(f32 xp, f32 yp, f32 gravity, f32 radius, f32 init_vel_x, f32 init_vel_y)
{
  num_planets++;
  if (num_planets == 1)
  {
    planets = malloc(sizeof(planet));
  }
  else
  {
    planets = realloc(planets, sizeof(planet) * num_planets);
  }

  planets[num_planets - 1].pos_x = xp;
  planets[num_planets - 1].pos_y = yp;
  planets[num_planets - 1].gravity = gravity;
  planets[num_planets - 1].mass = gravity * radius * radius / G_CONST;
  planets[num_planets - 1].radius = radius;
  planets[num_planets - 1].vel_x = init_vel_x;
  planets[num_planets - 1].vel_y = init_vel_y;
}

bool get_key_release(KEYS key)
{
  static bool down[KEY_ACTION_COUNT] = {false};
  bool key_released = false;

  if (!key_is_down[key])
  {
    if (down[key])
    {
      down[key] = false;
      key_released = true;
    }
  }
  else
  {
    down[key] = true;
  }

  return key_released;
}

void render_character(unsigned char character, u32 x, u32 y, u32 color)
{
  unsigned char *letter = font8x8_basic[character];
  for (u32 xx = 0; xx < CHAR_WIDTH; ++xx)
  {
    for (u32 yy = 0; yy < CHAR_HEIGHT; ++yy)
    {
      if (letter[xx] & 1 << yy)
      {
        set_pixel(x + yy, y + xx, color);
      }
    }
  }
}

void draw_text(char *text, u32 x, u32 y, u32 color)
{
  if (strlen(text) == 0)
    return;
  for (u32 i = 0; i < strlen(text); ++i)
  {
    render_character(text[i], x + (CHAR_WIDTH * i), y, color);
  }
}

void int_slider(i32 *i, i32 min, i32 max, u32 x, u32 y, f32 *slider)
{
  i32 left = x - 50;
  i32 right = x + 50;

  if (button_circle(8, *slider + left, y) && *slider >= 0.0f && *slider <= 100.0f && key_is_down[SGL_LMB])
    *slider = mouse_pos.x - left + (min / (max - min));

  if (*slider > 100.0f)
    *slider = 100.0f;

  if (*slider < 0.0f)
    *slider = 0.0f;

  draw_rectangle(false, left, y + 10, right, y - 10, BLUE, WHITE);
  draw_circle(true, 8, *slider + left, y, GRAY, BLUE);

  *i = (*slider / 100) * (max - min) + min;
}

f32 planet_scale = 0;

#define EDIT_MODE 1 << 1
#define SPECTATE_MODE 1 << 2

u32 current_mode = SPECTATE_MODE;

f32 distance = 0;
vec2 initial_pos = {};
bool creating_planet = false;

bool init_creation_win = false;

bool init_creation_window(u32 x1, u32 y1, u32 x2, u32 y2,
                          i32 *radius, i32 *gravity, i32 *init_velocity_x, i32 *init_velocity_y)
{
  char radius_text[] = "Enter Radius : ";
  char gravity_text[] = "Enter Gravity : ";
  char x_vel_text[] = "Enter X Velocity : ";
  char y_vel_text[] = "Enter Y Velocity : ";
  char create_text[] = "Create";

  char radius_dsp[10];
  char gravity_dsp[10];
  char x_vel_dsp[10];
  char y_vel_dsp[10];

  itoa((i32)*radius, radius_dsp, 10);
  itoa((i32)*gravity, gravity_dsp, 10);
  itoa((i32)*init_velocity_x, x_vel_dsp, 10);
  itoa((i32)*init_velocity_y, y_vel_dsp, 10);

  static f32 radius_slider = 0;
  static f32 gravity_slider = 0;
  static f32 x_vel_slider = 0;
  static f32 y_vel_slider = 0;

  draw_rectangle(true, x1, y1, x2, y2, GRAY, GRAY);

  draw_text(radius_text, x1 + (x2 - x1) / 2 - CHAR_WIDTH * strlen(gravity_text) / 2, y2 + 10, BLACK);
  draw_text(radius_dsp, x1 + (x2 - x1) / 2 - CHAR_WIDTH * strlen(gravity_dsp) / 2, y2 + 30, BLACK);
  int_slider(radius, 1, 100, x1 + (x2 - x1) / 2, y2 + 50, &radius_slider);

  draw_text(gravity_text, x1 + (x2 - x1) / 2 - CHAR_WIDTH * strlen(gravity_text) / 2, y2 + 65, BLACK);
  draw_text(gravity_dsp, x1 + (x2 - x1) / 2 - CHAR_WIDTH * strlen(gravity_dsp) / 2, y2 + 80, BLACK);
  int_slider(gravity, 1, 100, x1 + (x2 - x1) / 2, y2 + 100, &gravity_slider);

  draw_text(x_vel_text, x1 + (x2 - x1) / 2 - CHAR_WIDTH * strlen(x_vel_text) / 2, y2 + 120, BLACK);
  draw_text(x_vel_dsp, x1 + (x2 - x1) / 2 - CHAR_WIDTH * strlen(x_vel_dsp) / 2, y2 + 130, BLACK);
  int_slider(init_velocity_x, -100, 100, x1 + (x2 - x1) / 2, y2 + 150, &x_vel_slider);

  draw_text(y_vel_text, x1 + (x2 - x1) / 2 - CHAR_WIDTH * strlen(y_vel_text) / 2, y2 + 175, BLACK);
  draw_text(y_vel_dsp, x1 + (x2 - x1) / 2 - CHAR_WIDTH * strlen(y_vel_dsp) / 2, y2 + 190, BLACK);
  int_slider(init_velocity_y, -100, 100, x1 + (x2 - x1) / 2, y2 + 210, &y_vel_slider);

  draw_text(create_text, x1 + (x2 - x1) / 2 - CHAR_WIDTH * strlen(create_text) / 2, y1 - (25 + CHAR_HEIGHT), BLACK);

  draw_rectangle(false, x1 + 30, y1 - 20, x2 - 30, y1 - 40, WHITE, WHITE);

  return button_rect(x1 + 30, y1 - 20, x2 - 30, y1 - 40) && key_is_down[SGL_LMB];
}

void spawn_new_planet()
{
  static bool create_planet = false;

  static i32 radius = 0;
  static i32 gravity = 0;
  static i32 initial_velocity_x = 0;
  static i32 initial_velocity_y = 0;

  if (get_key_release(SGL_LMB) && !init_creation_win)
  {
    initial_pos = mouse_pos;
    creating_planet = !creating_planet;
    init_creation_win = false;
  }

  if (creating_planet)
  {
    f32 d_x = initial_pos.x - mouse_pos.x;
    f32 d_y = initial_pos.y - mouse_pos.y;
    distance = sqrt(d_x * d_x + d_y * d_y);

    draw_circle(false, distance, initial_pos.x, initial_pos.y, RED, WHITE);
  }

  if (key_is_down[SGL_RMB] && creating_planet)
  {
    init_creation_win = true;
    creating_planet = false;
    radius = distance;
  }

  if (init_creation_win)
  {

    create_planet = init_creation_window(300 - 90, 300 + 230, 300 + 90, 300 - 100,
                                         &radius, &gravity, &initial_velocity_x, &initial_velocity_y);
  }

  if (create_planet || get_key_release(SGL_ENTER))
  {
    new_planet(initial_pos.x, initial_pos.y, gravity, radius, initial_velocity_x, initial_velocity_y);
    create_planet = false;
    init_creation_win = false;
    creating_planet = false;
  }

  if (get_key_release(SGL_ESC))
  {
    init_creation_win = false;
    creating_planet = false;
    create_planet = false;
  }
}

i32 main()
{
  initialize_SGL(600, 600, "SGL");
  bool is_running = true;

  while (is_running)
  {
    receive_msg(&is_running);

    for (u32 i = 0; i < num_planets; ++i)
    {
      if (!init_creation_win)
      {
        f32 a_x = 0;
        f32 a_y = 0;
        for (u32 j = 0; j < num_planets; ++j)
        {
          if (i != j)
          {
            f32 dx = planets[j].pos_x - planets[i].pos_x;
            f32 dy = planets[j].pos_y - planets[i].pos_y;
            f32 distance = dx * dx + dy * dy;
            f32 dir_x = dx / sqrt(distance);
            f32 dir_y = dy / sqrt(distance);

            f32 f_x = dir_x * (f32)G_CONST * planets[j].mass / distance;
            f32 f_y = dir_y * (f32)G_CONST * planets[j].mass / distance;
            a_x += f_x;
            a_y += f_y;
          }
        }

        planets[i].acc_x = a_x;
        planets[i].acc_y = a_y;
        planets[i].vel_x += planets[i].acc_x * 0.01f;
        planets[i].vel_y += planets[i].acc_y * 0.01f;

        planets[i].pos_x += planets[i].vel_x * 0.01f;
        planets[i].pos_y += planets[i].vel_y * 0.01f;
      }

      draw_circle(true, planets[i].radius, planets[i].pos_x, planets[i].pos_y, RED, RED);
    }

    draw_text("Very Very Simple Solar Simulator", 300 - CHAR_WIDTH * 16, 20, BLACK);
    draw_text("LMB and then RMB to make new planet then press ENTER or click Create", 300 - CHAR_WIDTH * 68 / 2, 30, RED);
    draw_text("ESC to exit out of planet creation", 300 - CHAR_WIDTH * 34 / 2, 40, BLUE);
    spawn_new_planet();
    
    present(WHITE);
  }
  free(planets);

  return 0;
}
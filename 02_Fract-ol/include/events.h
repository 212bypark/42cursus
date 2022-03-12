#ifndef EVENTS_H
# define EVENTS_H

/*  KEY code */
# define MOUSE_UP 4
# define MOUSE_DOWN 5

# define KEY_ESC 53

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13

# define ARR_UP 126
# define ARR_DOWN 125
# define ARR_LEFT 123
# define ARR_RIGHT 124

# define NUM_1 18
# define NUM_2 19
# define NUM_3 20

# define KEY_R 15
# define KEY_Q 12
# define KEY_E 14
# define KEY_C 8

/*  EVENT */
# define KEY_PRESS 2
# define BUTTON_PRESS 4
# define DESTROY 17

/*  MASK */
# define MASK_KEY_PRESS 1L
# define MASK_BUTTON_PRESS  4L
# define MASK_DESTROY   131072L

/*  Scale */
# define SHIFT_SCALE 0.05
# define ZOOM_IN 1.20
# define ZOOM_OUT 0.80

/*  Funciton */
int	ft_quit(t_data *data);
int	ft_key_hook(int keycode, t_data *data);
int	ft_mouse_hook(int keycode, int x, int y, t_data *data);

#endif

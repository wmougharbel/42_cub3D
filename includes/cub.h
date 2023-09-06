/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurawsk <amurawsk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:18:39 by wmoughar          #+#    #+#             */
/*   Updated: 2023/09/06 19:00:14 by amurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define BOLD_PINK "\033[1;38;2;255;0;204m"
# define DEFAULT "\033[0m"
# define WIDTH 1920.0
# define HEIGHT 1080.0
# define MAX_DISTANCE 100.0
# define EAST 1
# define WEST 2
# define SOUTH 3
# define NORTH 4

# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define ARROW_RIGHT 124
# define ARROW_LEFT 123

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <math.h>

typedef struct s_texture
{
	void	*img; 
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	char	*path;
}				t_texture;

typedef struct s_mlx_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx_img;

typedef struct s_mlx_instance
{
	void	*ptr;
	void	*win;
}	t_mlx_instance;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_ivector
{
	int	x;
	int	y;
}	t_ivector;

typedef struct s_map
{
	char			*filename;
	char			**map;
	int				floor[3];
	int				ceiling[3];
	int				floor_color;
	int				ceiling_color;
	t_texture		north_text;
	t_texture		south_text;
	t_texture		west_text;
	t_texture		east_text;
	unsigned int	text_clr;
	t_vector		text;
	t_vector		p_pos;
	t_vector		ray_pos;
	t_vector		ray_dir;
	t_vector		ray_length;
	t_vector		step_size;
	t_ivector		sides;
	t_vector		new_pos;
	int				side;
	t_ivector		step;
	t_ivector		map_check;
	double			view_dir;
	t_mlx_img		mlx_img;
	t_mlx_instance	mlx;
	float			distance;
	int				pixel_number;
	double			fov;
}	t_map;

enum	e_token_type
{
	__map,
	__north_text,
	__south_text,
	__east_text,
	__west_text,
	__ceiling_color,
	__floor_color,
	__empty_space
};

//check_map
	//ft_check_input
bool			ft_check_arguments(int argc);
bool			ft_extension_is_cub(char *argv);
bool			ft_check_input(int argc, char *argv);

	//ft_check_map
bool			ft_check_map_characters(t_map *map);
bool			ft_check_map(t_map *map);
bool			ft_compare_lines(t_map *map);

	//ft_check_borders
bool			ft_check_top_bottom_borders(t_map *map);
bool			ft_check_left_right_borders(t_map *map);
bool			ft_check_first_line(t_map *map, int i);
bool			ft_check_last_line(t_map *map, int i, int bottom_border);

	//ft_check_map_utils
bool			ft_space(char c);
void			ft_store_map_in_array(t_map *map);
char			*ft_find_map_in_file(char *line, int fd);

	//ft_check_player
int				ft_count_player(t_map *map);
void			find_p_position(t_map *map);
void			set_view_dir(t_map *map, char c);

//read_file
	//ft_get_file_content
void			ft_init_content(t_map *map);
bool			ft_get_token_type(t_map *map);
int				ft_get_line_type(char *line);
void			ft_store_in_corresponding_array(t_map *map, char *texture,
					int type);
void			ft_store_colors_in_arrays(t_map *map, int type, char *color);

	//colors
int				ft_rgb_to_hexadecimal(int red, int green, int blue);
void			ft_convert_color_to_hex(t_map *map);

	//ft_check_textures
int				ft_count_commas(char *color);
bool			ft_texture_exist(t_map *map);
bool			ft_correct_texture_path(t_map *map);
bool			ft_correct_texture_path_end(char *texture);
bool			ft_check_texture(t_map *map);

//free
void			ft_free_split_string(char **string);
void			ft_free_map_struct(t_map *map);
void			ft_free_map_textures(t_map *map);
void			ft_exit(char *message, t_map *map);
void			ft_destroy_mlx(t_map *map);

//initialize_game
void			ft_initialize_window(t_map *map);
void			ft_initialize_north_south_texts(t_map *map);
void			ft_initialize_east_west_texts(t_map *map);
void			ft_initialize_mlx_hook(t_map *map);
void			ft_initialize_game(t_map *map);

//ray_cast
	//raycast
void			ft_raycast(t_map *map);
int				sample_texture(t_texture texture);
	//raycast_utils
void			raycast_reset(t_map *map);
void			color_pixel_put(t_map *map, int x, int y, int color);
unsigned int	get_color(t_texture *text, double text_x, double text_y);
int				firing_ray(t_map *map);

//game
	//controls
int				ft_key_controls(int key, t_map *map);
void			arrow_movements(int key, t_map *map, double move_step);

#endif
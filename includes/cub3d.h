/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:25:41 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/04 10:09:47 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <libtype.h>
# include <vla.h>

# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_W 119
# define KEY_ESC 65307
# define KEY_LEFT 65363
# define KEY_RIGHT 65361

typedef struct		s_point {
	int				x;
	int				y;
}					t_point;

typedef struct		s_point2 {
	double			x;
	double			y;
}					t_point2;

typedef struct		s_player {
	t_point2		pos;
	double			dir;
	double			heading_v;
	double			side_v;
	double			ang_v;
	int				end;
}					t_player;

typedef struct		s_color {
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_textures {
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*sp;
	t_color			floor;
	t_color			ceil;
}					t_textures;

typedef struct		s_config {
	t_point			window_size;
	t_textures		textures;
	t_array			map;
	t_point			*player_location;
}					t_config;

typedef struct		s_image {
	t_point			size;
	void			*img;
	void			*addr;
	int				bpp;
	int				line_len;
	int				endian;
}					t_image;

typedef struct		s_mlx {
	t_image			win;
	t_image			no_tx;
	t_image			so_tx;
	t_image			we_tx;
	t_image			ea_tx;
	t_image			sp_tx;
	void			*mlx_ptr;
	void			*win_ptr;
	t_player		player;
}					t_mlx;

typedef enum		e_map_obj {
	wall,
	sprite,
	blank
}					t_map_obj;

typedef struct		s_sp_inf {
	double			side_rate;
	double			dist;
}					t_sp_inf;

typedef struct		s_ray_obj {
	double		rad;
	double		camera_dist;
	double		heading_rad;
	t_point2	pos;
	t_point2	pl_pos;
	t_array		sp_stk;
}					t_ray_obj;

typedef enum		e_error {
	arg_err,
	file_name,
	read_file,
	file_format,
	map_err,
	malloc_err,
	mlx_err,
	img_err,
	write_file
}					t_error;

typedef struct		s_arg {
	int			save;
	t_mlx		mlx;
	t_config	conf;
}					t_arg;

void				cub3d_error(t_error err_code);
void				read_conf(char *file, t_config *conf);
void				set_texture(char *line, char **path);
void				init_conf(t_config *conf);
t_status			atoi_check(char *str);
t_status			atoi_check2(char *str, int *n);
void				check_conf(t_config *conf);
char				*skip_space(char *s);
char				*replace_white_space(char *s);
size_t				count_delimiter(char *s, char del);
void				set_map(t_array file_contents, t_config *conf);
t_array				*map_zeros_like(t_array src);
t_point				*gen_point(int x, int y);
int					is_throughable(t_config conf, int x, int y);
int					is_wall(t_config conf, int x, int y);
int					is_sprite(t_config conf, int x, int y);
void				check_map(t_config *conf);
void				check_surrounded(t_config conf);
int					is_stk_appendable(t_config conf, int x, int y);
void				put_pixel(t_image *data, int x, int y, int color);
void				set_mlx(t_arg *ag);
int					gen_trgb(int t, int r, int g, int b);
int					gen_trgb2(int t, t_color color);
int					get_t(int trgb);
int					get_r(int trgb);
int					get_g(int trgb);
int					get_b(int trgb);
int					get_safe_index(double rate, int image_max);
void				draw_fc(t_arg *ag);
void				draw_wall(t_ray_obj obj_inf, t_mlx *data, int sw);
void				draw_sprite(t_ray_obj *obj_inf, t_mlx *data, int sw);
void				set_px_color(t_image *data, int x, int y, int color);
double				get_euclid_dist(double x1, double y1, double x2, double y2);
double				get_euclid_dist2(t_point2 p1, t_point2 p2);
double				get_camera_dist(t_point2 obj, t_point2 eye,
					double heading_rad);
double				get_min_rad(double large_rad);
void				extend_ray(double curr_rad, t_point2 *ray,
					t_point2 *prev_ray);
void				raycast(t_arg *ag);
t_status			load_images(t_config conf, t_mlx *data);
int					get_img_trgb(t_image img, int x, int y);
double				rad_to_side_rate(double rad);
t_sp_inf			*gen_sp_inf(double delta_rad, double euclid_dist);
int					render(void *ag);
void				move_player(t_arg *ag);
int					get_tx_height(t_ray_obj obj_inf, t_mlx data);
int					get_tx_width(t_ray_obj obj_inf, t_mlx data);
int					key_press_act(int key, t_arg *ag);
int					key_release_act(int key, t_arg *ag);
int					cub3d_end(t_arg *ag);
void				conf_clear(t_arg *ag);
t_status			write_bmp(t_arg *ag);
void				clear_conf(t_arg *ag);

#endif

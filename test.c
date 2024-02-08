#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>   // exit関数のために必要
#include <sys/time.h> // gettimeofday関数のために必要

__attribute__((destructor)) static void destructor()
{
	system("leaks -q a.out");
}

typedef struct s_env
{
	void		*mlx_ptr;
	void		*win_ptr;
	long long	start_time;
}				t_env;

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000); // ミリ秒単位で時間を返す
}

int	close_after_delay(void *param)
{
	t_env		*env;
	long long	current_time;

	env = (t_env *)param;
	current_time = get_time();
	if (current_time - env->start_time > 5000) // 5000ミリ秒 = 5秒
	{
		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
		exit(0); // プログラムを正常に終了
	}
	return (0);
}

int	main(void)
{
	t_env	env;
	void	*img_ptr;

	int img_width, img_height;
	env.mlx_ptr = mlx_init();
	if (!env.mlx_ptr)
	{
		fprintf(stderr, "Error: MiniLibX initialization failed.\n");
		return (1);
	}
	env.win_ptr = mlx_new_window(env.mlx_ptr, 800, 600, "XPM Test Window");
	if (!env.win_ptr)
	{
		fprintf(stderr, "Error: Window creation failed.\n");
		return (1);
	}
	img_ptr = mlx_xpm_file_to_image(env.mlx_ptr, // ここを修正
									"includes/img/Pac-Man/black.xpm",
									&img_width,
									&img_height);
	if (!img_ptr)
	{
		fprintf(stderr, "Error: Failed to load XPM image.\n");
		return (1);
	}
	mlx_put_image_to_window(env.mlx_ptr, env.win_ptr, img_ptr, 0, 0);
		// 画像をウィンドウに配置
	env.start_time = get_time();
	// 定期的な処理を設定
	mlx_loop_hook(env.mlx_ptr, close_after_delay, &env);
	mlx_loop(env.mlx_ptr);
	return (0);
}

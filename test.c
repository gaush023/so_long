#include <mlx.h>
#include <stdio.h>

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;

	int img_width, img_height;
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
	{
		fprintf(stderr, "Error: MiniLibX initialization failed.\n");
		return (1);
	}
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "XPM Test Window");
	if (!win_ptr)
	{
		fprintf(stderr, "Error: Window creation failed.\n");
		return (1);
	}
	// "example.xpm" はあなたのXPMファイル名に置き換えてください。
	img_ptr = mlx_xpm_file_to_image(mlx_ptr,
									"/Users/shuga/Desktop/42/so_long/includes/img/Other/Portal/portal.xpm",
										& img_width,
									&img_height);
	if (!img_ptr)
	{
		fprintf(stderr, "Error: Failed to load XPM image.\n");
		return (1);
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}

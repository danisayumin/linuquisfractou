// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include "ft_fractol.h"

// -----------------------------------------------------------------------------
// static mlx_image_t* image;

uint32_t ft_pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_pixels(mlx_image_t *image, char *argv[]) {    
    uint32_t x = 0;
    while (x < IMAGE) {
        uint32_t y = 0;
        while (y < IMAGE) {
            double new_x = map(x, 0, IMAGE, -2.5, 1.5);
            double new_y = map(y, 0, IMAGE, -1.5, 2.5);

            t_complex c ;
            c = (t_complex){new_x, new_y};

            int i = map(ft_calculate_mandelbrot(c, (double) *argv[1], (double) *argv[2]), 0, MAX_ITER, 0, 255);
            mlx_put_pixel(image, x, y, ft_pixel(i, i, i, 255));

            y++;
        }
        x++;
    }
}



// void ft_hook(void* param) //manipula eventos do teclado
// {
// 	mlx_t* mlx = param;

// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// 		image->instances[0].y -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
// 		image->instances[0].y += 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// 		image->instances[0].x -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// 		image->instances[0].x += 5;
// }

/* -----------------------------------------------------------------------------
https://github.com/danisayumin/Fractol.git
*/

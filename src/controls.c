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

void ft_pixels(mlx_image_t *image) {
    uint32_t fixedColor = 0xFF0000FF;

    uint32_t x = 5;
    while (x < 10) {

        uint32_t y = 5;
        while (y < 10) {
            mlx_put_pixel(image, x, y, fixedColor);
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

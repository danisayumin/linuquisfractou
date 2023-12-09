// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include "ft_fractol.h"

uint32_t ft_pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

t_color color_palette[] = {
    {0, 0, 0},         // Cor mais escura
    {0, 0, 128},       // Azul escuro
    {0, 0, 255},       // Azul médio
    {135, 206, 250},   // Azul claro
    {173, 216, 230},   
    {240, 248, 255},    
    {100, 149, 237},    
    {0, 191, 255},      
    {70, 130, 180},     
    {30, 144, 255},     
    {0, 0, 205},        
    {0, 0, 139},        
    {0, 0, 128},        
    {0, 0, 139},        
    {0, 0, 128},        
    {0, 0, 139},        
    {0, 0, 128},        
    {0, 0, 139},        
    {0, 0, 128},        
    {0, 0, 139},        
    {0, 0, 128},        
    {0, 0, 139},       
    {0, 0, 128},
    {255, 255, 255}    
};

#define NUM_COLORS (sizeof(color_palette) / sizeof(color_palette[0]))

t_color interpolate_colors(t_color color1, t_color color2, double factor)
{
    t_color result;

    if (factor < 0.0)
        factor = 0.0;
    if (factor > 1.0)
        factor = 1.0;

    result.r = (1.0 - factor) * color1.r + factor * color2.r;
    result.g = (1.0 - factor) * color1.g + factor * color2.g;
    result.b = (1.0 - factor) * color1.b + factor * color2.b;

    return result;
}

t_color get_interpolated_color(int i)
{
    int num_colors = NUM_COLORS - 1;
    int index1 = i / num_colors;
    int index2 = (index1 + 1) % NUM_COLORS;
    double factor = (i % num_colors) / (double)num_colors;

    t_color color1 = color_palette[index1];
    t_color color2 = color_palette[index2];

    return interpolate_colors(color1, color2, factor);
}

void ft_pixels(t_image_info *info)
{
    uint32_t x = 0;
    while (x < IMAGE)
    {
        uint32_t y = 0;
        while (y < IMAGE)
        {
            double new_x = map(x, 0, IMAGE, -2.5 / info->scale_x + info->offset_x, 1.5 / info->scale_x + info->offset_x);
            double new_y = map(y, 0, IMAGE, -1.5 / info->scale_y + info->offset_y, 2.5 / info->scale_y + info->offset_y);
            t_complex c;
            c = (t_complex){new_x, new_y};

            int i = if_mandelbrot(c);
            t_color interpolated_color = get_interpolated_color(i);

            mlx_put_pixel(info->image, x, y, ft_pixel(interpolated_color.r, interpolated_color.g, interpolated_color.b, 255));

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

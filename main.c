/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:30:59 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/27 21:31:10 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolfenstein.h"

void print_pars_info(const t_pars *data)
{

	printf(BOLD BLUE "\n=========== Game Parsing Info ===========" RESET "\n");

	// Map size
	printf(BOLD CYAN "Map Dimensions: " RESET GREEN "%d x %d\n" RESET, data->map_w, data->map_h);

	// Start position and direction
	printf(BOLD CYAN "Start Position: " RESET "x: " GREEN "%d " RESET "y: " GREEN "%d\n" RESET, data->start_x, data->start_y);
	printf(BOLD CYAN "Start Direction: " RESET GREEN "%c\n" RESET, data->start_dir);

	// Map error details
	printf(BOLD CYAN "Map Errors: " RESET "\n");
	printf("- Empty Line: %s\n", data->empty_line ? RED "Yes" RESET : GREEN "No" RESET);
	printf("- Wrong Characters: %s\n", data->wrongchar ? RED "Yes" RESET : GREEN "No" RESET);
	printf("- Parsing Inside Map: %s\n", data->in_map ? GREEN "Yes" RESET : RED "No" RESET);

	// Texture files
	printf(BOLD CYAN "Texture Files:\n" RESET);
	printf("- North (NO): " GREEN "%s\n" RESET, data->no ? data->no : RED "Not Set" RESET);
	printf("- South (SO): " GREEN "%s\n" RESET, data->so ? data->so : RED "Not Set" RESET);
	printf("- West (WE): " GREEN "%s\n" RESET, data->we ? data->we : RED "Not Set" RESET);
	printf("- East (EA): " GREEN "%s\n" RESET, data->ea ? data->ea : RED "Not Set" RESET);

	// Colors
	printf(BOLD CYAN "Colors:\n" RESET);
	printf("- Floor (F): " GREEN "%d\n" RESET, data->f);
	printf("- Ceiling (C): " GREEN "%d\n" RESET, data->c);

	// Error status
	printf(BOLD CYAN "General Error Status: " RESET "%s\n", data->error ? RED "Error Detected" RESET : GREEN "No Errors" RESET);

	printf(BOLD BLUE "=========================================\n" RESET);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	t_pars	*data;

	data = malloc(sizeof(t_pars));
	if (argc != 2)
		return (write(1, "Wrong number of arguments\n", 26), 0);
	init_pars(&data);
	parse_all(data, argv[1]);
	print_pars_info(data);
	if (!init_project(&game, data))
		return (1);
	printf("Initialization successful, entering mlx_loop\n");
	mlx_loop_hook(game->win.mlx_ptr, update, game);
	mlx_loop(game->win.mlx_ptr);
	return 0;
}

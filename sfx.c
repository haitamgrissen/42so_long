/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:37:28 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/06 15:44:59 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    stop_damage_sfx()
{
   //kill(g_dmg_sfx_pid);
}

void    play_damage_sfx(int i)
{
	char *afplay[3];
	int pid;

	afplay[0] = "/usr/bin/afplay";
	afplay[1] = "./Sound_Effects/damage_sfx.mp3";
	afplay[2] = 0;

	//stop_damage_sfx();

	if (i == 0)
		afplay[1] = "./Sound_Effects/minecraft_damage_sfx.mp3";
	else
		afplay[1] = "./Sound_Effects/roblox_damage_sfx.mp3";

	if ((pid = fork()) == 0)
	{
		execve(afplay[0], afplay, 0);
	}
	else
		;
}
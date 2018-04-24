/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:55:41 by jjourne           #+#    #+#             */
/*   Updated: 2018/04/24 15:33:46 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//near
	//sur toutes les cases autour des cases enemies
	// y -1, y + 1, x - 1, x + 1;


	// void	reset_move(t_fil *dna)     RESET LA SAVE DU MEILLEUR MOVE
	// {
	// 	dna->move.score = 0;
	// 	dna->move.x = 0;
	// 	dna->move.y = 0;
	// }


//check move
	//reset_move


//check_block
	//if en dehors des limites retourne 0
	//Si c est une case ennemi retourne 0
	//si le block est au dessus d un block amis weld++;
	//Si player char dna->move.weld


//test each block
	//return 0 si on ne peut pas poser une piece
	//donc double boucle pour tester chaque block
	//si c est un '*' tester si le block est posable sinon passer au suivant
	//check_block sur les cases '*' return 1 si je peux poser 0 si je peux pas
	// if (check_block == 1)
		//score += score de la case
	//si weld == 1 return 1 or score else return 0
	//save best move




//play
	//near == algo pour gagner
	//check move
		// commence double boucle in negative value like 0 - dna->map.w == -5;
	// test_each_block

// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   tictactoe.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/10/02 05:03:15 by dpearson          #+#    #+#             //
//   Updated: 2017/10/02 05:03:19 by dpearson         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "tictactoe.h"

int		main(void)
{
	int move;
	Board board;
	Players plrs;

	plrs.choose_Mark();
	board.initialize_Board();
	do
	{
		board.draw_Board();
		do
		{
			cout << "Choose your move " << plrs.get_Mover() << '\n';			
			cin >> move;
		} while (!(board.isValid(move)));
		plrs.move(board, move);
		if (plrs.no_moves())
		{
			cout << "Tie!!\n";
			return (0);
		}
	}
	while (!(board.is_Winner()));
	board.draw_Board();
	cout << "The loser is " <<plrs.get_Mover() << '\n';
	return (0);
}
/*
    This file is part of Cute Chess.

    Cute Chess is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Cute Chess is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Cute Chess.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef XBOARDENGINE_H
#define XBOARDENGINE_H

#include "chessengine.h"

/*!
 * \brief A chess engine which uses the Xboard chess engine communication protocol.
 *
 * Xboard's specifications: http://www.tim-mann.org/xboard/engine-intf.html
 */
class LIB_EXPORT XboardEngine : public ChessEngine
{
	Q_OBJECT

	public:
		/*!
		 * Creates a new XboardEngine object.
		 * \param ioDevice An open chess engine process or socket.
		 * \param chessboard A chessboard object for converting between the
		 * various move formats.
		 * \param parent The parent object.
		 */
		XboardEngine(QIODevice* ioDevice,
		             Chess::Board* chessboard,
		             QObject* parent = 0);

		~XboardEngine();

		void newGame(Chess::Side side, ChessPlayer* opponent);
		void go();
		void makeMove(const Chess::Move& move);
		Protocol protocol() const;
		void ping();

	protected:
		void parseLine(const QString& line);

	private:
		bool m_forceMode;
		bool m_drawOnNextMove;
		int m_lastPing;
		
		void sendTimeLeft();
};

#endif // XBOARDENGINE_H

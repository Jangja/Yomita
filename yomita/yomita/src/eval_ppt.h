﻿/*
読み太（yomita）, a USI shogi (Japanese chess) playing engine derived from
Stockfish 7 & YaneuraOu mid 2016 V3.57
Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
Copyright (C) 2008-2015 Marco Costalba, Joona Kiiski, Tord Romstad (Stockfish author)
Copyright (C) 2015-2016 Marco Costalba, Joona Kiiski, Gary Linscott, Tord Romstad (Stockfish author)
Copyright (C) 2015-2016 Motohiro Isozaki(YaneuraOu author)
Copyright (C) 2016 Ryuzo Tukamoto

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "evaluate.h"

#ifdef EVAL_PPT

#include "evalsum.h"

#define PP_BIN "PP.bin"

namespace Eval
{
	// ValuePp[0] = 手番を握っている側の点数。[1]は手番とは関係ない点数。
	typedef std::array<int32_t, 2> ValuePp;

	// memory mapped file用
	struct SharedEval
	{
		ValuePp ppt_[fe_end2][fe_end2];
	};

	struct EvalTable
	{
		ValuePp(*ppt_)[fe_end2][fe_end2];

		void set(SharedEval* se)
		{
			ppt_ = &se->ppt_;
		}
	};

	extern EvalTable et;

} // namespace Eval
#endif

/**
 * Copyright (c) 2014-2015 G�bor G�rzs�ny (www.gorzsony.com)
 *
 * This source is a private work and can be used only with the
 * written permission of the author. Do not redistribute it!
 * All rights reserved.
 */

#pragma once

#include <cstdint>
#include "gg/thread.hpp"

class Game;

namespace backend
{
	class Backend
	{
	public:
		enum State : uint16_t
		{
			MENU,
			SINGLE_PLAY,
			MULTIPLAY
		};

		Backend(Game*);
		~Backend();
		Game* getGame();
		void start(gg::IThread::Mode);
		void stop();
		State getState() const;
		void setState(State);
		gg::ThreadPtr getThread();

	private:
		Game* m_game;
		gg::ThreadPtr m_thread;
	};
};

if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
			case SDLK_w:
				if (!keyDown[0])
				{
					shipBody.velocity += vec2D(0.0f, -movingSpeed);
				}
				keyDown[0] = true;
				break;

			case SDLK_a:
				if (!keyDown[1])
				{
					shipBody.velocity += vec2D(-movingSpeed, 0.0f);
				}
				keyDown[1] = true;
				break;

			case SDLK_s:
				if (!keyDown[2])
				{
					shipBody.velocity += vec2D(0.0f, movingSpeed);
				}
				keyDown[2] = true;
				break;

			case SDLK_d:
				if (!keyDown[3])
				{
					shipBody.velocity += vec2D(movingSpeed, 0.0f);
				}
				keyDown[3] = true;
				break;
		}

	}
	else if (event.type == SDL_KEYUP)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_w:
			if (keyDown[0])
			{
				shipBody.velocity += vec2D(0.0f, movingSpeed);
			}
			keyDown[0] = false;
			break;

		case SDLK_a:
			if (keyDown[1])
			{
				shipBody.velocity += vec2D(movingSpeed, 0.0f);
			}
			keyDown[1] = false;
			break;

		case SDLK_s:
			if (keyDown[2])
			{
				shipBody.velocity += vec2D(0.0f, -movingSpeed);
			}
			keyDown[2] = false;
			break;

		case SDLK_d:
			if (keyDown[3])
			{
				shipBody.velocity += vec2D(-movingSpeed, 0.0f);
			}
			keyDown[3] = false;
			break;
		}
	}
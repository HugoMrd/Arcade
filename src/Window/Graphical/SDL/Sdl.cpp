/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** Sdl
*/

#include "Sdl.hpp"

std::unique_ptr<arcade::IDisplayModule> _open = nullptr;

arcade::Sdl::Sdl(std::string const &name) : _font()
{
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	create(name);
}

arcade::Sdl::~Sdl()
{
	close();
	TTF_Quit();
	SDL_Quit();
}

void arcade::Sdl::create(std::string const &name)
{
	_window = SDL_CreateWindow(name.c_str(),
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
}

bool arcade::Sdl::open(void)
{
	if (_renderer)
		return (true);
	return (false);
}

void arcade::Sdl::close(void)
{
	SDL_DestroyWindow(_window);
}

void arcade::Sdl::clear(void)
{
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 0);
	SDL_RenderClear(_renderer);
}

void arcade::Sdl::display(void)
{
	SDL_RenderPresent(_renderer);
}

bool arcade::Sdl::pollEvent(arcade::Event)
{
	SDL_Event useEvent = {};

	while (SDL_PollEvent(&useEvent)) {
		if (useEvent.type == SDL_KEYDOWN) {
			auto it = _keyboard.find(useEvent.key.keysym.sym);
			if (it != _keyboard.end())
				_keysEvent.push(it->second);
			else
                throw std::out_of_range("Key not found in keyboard map");
		}
	}
	return (!_keysEvent.empty());
}

void arcade::Sdl::draw(arcade::Sprite &sprite)
{
	int i = 0;
	int j = 0;
	std::vector<Color> color = sprite.getSpriteArray();
	Uint8 r = color.at(i * sprite.getW() + j).r;
	Uint8 g = color.at(i * sprite.getW() + j).g;
	Uint8 b = color.at(i * sprite.getW() + j).b;
	Uint8 a = color.at(i * sprite.getW() + j).a;

	for (i = 0; i < (int)sprite.getH(); i++) {
		for (j = 0; j < (int)sprite.getW(); j++) {
			SDL_SetRenderDrawColor(_renderer, r, g, b, a);
			SDL_RenderDrawPoint(_renderer, sprite.getX() + j, sprite.getY() + i);
		}
	}
}

void arcade::Sdl::drawBack(void)
{
    SDL_Texture* backgroundTexture = NULL;
    SDL_Surface* backgroundSurface = IMG_Load("Resources/background.png");

    backgroundTexture = SDL_CreateTextureFromSurface(_renderer, backgroundSurface);
    SDL_FreeSurface(backgroundSurface);
    SDL_Rect backgroundRect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
    SDL_RenderCopy(_renderer, backgroundTexture, NULL, &backgroundRect);
    SDL_DestroyTexture(backgroundTexture);
}

arcade::Event arcade::Sdl::useEvent()
{
	arcade::Event keys =_keysEvent.front();
	_keysEvent.pop();
	return (keys);
}

void arcade::Sdl::drawText(Text &text)
{
	auto texW = (int) text.getX();
	auto texH = (int) text.getY();
	int size = static_cast<int> (text.getSize().at(0));
	int x = static_cast<int> (text.getPosition().at(0));
	int y = static_cast<int> (text.getPosition().at(1));

	_font = TTF_OpenFont("Resources/UniversCondensed.ttf", size);
	SDL_Color color = {text.getColor().r, text.getColor().g, text.getColor().b, text.getColor().a};
	SDL_Surface *surface = TTF_RenderText_Solid(_font, text.getText().c_str(), color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, surface);
	SDL_QueryTexture(texture, NULL, NULL, &texH, &texW);
	SDL_Rect dstrect = {x, y, texH, texW};
	SDL_RenderCopy(_renderer, texture, NULL, &dstrect);
	TTF_CloseFont(_font);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

extern "C" arcade::IDisplayModule *openGraphical()
{
	_open = std::make_unique<arcade::Sdl>("Arcade - SDL graphics");
	return (_open.get());
}

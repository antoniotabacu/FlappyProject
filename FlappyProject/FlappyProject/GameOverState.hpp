#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include <fstream>

namespace Tabacu {

	class GameOverState : public State
	{
	public:
		GameOverState(GameDataRef data, int score);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

		int getScore();
		int getHighScore();
		void setScore(int score);
		void setHighScore(int highscore);

		void startScoring() {
			std::ifstream readFile;
			readFile.open(HIGHSCORE_FILEPATH);

			if (readFile.is_open()) {
				while (!readFile.eof()) {
					readFile >> _highScore;
				}
			}

			readFile.close();
		}

	private:
		GameDataRef _data;

		sf::Sprite _background;

		sf::Sprite _gameOverTitle;
		sf::Sprite _gameOverContainer;
		sf::Sprite _retryButton;

		sf::Text _scoreText;
		sf::Text _highScoreText;

		int _score;
		int _highScore;
		int _initHighScore = 0;

	};
}
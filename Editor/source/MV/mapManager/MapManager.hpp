#pragma once

#include <vector>

#include "MV/cell/Cell.hpp"
#include "MV/ticker/Ticker.hpp"
#include "MV/InputManager/InputManager.hpp"
#include "MV/mouse/Mouse.hpp"
#include "MV/math/Math.hpp"

namespace mv
{
	class MapManager final : public Ticker
	{
		/* ===Objects=== */
	public:
	protected:
	private:
		//Vector of cells which are the surface
		std::vector<Cell> map;

		//World size in units
		sf::Vector2i unitWorldSize{ 0,0 };

		//Dimensions of cell(in px)
		sf::Vector2f cellDimensions{ 0,0 };

		int initialState;

		static MapManager* instance;

		InputManager inputManager;

		/* ===Methods=== */
	public:
		static MapManager& getInstance();

		static void createInstance( sf::Vector2i uWorldSize, const sf::Vector2f& celldimensions );

		//Returns world size in units
		sf::Vector2i getUnitWorldSize();

		//Returns dimensions of cell (in px)
		sf::Vector2f getCellDimensions();

		//Returns pointer to cell's vector
		std::vector<Cell> *getCellStorage();

		//Construct whole world with default state
		bool constructWholeWorld( int defaultState = 0 );

		//Uptades cells (to next state)
		void updateCells();

		//Sets default state
		void setDefaultState( Cell& );

		//Sets default state in each cell
		void resetAllCells();

		//Checks that object with given position is in map
		bool isInMap( sf::Vector2i& unitPosition );

		//Checks that object with given position is in map
		bool isInMap( unsigned int i, unsigned int j );

		virtual void tick() override;

	protected:
	private:
		void createWorld( int defaultStateNumber );

		MapManager( sf::Vector2i uWorldSize, const sf::Vector2f& celldimensions );
		MapManager() = delete;  // Not Implemented
		MapManager( MapManager const& copy ) = delete;            // Not Implemented
		MapManager& operator=( MapManager const& copy ) = delete; // Not Implemented

		void rotateCell();
	};
}

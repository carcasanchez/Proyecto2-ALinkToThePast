#ifndef _HUD_H_
#define _HUD_H_

#include "j1Module.h"
#include "Player.h"
#include "UI_Heart.h"
#include "UI_Stamina.h"
#include "UI_Image.h"
#include "UI_String.h"
#include "UI_Counter.h"
#include "InputManager.h"

class UI_element;
class UI_Image;

enum PAUSEMOVE
{
	PAUSE_NO_MOVE,
	PAUSE_UP,
	PAUSE_DOWN
};

class Hud : public InputListener
{
public:
	Hud();

	bool		Awake(pugi::xml_node& conf);
	bool		Start();
	bool		Update(float);
	bool		CleanUp();

	void		OnInputCallback(INPUTEVENT, EVENTSTATE);
	UI_element*	LoadUIElement(pugi::xml_node, UI_element*, UI_TYPE);

public:
	//In game HUD elements
	UI_element*		hud_screen = nullptr;

	//Counters image
	UI_Image*		numbers = nullptr; //Image not in gui
	
	//Little items
	UI_Image*		Rupees = nullptr;
	UI_Counter*		rupees_counter = nullptr;

	UI_Image*		Bombs = nullptr;
	UI_Counter*		bombs_counter = nullptr;

	UI_Image*		Arrows = nullptr;
	UI_Counter*		arrows_counter = nullptr;

	//life hud
	UI_Image*			life = nullptr;	
	UI_Image*			empty_heart = nullptr; //Image not in gui
	UI_Image*			medium_heart = nullptr; //Image not in gui
	UI_Image*			full_heart = nullptr; //Image not in gui

	vector<UI_Heart*>	hearts;
	int					space_between_hearts = 4;

	//items images
	UI_Image*		item_frame				= nullptr;
	UI_Image*		items_frame_inactive	= nullptr;
	UI_Image*		items_frame_using		= nullptr;
	bool			item_active = false;

	UI_Image*		items_bow;
	UI_Image*		items_bomb;
	UI_Image*		items_potion_red;
	UI_Image*		items_potion_green;

	//Stamina images
	UI_Image*		stamina_container = nullptr; //Image not in gui
	UI_Image*		stamina_green = nullptr; //Image not in gui
	UI_Image*		stamina_yellow = nullptr; //Image not in gui
	UI_Image*		stamina_red = nullptr; //Image not in gui

	UI_Stamina*		stamina_bar = nullptr;

	//Pause Elements
	PAUSEMOVE		pause_transition = PAUSE_NO_MOVE;

	//main menu works as screen
	UI_Image*		main_menu = nullptr;
	UI_Image*		item_menu = nullptr;
	UI_Image*		resume = nullptr;
	UI_Image*		quit = nullptr;

	std::vector<UI_Image*> pause_selectables;

	

private:

	SDL_Rect		LoadRect(pugi::xml_node);

	//Pause methods
	bool		LoadPause(string file);
	bool		IntoPause();
	void		GonePause();
	void		PauseOut(float);

	//In game HUD methods
	bool		LoadHud(string file);

	//Life methods
	int			active_hearts = 0;
	void		LoadHearts();
	void		LookLife();
	void		LookNumHearts();

	//items method
	void		LookInventory();
	void		ActiveItem(OBJECT_TYPE);
	void		SetFrame();


};

#endif // !_HUD_H_
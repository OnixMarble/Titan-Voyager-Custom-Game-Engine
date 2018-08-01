#pragma once
#ifndef __GAME_H__
#define __GAME_H__

#include "Renderer.h"
#include "Camera.h"
#include "Model.h"
#include "Terrain.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "Player.h"
#include "Debugger.h"
#include "Enemy.h"
#include "ParticleEmitter.h"
#include "Font.h"
#include "Framebuffer.h"
#include "Atmosphere.h"
#include "Cloth.h"

class Game
{
public:
	Game();
	~Game();

	void Run();

private:
	void InitMeshes();
	void InitLights();
	void InitDebugger();
	void InitText();
	void InitMultiRenderTarget();
	void InitCloth();
	void InitPlayer();
	void ProcessInput(std::vector<SDL_Event>&);
	void GameLoop();
	void Update();
	void RenderScene();

private:
	enum { CAM_FORWARD, CAM_BACKWARD, CAM_LEFT, CAM_RIGHT, CAM_RISE, CAM_FALL, TOTAL_CAM_MOVES };
	bool m_bCamMovements[TOTAL_CAM_MOVES];
	
	enum { SATURN_RINGS = 1, SPACE_CUBE, SKYBOX, SATURN, FPS_CROSSHAIR, AMMO, HEALTH, MUZZLE_FLASH, 
		   SNIPER_SCOPE, POSTPROCESSING_QUAD };
	
	enum class GameState { MAIN_MENU = 100, PLAY, EXIT, TOTAL_STATES };
	GameState m_gameState;
	float m_deltaTime;

private:
	Model m_asteroid, m_flagPole, m_mountainRock;
	std::vector<Model> m_mountainRocks;
	Atmosphere m_atmosphere;
	Terrain m_terrain;
	DirectionalLight m_dirLight;
	PointLight m_pointLight;
	Debugger m_debugger;
	Camera m_camera, m_cameraHUD;
	Framebuffer m_framebuffer;
	Cloth m_flag;
	std::vector<Text> m_texts;
	std::vector<Enemy*> m_enemies;

private:
	bool m_sniperScope, m_zoom;
};

#endif // !__GAME_H__
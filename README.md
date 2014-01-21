GameSync
========

(In Progress)
---

Node.js 2D game Dev Kit
---

You just get to work, we handle the hassle


What is GameSync?
===

GameSync is a development kit for 2D games. Not just any games - multiplayer synchronous games with physics. You work with the browser interface and some javascript, and GameSync will export a gameserver configured for deployment.

Notes about the engine 1/21/2014
===

	*	After cloning this repository, the node module responsible for
		physics is located in the "engine" folder - this module contains native code
		and could present problems when compiling, although we try to avoid causing them.

	*	There is a script in "engine/build" named 'rebuild', on linux running 'bash rebuild'
		should compile the module

	*	The rest of the project - in the "GameSync" folder - needs the engine module to 
		function. Once the engine has been rebuilt, copy/paste the entire "engine" folder
		into the "GameSync/node_modules" folder. If the "node_modules" folder doesn't exist,
		then you have not yet run 'npm install' in the "GameSync" folder (do that after engine has been copied over). Go ahead and make the "node_modules" folder and paste the "engine" folder over. 

	*	the engine runs on the Box2D.cpp library - currently version 2.3.0


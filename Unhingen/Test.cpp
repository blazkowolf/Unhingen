#include "Common\Types.h"

#include <SDL2\SDL.h>
#include <string>

#include "Display\Display.h"
#include "Common\Mesh.h"
#include "Common\Vertex.h"
#include "Common\Shader.h"
#include "Utils\IO.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main ( int argc, char *argv[] ) {
	Display win( WINDOW_WIDTH, WINDOW_HEIGHT, "Test Window" );
	Shader shader( "./Res/Shaders/Test" );
	Vertex vertices[] = {
		Vertex( glm::vec3( -0.5f, -0.5f, 0.0f ) ),
		Vertex( glm::vec3( 0.0f, 0.5f, 0.0f ) ),
		Vertex( glm::vec3( 0.5f, -0.5f, 0.0f ) )
	};
	Mesh mesh( vertices, sizeof( vertices ) / sizeof( vertices[0] ) );
	//std::string fileContents = utils::LoadFile( "./Res/Hello.txt" );
	while ( win.IsRunning() ) {
		win.Clear( 0.0f, 0.15f, 0.3f, 1.0f );	// Clear the window with light-blue

		shader.Enable();
		mesh.Draw();

		win.Update();
		for ( SDL_Event e; SDL_PollEvent( &e ); ) {
			switch ( e.type ) {
				case SDL_QUIT: win.SetRunning( false );
				case SDL_KEYUP:
					switch ( e.key.keysym.sym ) {
						case SDLK_ESCAPE: win.SetRunning( false );
					}
			}
		}
	}
	return 0;
}
//#include <SDL.h>
//#include <stdio.h>
//#include <mach/machine.h>
//#include <SDL_image.h>
//#include <stdbool.h>
//
////Screen dimension constants
//const int SCREEN_WIDTH = 1940;
//const int SCREEN_HEIGHT = 1080;
//
////Starts up SDL and creates window
//boolean_t init();
//
////Loads media
//boolean_t loadMedia();
//
////Frees media and shuts down SDL
//void close();
//
//SDL_Texture * room_texture = NULL;
//
//SDL_Texture * background_texture = NULL;
//
//SDL_Texture * ant_texture = NULL;
//
//SDL_Renderer * renderer = NULL;
//
////The window we'll be rendering to
//SDL_Window* gWindow = NULL;
//
////The surface contained by the window
//SDL_Surface* gScreenSurface = NULL;
//
////The image we will load and show on the screen
//SDL_Surface* background = NULL;
//
//SDL_Surface* rooms = NULL;
//
//SDL_Surface* ant = NULL;
//
//
//boolean_t   init_sdl_images()
//{
//	 //Initialization flag
//	boolean_t success = 1;
//
//	 //Initialize SDL
//	if(!(IMG_Init( IMG_INIT_PNG ) & IMG_INIT_PNG))
//	{
////  printf( "Could not initialize SDL_image! SDL_Error: %s\n", IMG_GetError() );
//	printf("%s", (char *)SDL_GetError());
//	success = 0;
//	}
//}
//
//boolean_t init()
//{
//	 //Initialization flag
//	boolean_t success = 1;
//
//	 //Initialize SDL
//	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
//	{
//		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
//		success = 0;
//	}
//	else
//	{
//	  //Create window
//		gWindow = SDL_CreateWindow( "Lem-in", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
//		if( gWindow == NULL )
//		{
//			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
//			success = 0;
//	  	}
//	}
//	init_sdl_images();
//
//	return success;
//}
//
//void     init_textures(void)
//{
//	renderer = SDL_CreateRenderer(gWindow, -1, 0);
//
//	room_texture = SDL_CreateTextureFromSurface(renderer, rooms);
//
//	background_texture = SDL_CreateTextureFromSurface(renderer, background);
//
//	ant_texture = SDL_CreateTextureFromSurface(renderer, ant);
//}
//
//boolean_t   loadMedia()
//{
//	 //Loading success flag
//	boolean_t success = 1;
//
//	background = IMG_Load("/Users/mcanhand/Downloads/space.jpg");
//	rooms = IMG_Load("/Users/mcanhand/Downloads/room.png");
//	ant = IMG_Load("/Users/mcanhand/Downloads/ant.png");
//
//	 //Load splash image
//	if( rooms == NULL )
//	{
//	    printf( "Unable to load image %s! SDL Error: %s\n", "03_event_driven_programming/x.bmp", SDL_GetError() );
//	    success = 0;
//	}
//	if( background == NULL )
//	{
//		printf( "Unable to load image %s! SDL Error: %s\n", "03_event_driven_programming/x.bmp", SDL_GetError() );
//		success = 0;
//	}
//	init_textures();
//	return success;
//}
//
//void close()
//{
//	 //Deallocate surface
//	SDL_FreeSurface( background );
//	background = NULL;
//	SDL_FreeSurface( rooms );
//	rooms = NULL;
//
//	SDL_DestroyTexture(room_texture);
//	SDL_DestroyTexture(ant_texture);
//
//	SDL_DestroyTexture(background_texture);
//	SDL_DestroyRenderer(renderer);
//	 //Destroy window
//	SDL_DestroyWindow( gWindow );
//	gWindow = NULL;
//
//	 //Quit SDL subsystems
//	SDL_Quit();
//}

//int main( int argc, char* args[] )
//{
//	//Start up SDL and create window
//	if( !init() )
//	{
//		printf( "Failed to initialize!\n" );
//	}
//	else
//	{
//	 //Load media
//		if( !loadMedia() )
//		{
//			printf( "Failed to load media!\n" );
//		}
//		else
//		{
//	//Main loop flag
//			boolean_t quit = 0;
//
//	//Event handler
//			SDL_Event e;
//
//	//While application is running
//			while( !quit )
//			{
//	 //Handle events on queue
//	            while( SDL_PollEvent( &e ) != 0 )
//	            {
//	  //User requests quit
//	                if( e.type == SDL_QUIT )
//	                {
//						quit = 1;
//	                }
//	            }
//
//	 //Apply the image
//				SDL_Rect room_dstrect = {150, 105, 250, 200 };
//				SDL_Rect ant_dstrect = {150 + 80, 105 + 50, 70, 100 };
//				SDL_RenderCopy(renderer, background_texture, NULL, NULL);
//				SDL_RenderCopy(renderer, room_texture, NULL, &room_dstrect);
//				SDL_RenderCopy(renderer, ant_texture, NULL, &ant_dstrect);
//
//				SDL_Rect rect;
//				rect.x = 250;
//				rect.y = 150;
//				rect.w = 200;
//				rect.h = 200;
//
////				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//				SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
//
////				SDL_RenderDrawRect(renderer, &rect);
//				SDL_RenderDrawLine(renderer, 620, 800, 300, 240);
//				SDL_RenderDrawLine(renderer, 620 + 1, 800 + 1, 300 + 1, 240 + 1);
//				SDL_RenderDrawLine(renderer, 620 + 2, 800 + 2, 300 + 2, 240 + 2);
//
//				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//
////				SDL_RenderCopyEx(renderer, texTarget, NULL, NULL, 0, NULL, SDL_FLIP_VERTICAL);
//
//				SDL_RenderPresent(renderer);
//
//			}
//	    }
//	 }
//	 //Free resources and close SDL
//	 close();
//
//	 return 1;
//}



//include_directories(~/Library/Frameworks/SDL2.framework/Headers)
//include_directories(~/Library/Frameworks/SDL2_image.framework/Headers)
//include_directories(~/Library/Frameworks/SDL2_ttf.framework/Headers)
//
//
//
//target_link_libraries(visualize_new "-framework SDL2")
//target_link_libraries(visualize_new "-framework SDL2_image")
//target_link_libraries(visualize_new "-framework SDL2_ttf")
//set_target_properties(visualize_new PROPERTIES LINK_FLAGS "-F /Users/$ENV{USER}/Library/Frameworks")
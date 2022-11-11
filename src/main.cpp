#include <iostream>
#include <vector>
#include <string>

#include "SDLApp.hpp"
#include "ResourceManager.hpp"
#include "TexturedRectangle.hpp"
#include "GameEntity.hpp"

SDLApp *app = nullptr;
GameEntity *obj1 = nullptr;
GameEntity *obj2 = nullptr;

bool right = true;
bool down = true;
int move_step = 1;

void EventHandler()
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    if (event.type == SDL_QUIT)
    {
      app->SetIsRunning(false);
    }
  }
}

void UpdateHandler()
{
  SDL_Rect rect = obj1->GetTexturedRectangle()->GetDstRect();
  if (rect.x + rect.w >= app->GetWindowWidth())
  {
    right = false;
  }

  if (rect.x <= 0)
  {
    right = true;
  }

  if (rect.y + rect.h >= app->GetWindowHeight())
  {
    down = false;
  }

  if (rect.y <= 0)
  {
    down = true;
  }

  obj1->GetTexturedRectangle()->UpdatePosition(
      right ? rect.x + move_step : rect.x - move_step,
      down ? rect.y + move_step : rect.y - move_step);

  // mouse object
  SDLAppPosition posi = app->GetMousePosition();
  obj2->GetTexturedRectangle()->UpdatePosition(posi.x, posi.y);

  obj1->Update();
  obj2->Update();
}

void RendererHandler(SDL_Renderer *renderer)
{
  SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);

  obj1->Render();

  obj2->Render();

  // collision check
  if (obj1->GetCollider2D().IsColliding(obj2->GetCollider2D()))
  {
    std::cout << "Two objects has collision.\n";
  }
  
  // if (obj1->GetTexturedRectangle()->HasCollision(obj2->GetTexturedRectangle()))
  // {
  //   std::cout << "Two objects has collision.\n";
  // }

  SDL_RenderPresent(renderer);
}

int main(int argc, char **argv)
{

  app = new SDLApp(
      "SDL App with C++",
      0,
      0,
      640,
      480);

  obj1 = new GameEntity(app->GetRenderer(), "../assets/images/bask.bmp");
  obj2 = new GameEntity(app->GetRenderer(), "../assets/images/bask.bmp");
  obj1->GetTexturedRectangle()->UpdateDimensition(100, 100);
  obj2->GetTexturedRectangle()->UpdateDimensition(100, 100);

  app->SetEventHandler(EventHandler);
  app->SetUpdateHandler(UpdateHandler);
  app->SetRendererHandler(RendererHandler);
  app->SetFrameRate(100);

  app->Runloop();

  delete obj1;
  delete obj2;

  return 0;
}
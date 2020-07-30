#pragma once

/* an example header */

#include <string>
#include <vector>

namespace DigiRoyale
{

void example();

struct Contestant
{
  std::string image_url;
  std::string name;
  int killCount = 0;
  bool isAlive = true;
};

enum Action
{
  NOTHING_HAPPENS,
  KILL,
  KILLED,
};

struct Event
{
  int contestantCount;
  std::vector<Contestant> contestants;
  std::vector<Action> whatHappened;
  std::vector<std::string> text;
};

struct SimResult
{
  std::vector<Event> events;
  std::vector<Contestant> contestants;
  Contestant winner;
};

SimResult simulate(std::vector<Contestant> contestants);

}

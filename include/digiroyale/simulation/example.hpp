#pragma once

/* an example header */

#include <string>
#include <vector>

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
  std::vector <std::string> text;
};

std::vector<Event> simulate(std::vector<Contestant> contestants);

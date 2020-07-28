#pragma once

/* an example header */

#include <string>
#include <vector>

void example();

struct Contestant
{
  std::string image_url;
  std::string name;
  int killCount;
  bool isAlive;
};

enum Action
{
  NOTHING_HAPPENS,
  KILL,
  KILLED,
};

struct Event
{
  std::vector<Contestant> contestants;
  std::vector<Action> whatHappened;
  std::vector <std::string> text;
};

std::vector<Event> simulate(std::vector<Contestant> contestants);

#include <digiroyale/simulation/example.hpp>

void example() {}

std::vector<Event> events =
{
  {1, {}, {NOTHING_HAPPENS}, {"0", " sat around."}},
  {2, {}, {NOTHING_HAPPENS, NOTHING_HAPPENS}, {"0", " and ", "1", " snuggled."}},
  {2, {}, {NOTHING_HAPPENS, KILLED}, {"0", " and ", "1", " walked on a bridge but ", "1", " slipped and died."} },
  {1, {}, {KILLED}, {"0", " committed suicide."}},
  {2, {}, {KILL, KILLED}, {"0", " brutally murders ", "1", " with an axe."}},
};

static int numAlive(std::vector<Contestant> contestants)
{
  int sum = 0;
  for (Contestant& c : contestants)
  {
    if (c.isAlive)
    {
      ++sum;
    }
  }
  return sum;
}

std::vector<Event> simulate(std::vector<Contestant> contestants)
{
  std::vector<Event> return_events;
  while (numAlive(contestants) > 1)
  {
    Event e = events[rand() % events.size()];
    std::vector<Contestant> involved;
    for (int i = 0; i < e.contestantCount; ++i)
    {
      int idx = rand() % contestants.size();
      if (contestants[idx].isAlive)
      {
        switch (e.whatHappened[i])
        {
        case KILL:
          contestants[idx].killCount += 1;
          break;
        case KILLED:
          contestants[idx].isAlive = false;
          break;
        case NOTHING_HAPPENS:
        default:
          break;
        }
        involved.push_back(contestants[idx]);
      }
      else
      {
        --i;
        continue;
      }
    }

    e.contestants = involved;

    for (std::string& s : e.text)
    {
      if (isdigit(s[0]))
      {
        s = e.contestants[s[0] - '0'].name;
      }
    }
    return_events.push_back(e);
  }
  return return_events;
}
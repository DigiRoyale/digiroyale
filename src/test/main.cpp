#include <digiroyale/simulation/example.hpp>

#include <iostream>

std::vector<std::string> names =
{
  "Robert",
  "Joseph",
  "Jonathan",
  "Gyro",
  "Funny",
  "Dio",
  "Polpo",
  "Kars",
  "Rudol",
  "Melone",
  "Josuke",
  "Diavolo",
  "Abdul"
};

int main()
{
  srand(7);
  std::vector<Contestant> test_contestants;
  for (int i = 0; i < 10; ++i)
  {
    test_contestants.emplace_back(Contestant{
      "https://cdn.discordapp.com/avatars/170972525361102851/72fd532e6052d7093dd1be9cb78a9c21.png",
      names[rand() % names.size()] + "#" + std::to_string(rand()),
      0, true
    });
  }

  auto events = simulate(test_contestants);
  for (Event& event : events)
  {
    for (std::string& chunk : event.text)
    {
      std::cout << chunk;
    }
    std::cout << std::endl;
  }
  std::cout << "done\n";
}
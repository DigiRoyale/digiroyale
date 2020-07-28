#include <digiroyale/simulation/example.hpp>

#include <iostream>

std::vector<std::string> names =
{
  "Robert Speedwagon",
  "Joseph Joestar",
  "Jonathan Joestar",
  "Gyro Zeppeli",
  "Funny Valentine",
  "Dio Brando",
  "Polpo",
  "Kars",
  "Rudol von Stroheim",
  "Melone",
  "Josuke Higashikata",
  "Diavolo",
  "Muhammad Abdul",
  "Leon Abbachio",
  "Caesar Zeppeli",
  "Yasuho Hirose",
  "Foo Fighters",
  "Yoshikage Kira",
  "Hot Pants"
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

  auto result = simulate(test_contestants);
  for (Event& event : result.events)
  {
    for (std::string& chunk : event.text)
    {
      std::cout << chunk;
    }
    std::cout << std::endl;
  }
  std::cout << "The winner is " << result.winner.name << " with " << result.winner.killCount << " kills.\n";
}
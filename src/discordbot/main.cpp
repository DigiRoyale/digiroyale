/* Standard Headers */
#include <iostream>

/* Library Headers */
#include <sleepy_discord/sleepy_discord.h>

/* DigiRoyale Sim Headers */
#include <digiroyale/simulation/example.hpp>

/* DigiRoyale Bot Headers */
#include <digiroyale/discordbot/example.hpp>

class MyClientClass : public SleepyDiscord::DiscordClient
{
public:
	using SleepyDiscord::DiscordClient::DiscordClient;
	void onMessage(SleepyDiscord::Message message) override
	{
		if (message.startsWith("whcg hello"))
			sendMessage(message.channelID, "Hello " + message.author.username);
	}
};

int main()
{
	MyClientClass client("token", SleepyDiscord::USER_CONTROLED_THREADS);
	example();
	std::cout << "wow it works\n";
	client.run();
}

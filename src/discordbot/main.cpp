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
		if (message.startsWith("Pog"))
		{
			//sends a message to the same channel that Pog was received in and then turns it into a link to their avatar using their ID and avatar hash and then add a .png link
			
			SleepyDiscord::Server guild = getServer(message.serverID);
			auto members = listMembers(message.serverID,12).list();
			
			std::vector<Contestant> test_contestants;

			for (SleepyDiscord::ServerMember& member : members) {
				std::string pfp = "https:\//cdn.discordapp.com/avatars/" + member.user.ID + "/" + member.user.avatar + ".png";
				test_contestants.emplace_back(Contestant{ pfp, member.user.username,0,true });
			}
			sendTyping(message.channelID);
			auto events = simulate(test_contestants);
			std::string eventsList;
			for (Event& event : events)
			{
				for (std::string& chunk : event.text)
				{
					eventsList += chunk;
				}
				eventsList += "\n";
			}
			sendMessage(message.channelID, eventsList);
		}
	}
};

int main()
{
	MyClientClass client("token", SleepyDiscord::USER_CONTROLED_THREADS);
	example();
	std::cout << "wow it works\n";
	client.run();
}

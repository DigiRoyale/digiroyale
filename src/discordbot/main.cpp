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

			SleepyDiscord::Server guild = getServer(message.serverID);
			//grabs a list of members from the server up to 120 users
			auto members = listMembers(message.serverID, 120).list();
			
			std::vector<Contestant> test_contestants;

			for (SleepyDiscord::ServerMember& member : members) {
				//grab the pfp link using member data
				std::string pfp = "https:\//cdn.discordapp.com/avatars/" + member.user.ID + "/" + member.user.avatar + ".png";
				//stick a contestant into the the vector
				test_contestants.emplace_back(Contestant{ pfp, member.user.username,0,true });
			}
			//make the bot type so it seems more realistic
			sendTyping(message.channelID);

			//simulate all the events
			auto result = simulate(test_contestants);
			std::string eventsList; //build a string full of all the events *to avoid ratelimit*
			for (Event& event : result.events)
			{
				for (std::string& chunk : event.text)
				{
					eventsList += chunk;
				}
				eventsList += "\n";
			}
			sendMessage(message.channelID, eventsList); //send the message off
		}
	}
};

int main()
{
	MyClientClass client("MzY2MjM1MDU1MjUwNjA0MDMz.XroQWA.ISJA-HLLbLHGFMO5kTJRVsCtbx8", SleepyDiscord::USER_CONTROLED_THREADS);
	example();
	std::cout << "wow it works\n";
	client.run();
}

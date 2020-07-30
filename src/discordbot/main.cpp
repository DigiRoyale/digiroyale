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
			//grabs a list of members from the server up to 120 users
			auto members = listMembers(message.serverID, 120).list();
			
			std::vector<DigiRoyale::Contestant> test_contestants;

			for (SleepyDiscord::ServerMember& member : members) {
				//grab the pfp link using member data
				std::string pfp = "https:\//cdn.discordapp.com/avatars/" + member.user.ID + "/" + member.user.avatar + ".png";
				//stick a contestant into the the vector
				test_contestants.emplace_back(DigiRoyale::Contestant{ pfp, member.user.username,0,true });
			}
			//make the bot type so it seems more realistic
			sendTyping(message.channelID);

			//simulate all the events
			auto result = simulate(test_contestants);
			std::string eventsList; //build a string full of all the events *to avoid ratelimit*
			for (DigiRoyale::Event& event : result.events)
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
	std::string token;

	{
		std::ifstream token_infile{ "data/discordbot/token.json" };
	  std::stringstream buffer;
		// read the entire json file into the buffer
		buffer << token_infile.rdbuf();
		// move the string out of the buffer
		token = buffer.str();
	}

	// parse the json file
	rapidjson::Document doc;
	if (doc.Parse(token.c_str()).HasParseError())
	{
		std::cerr << "Failed to parse token.json in the data/discordbot folder.\n";
		return 1;
	}

	// the only contents of the json should be "token": "token_goes_here"
	token = doc["token"].GetString();
	// NO_TOKEN is the placeholder. maybe replace it with something that invites filling in the token?
	if (token == "NO_TOKEN")
	{
		std::cerr << "No bot token found. Fill in the token.json file in the data/discordbot folder.\n";
		return 1;
	}

	MyClientClass client(token, SleepyDiscord::USER_CONTROLED_THREADS);
	std::cout << "DigiRoyale v0.0.0\n";
	client.run();

	return 0;
}

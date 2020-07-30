if (NOT EXISTS discordbot/token.json)
  message("Token file not found, generating now.")
  file(COPY templates/token.json DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/discordbot)
endif()
